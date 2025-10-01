#include "Sliding.h"

using namespace ActionConfig;
using namespace ActionConfig::Mask;

Sliding::Sliding() {
	stateName_ = "Sliding";
	// 遷移可能な状態
	enableChangeState_ = Movement::SubAction::jump | Movement::SubAction::evasion;
}

void Sliding::Init() {

}

void Sliding::Update() {

}
