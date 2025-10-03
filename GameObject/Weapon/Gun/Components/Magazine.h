#pragma once

/// <summary>
/// 残弾を管理する弾倉クラス
/// </summary>
class Magazine {
public:
	// コンストラクタ
	Magazine();
	// デストラクタ
	~Magazine() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(const float& bulletCount);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();

public:// アクセサ
	/// <summary>
	/// 弾があるかを取得
	/// </summary>
	/// <returns></returns>
	bool GetEmpty() { return bulletCount_ <= 0.0f; }

	/// <summary>
	/// 残弾を減らす
	/// </summary>
	/// <param name="value">減少量</param>
	void BulletDecrement(const float& value) { bulletCount_ -= value; }
private:
	// 弾数
	float bulletCount_;
};

