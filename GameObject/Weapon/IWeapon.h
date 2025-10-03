#pragma once

/// <summary>
/// 部Ēクラスのインターフェイス
/// </summary>
class IWeapon {
public:
	// コンストラクタ
	IWeapon() = default;
	// デストラクタ
	virtual ~IWeapon() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;
};

