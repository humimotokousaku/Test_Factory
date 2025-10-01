#pragma once
#include "Action/IAction.h"
#include "../../../../Componets/Math.h"
#include <memory>

class IActions {
public:
	// コンストラクタ
	IActions() = default;
	// デストラクタ
	virtual ~IActions() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 調整項目
	/// </summary>
	virtual void DebugGui(const Math::Vector2& pos) = 0;

protected:
	/// <summary>
	/// 状態の変更
	/// </summary>
	/// <param name="currentAction"></param>
	/// <param name="nextAction"></param>
	void ChangeState(std::unique_ptr<IAction>& currentAction, std::unique_ptr<IAction> nextAction) {
		// 権利を譲渡
		currentAction = std::move(nextAction);
	}
	/// <summary>
	/// 変更可能な状態かを取得
	/// </summary>
	/// <returns></returns>
	bool CheckEnableChangeState(const unsigned int& targetStateMask, const unsigned int& enableChangeStateMask) {
		if (targetStateMask & enableChangeStateMask) return true;
		return false;
	}
	/// <summary>
	/// 並列可能な状態同士であるかを取得
	/// </summary>
	/// <param name="stateMask"></param>
	/// <returns></returns>
	bool CheckInabilityParallelState(const unsigned int& targetStateMask, const unsigned int& inabilityParallelStateMask) {
		// 並列禁止マスクがある場合はfalse
		if (targetStateMask & inabilityParallelStateMask) return false;
		return true;
	}

public:// アクセサ
#pragma region Getter
	/// <summary>
	/// 変更可能な状態マスクを取得
	/// </summary>
	/// <returns></returns>
	unsigned int GetEnableChangeState() { return enableChangeState_; }
	/// <summary>
	/// 並列不能な状態マスクを取得
	/// </summary>
	/// <returns></returns>
	unsigned int GetInabilityParallelState() { return inabilityParallelState_; }
#pragma endregion

#pragma region Setter

#pragma endregion

protected:
	// 変更可能な状態マスク
	unsigned int enableChangeState_ = 0;
	// 並列不能な状態マスク
	unsigned int inabilityParallelState_ = 0;
};