#pragma once
#include "../ICharacter.h"
#include "Actions/MoveController.h"
#include "Actions/WeaponController.h"
#include "../../../Componets/Math.h"

/// <summary>
/// 自機クラス
/// </summary>
class Player : public ICharacter {
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player() override = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override;
	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	// 移動行動系の処理
	std::unique_ptr<MoveController> moveController_;
	// 武器の処理
	std::unique_ptr<WeaponController> weaponController_;
};

