#pragma once
#include "IActions.h"
#include "Action/IAction.h"
#include <memory>
#include <vector>

/// <summary>
/// メイン、サブ武器の使い分け
/// </summary>
class WeaponController : public IActions {
public:
	// コンストラクタ
	WeaponController();
	// デストラクタ
	~WeaponController() override = default;

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

private:
	// 射撃とリロード
	std::unique_ptr<IAction> mainAction_;
	// メイン以外の並列して行える行動
	std::unique_ptr<IAction> subAction_;

	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
};

