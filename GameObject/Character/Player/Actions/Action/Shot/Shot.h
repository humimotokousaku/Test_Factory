#pragma once
#include "../IAction.h"

class Shot : public IAction {
public:
	// コンストラクタ
	Shot();
	// デストラクタ
	~Shot() override = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override;
	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

private:
};