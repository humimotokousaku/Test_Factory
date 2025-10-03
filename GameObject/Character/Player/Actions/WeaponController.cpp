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
	actions_[ActionType::kMain] = std::make_unique<NoneAction>();
	actions_[ActionType::kSub] = std::make_unique<NoneAction>();
	enableChangeState_ = Weapon::SubAction::ads | Weapon::MainAction::reloading | Weapon::MainAction::shot;
}

void WeaponController::Init() {
	for (auto it = actions_.begin(); it != actions_.end(); it++) {
		if (it->second) it->second->Init();
	}
}

void WeaponController::Update() {
	// 入力処理
	InputHandle();

	// 変更可能な状態を取得
	enableChangeState_ = 0;
	if (actions_[ActionType::kMain]) enableChangeState_ |= actions_[ActionType::kMain]->GetEnableChangeState();
	if (actions_[ActionType::kSub])  enableChangeState_ |= actions_[ActionType::kSub]->GetEnableChangeState();

	for (auto it = actions_.begin(); it != actions_.end(); it++) {
		if (it->second) it->second->Update();
	}
}

void WeaponController::DebugGui(const Math::Vector2& pos) {
	Novice::ScreenPrintf((int)pos.x, (int)pos.y, "Weapon State:");
	if (actions_[ActionType::kMain]) {
		// メイン
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 20, actions_[ActionType::kMain]->GetStateName().c_str());
	}
	if (actions_[ActionType::kSub]) {
		// サブ
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 40, actions_[ActionType::kSub]->GetStateName().c_str());
	}
}

void WeaponController::InputHandle() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	// 射撃
	if (keys_[DIK_RETURN]) {
		// 状態の変更ができるかを判別
		if (CheckEnableChangeState(Weapon::MainAction::shot, actions_[ActionType::kMain]->GetEnableChangeState())) {
			// 他の状態と並列しても問題ないかを判別
			if (CheckInabilityParallelState(Weapon::MainAction::shot, actions_[ActionType::kSub]->GetInabilityParallelState())) {
				ChangeState(actions_[ActionType::kMain], std::make_unique<Shot>());
			}
		}
	}
	// リロード
	if (keys_[DIK_R] && !preKeys_[DIK_R]) {
		if (CheckEnableChangeState(Weapon::MainAction::reloading, actions_[ActionType::kMain]->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Weapon::MainAction::reloading, actions_[ActionType::kSub]->GetInabilityParallelState())) {
				ChangeState(actions_[ActionType::kMain], std::make_unique<Reloading>());
			}
		}
	}
	// 狙う
	if (keys_[DIK_LCONTROL]) {
		// 狙う
		if (CheckEnableChangeState(Weapon::SubAction::ads, actions_[ActionType::kSub]->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Weapon::SubAction::ads, actions_[ActionType::kMain]->GetInabilityParallelState())) {
				ChangeState(actions_[ActionType::kSub], std::make_unique<ADS>());
			}
		}
	}
	// 構えている状態なら構え解除
	else if (actions_[ActionType::kSub]->GetStateName() == "ADS") {
		ChangeState(actions_[ActionType::kSub], std::make_unique<NoneAction>());
	}
}