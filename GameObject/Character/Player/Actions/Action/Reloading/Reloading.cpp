#include "Reloading.h"

using namespace Math;
using namespace ActionConfig;
using namespace ActionConfig::Mask;

Reloading::Reloading() {
	stateName_ = "Reloading";
	Init();
}

void Reloading::Init() {
	currentFrame_ = reloadingTime;
}

void Reloading::Update() {
	if (currentFrame_ <= 0.0f) {
		// 遷移可能な状態
		enableChangeState_ = Weapon::MainAction::reloading | Weapon::MainAction::shot;
	}

	currentFrame_--;
}
