#include "Jump.h"

using namespace Math;
using namespace ActionConfig;
using namespace ActionConfig::Mask;

Jump::Jump() {
	stateName_ = "Jump";
	// 遷移可能な状態
	enableChangeState_ = Movement::SubAction::evasion | Movement::SubAction::sliding;
}

void Jump::Init() {

}

void Jump::Update() {

}
