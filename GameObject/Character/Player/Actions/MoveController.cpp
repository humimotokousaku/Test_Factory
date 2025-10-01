#include "MoveController.h"
#include "Action/Move/Move.h"
#include "Action/Jump/Jump.h"
#include "Action/Sliding/Sliding.h"
#include "Action/Evasion/Evasion.h"
#include "Action/None/NoneAction.h"
#include <Novice.h>

using namespace ActionConfig;
using namespace ActionConfig::Mask;

MoveController::MoveController() {
	moveAction_ = std::make_unique<Move>();
	subAction_ = std::make_unique<NoneAction>();
	enableChangeState_ = Movement::SubAction::jump | Movement::SubAction::sliding | Movement::SubAction::evasion;
}

MoveController::~MoveController() {

}

void MoveController::Init() {
	if (moveAction_) moveAction_->Init();
	if (subAction_) subAction_->Init();
}

void MoveController::Update() {
	// 入力処理
	InputHandle();

	// 変更可能な状態を取得
	if (subAction_) enableChangeState_ = subAction_->GetEnableChangeState();

	if (moveAction_) moveAction_->Update();
	if (subAction_) subAction_->Update();
}

void MoveController::DebugGui(const Math::Vector2& pos) {
	Novice::ScreenPrintf((int)pos.x, (int)pos.y, "Move State:");
	if (moveAction_) {
		// メイン
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 20, moveAction_->GetStateName().c_str());
	}
	if (subAction_) {
		// サブ
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 40, subAction_->GetStateName().c_str());
	}
}

void MoveController::InputHandle() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	// ジャンプ
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		// 状態の変更ができるかを判別
		if (CheckEnableChangeState(Movement::SubAction::jump, subAction_->GetEnableChangeState())) {
			// 他の状態と並列しても問題ないかを判別
			if (CheckInabilityParallelState(Movement::SubAction::jump, moveAction_->GetInabilityParallelState())) {
				ChangeState(subAction_, std::make_unique<Jump>());
			}
		}
	}
	// スライディング
	if (keys_[DIK_C] && !preKeys_[DIK_C]) {
		if (CheckEnableChangeState(Movement::SubAction::sliding, subAction_->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Movement::SubAction::sliding, moveAction_->GetInabilityParallelState())) {
				ChangeState(subAction_, std::make_unique<Sliding>());
			}
		}
	}
	// 回避
	if (keys_[DIK_LSHIFT] && !preKeys_[DIK_LSHIFT]) {
		if (CheckEnableChangeState(Movement::SubAction::evasion, subAction_->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Movement::SubAction::evasion, moveAction_->GetInabilityParallelState())) {
				ChangeState(subAction_, std::make_unique<Evasion>());
			}
		}
	}
}