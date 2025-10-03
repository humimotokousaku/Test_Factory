#pragma once
#include "../IWeapon.h"
#include "Components/Magazine.h"
#include <memory>

/// <summary>
/// 銃の基底クラス
/// </summary>
class Gun : public IWeapon {
public:
	// コンストラクタ
	Gun() = default;
	// デストラクタ
	~Gun() override = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() override = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() override = 0;
	/// <summary>
	/// 調整項目
	/// </summary>
	virtual void DebugGui() = 0;

	/// <summary>
	/// 射撃
	/// </summary>
	virtual void Shoot() = 0;
	/// <summary>
	/// リロード
	/// </summary>
	virtual void Reload() = 0;
	/// <summary>
	/// 狙う(ADS)
	/// </summary>
	virtual void Aim() = 0;

protected:// 調整項目
	// 射撃間隔[秒]
	float shotIntervalTime_;

protected:
	// 弾倉
	std::unique_ptr<Magazine> magazine_;
};