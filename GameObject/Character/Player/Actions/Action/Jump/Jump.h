#pragma once
#include "../IAction.h"

class Jump : public IAction {
public:
	// コンストラクタ
	Jump();
	// デストラクタ
	~Jump() override = default;

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