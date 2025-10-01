#include "ADS.h"

using namespace Math;
using namespace ActionConfig;
using namespace ActionConfig::Mask;

ADS::ADS() {
	stateName_ = "ADS";
	// 遷移可能な状態
	enableChangeState_ = Weapon::MainAction::reloading | Weapon::MainAction::shot;
}

void ADS::Init() {

}

void ADS::Update() {

}
