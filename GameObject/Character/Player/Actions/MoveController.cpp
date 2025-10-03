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
	actions_[ActionType::kMain] = std::make_unique<Move>();
	actions_[ActionType::kSub] = std::make_unique<NoneAction>();
	enableChangeState_ = Movement::SubAction::jump | Movement::SubAction::sliding | Movement::SubAction::evasion;
}

MoveController::~MoveController() {

}

void MoveController::Init() {
	for (auto it = actions_.begin(); it != actions_.end(); ++it) {
		if(it->second) it->second->Init();
	}
}

void MoveController::Update() {
	// 入力処理
	InputHandle();

	for (auto it = actions_.begin(); it != actions_.end(); ++it) {
		if (it->second) it->second->Update();
	}
}

void MoveController::DebugGui(const Math::Vector2& pos) {
	Novice::ScreenPrintf((int)pos.x, (int)pos.y, "Move State:");

	if (actions_[ActionType::kMain]) {
		// メイン
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 20, actions_[ActionType::kMain]->GetStateName().c_str());
	}
	if (actions_[ActionType::kSub]) {
		// サブ
		Novice::ScreenPrintf((int)pos.x, (int)pos.y + 40, actions_[ActionType::kSub]->GetStateName().c_str());
	}
}

void MoveController::InputHandle() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	// ジャンプ
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		// 状態の変更ができるかを判別
		if (CheckEnableChangeState(Movement::SubAction::jump, actions_[ActionType::kSub]->GetEnableChangeState())) {
			// 他の状態と並列しても問題ないかを判別
			if (CheckInabilityParallelState(Movement::SubAction::jump, actions_[ActionType::kMain]->GetInabilityParallelState())) {
				ChangeState(actions_[ActionType::kSub], std::make_unique<Jump>());
			}
		}
	}
	// スライディング
	if (keys_[DIK_C] && !preKeys_[DIK_C]) {
		if (CheckEnableChangeState(Movement::SubAction::sliding, actions_[ActionType::kSub]->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Movement::SubAction::sliding, actions_[ActionType::kMain]->GetInabilityParallelState())) {
				ChangeState(actions_[ActionType::kSub], std::make_unique<Sliding>());
			}
		}
	}
	// 回避
	if (keys_[DIK_LSHIFT] && !preKeys_[DIK_LSHIFT]) {
		if (CheckEnableChangeState(Movement::SubAction::evasion, actions_[ActionType::kSub]->GetEnableChangeState())) {
			if (CheckInabilityParallelState(Movement::SubAction::evasion, actions_[ActionType::kMain]->GetInabilityParallelState())) {
				ChangeState(actions_[ActionType::kSub], std::make_unique<Evasion>());
			}
		}
	}
}