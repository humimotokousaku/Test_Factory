#pragma once
#include "../IAction.h"

class Move : public IAction {
public:
	// コンストラクタ
	Move();
	// デストラクタ
	~Move() override = default;

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

