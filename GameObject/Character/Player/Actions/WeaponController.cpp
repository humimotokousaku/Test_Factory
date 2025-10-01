#include "WeaponController.h"
#include "Action/Shot/Shot.h"
#include "Action/Reloading/Reloading.h"
#include "Action/ADS/ADS.h"
#include "Action/None/NoneAction.h"
#include <Novice.h>
#include "MoveController.h"

using namespace ActionConfig;
using namespace ActionConfig::Mask;

WeaponController::WeaponController() {
	mainAction_ = std::make_unique<NoneAction>();
	subAction_ = std::make_unique<NoneAction>();
	enableChangeState_ = Weapon::SubAction::ads | Weapon::MainAction::reloading | Weapon::MainAction::shot;
}

void WeaponController::Init() {
	if (mainAction_) mainAction_->Init();
	if (subAction_) subAction_->Init();
}

void WeaponController::Update() {
	// 入力処理
	InputHandle();

	// 変更可能な状態を取得
	enableChangeState_ = 0;
	if (mainAction_) enableChangeState_ |= mainAction_->GetEnableChangeState();
	if (subAction_)  enableChangeState_ |= subAction_->GetEnableChangeState();

	if (mainAction_) mainAction_->Update();
	if (subAction_) subAction_->Update();
}

void WeaponController::DebugGui(const Math::Vector2& pos) {
	Novice::ScreenPrintf((int)pos.x, (int)pos.y, "Weapon State:");
	if (mainAction_) {
		// メイン
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 20, mainAction_->GetStateName().c_str());
	}
	if (subAction_) {
		// サブ
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 40, subAction_->GetStateName().c_str());
	}
}

void WeaponController::InputHandle() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	// 射撃
	if (keys_[DIK_RETURN]) {
		// 状態の変更ができるかを判別
		if (CheckEnableChangeState(Weapon::MainAction::shot, mainAction_->GetEnableChangeState())) {
			// 他の状態と並列しても問題ないかを判別
			if (CheckInabilityParallelState(Weapon::MainAction::shot, subAction_->GetInabilityParallelState())) {
				ChangeState(mainAction_, std::make_unique<Shot>());
			}
		}
	}
	// リロード
	if (keys_[DIK_R] && !preKeys_[DIK_R]) {
		if (CheckEnableChangeState(Weapon::MainAction::reloading, mainAction_->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Weapon::MainAction::reloading, subAction_->GetInabilityParallelState())) {
				ChangeState(mainAction_, std::make_unique<Reloading>());
			}
		}
	}
	// 狙う
	if (keys_[DIK_LCONTROL]) {
		// 狙う
		if (CheckEnableChangeState(Weapon::SubAction::ads, subAction_->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Weapon::SubAction::ads, mainAction_->GetInabilityParallelState())) {
				ChangeState(subAction_, std::make_unique<ADS>());
			}
		}
	}
	// 構えている状態なら構え解除
	else if (subAction_->GetStateName() == "ADS") {
		ChangeState(subAction_, std::make_unique<NoneAction>());
	}
}