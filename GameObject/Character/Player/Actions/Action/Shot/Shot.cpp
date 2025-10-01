#include "Shot.h"

using namespace Math;
using namespace ActionConfig;
using namespace ActionConfig::Mask;

Shot::Shot() {
	stateName_ = "Shot";
	// 遷移可能な状態
	enableChangeState_ = Weapon::SubAction::ads | Weapon::MainAction::reloading | Weapon::MainAction::shot;
}

void Shot::Init() {

}

void Shot::Update() {

}