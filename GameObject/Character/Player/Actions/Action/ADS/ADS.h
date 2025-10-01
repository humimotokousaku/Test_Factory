#pragma once
#include "../IAction.h"

class ADS : public IAction {
public:
	// コンストラクタ
	ADS();
	// デストラクタ
	~ADS() override = default;

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