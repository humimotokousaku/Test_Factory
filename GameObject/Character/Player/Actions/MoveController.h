#pragma once
#include "IActions.h"
#include "Action/IAction.h"
#include <memory>
#include <vector>

/// <summary>
/// 自機の移動に関する機能クラス
/// </summary>
class MoveController : public IActions {
public:
	// コンストラクタ
	MoveController();
	// デストラクタ
	~MoveController() override;

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override;
	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

	/// <summary>
	/// 調整項目
	/// </summary>
	void DebugGui(const Math::Vector2& pos) override;

private:
	/// <summary>
	/// 入力処理
	/// </summary>
	void InputHandle();

public:// アクセサ
#pragma region Getter
	
#pragma endregion

#pragma region Setter

#pragma endregion

private:
	// 移動
	std::unique_ptr<IAction> moveAction_;
	// 移動以外の並列して行える行動
	std::unique_ptr<IAction> subAction_;

	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
};

