#pragma once
#include <Novice.h>
#include "../../Componets/Math.h"

/// <summary>
/// 出現する敵や自機の基底クラス
/// </summary>
class ICharacter {
public:
	// コンストラクタ
	ICharacter() = default;
	// デストラクタ
	virtual ~ICharacter() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;

public:// アクセサ
#pragma region Getter
	/// <summary>
	/// 座標を取得
	/// </summary>
	/// <returns></returns>
	const Math::Vector2& GetPos() { return pos_; }
#pragma endregion

#pragma region Setter

#pragma endregion

protected:
	// 座標
	Math::Vector2 pos_;
	// 大きさ
	Math::Vector2 size_ = { 16.0f, 16.0f };
};