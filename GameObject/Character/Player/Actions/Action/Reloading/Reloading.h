#pragma once
#include "../IAction.h"

class Reloading : public IAction {
public:
	// コンストラクタ
	Reloading();
	// デストラクタ
	~Reloading() override = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override;
	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

private:
	// リロードにかかる時間
	const float reloadingTime = 60.0f;

private:
	float currentFrame_;
};