#include "NoneAction.h"

using namespace Math;
using namespace ActionConfig;

NoneAction::NoneAction() {
	stateName_ = "None";
	// 遷移可能な状態
	enableChangeState_ = Mask::all;
}

void NoneAction::Init() {

}

void NoneAction::Update() {

}