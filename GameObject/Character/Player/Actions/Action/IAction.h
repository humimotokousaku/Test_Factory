#pragma once
#include "../../../../../Componets/Math.h"
#include "../ActionConfig.h"
#include <string>

/// <summary>
/// 自機行動の基底クラス
/// </summary>
class IAction {
public:
	// コンストラクタ
	IAction() = default;
	// デストラクタ
	virtual ~IAction() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;

public:// アクセサ
#pragma region Getter
	/// <summary>
	/// 変更可能な状態マスクを取得
	/// </summary>
	/// <returns></returns>
	unsigned int GetEnableChangeState() { return enableChangeState_; }
	/// <summary>
	/// 現在変更可能な状態マスクを取得
	/// </summary>
	/// <returns></returns>
	//const unsigned int& GetCurrentEnableChangeState() { return enableChangeState_; }
	/// <summary>
	/// 並列可能な状態マスクを取得
	/// </summary>
	/// <returns></returns>
	unsigned int GetInabilityParallelState() { return inabilityParallelState_; }
	/// <summary>
	/// 状態の名前を取得
	/// </summary>
	/// <returns></returns>
	const std::string& GetStateName() { return stateName_; }
#pragma endregion

#pragma region Setter

#pragma endregion

protected:
	// 変更可能な状態マスク
	unsigned int enableChangeState_ = 0;
	// 現在変更可能な状態マスク
	//unsigned int currentEnableChangeState_;
	// 並列可能な状態マスク
	unsigned int inabilityParallelState_ = 0;

	std::string stateName_;
};