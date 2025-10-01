#pragma once
#include "../IAction.h"

class Sliding : public IAction {
public:
	// コンストラクタ
	Sliding();
	// デストラクタ
	~Sliding() override = default;

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