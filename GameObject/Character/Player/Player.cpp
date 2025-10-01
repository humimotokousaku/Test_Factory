#include "Player.h"

using namespace Math;

Player::Player() {
	moveController_ = std::make_unique<MoveController>();
	weaponController_ = std::make_unique<WeaponController>();
}

void Player::Init() {
	pos_ = { 740.0f, 360.0f };
	size_ = { 16.0f, 16.0f };
	moveController_->Init();
	weaponController_->Init();
}

void Player::Update() {
	moveController_->Update();
	weaponController_->Update();
}

void Player::Draw() {
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_.x, (int)size_.y, 0.0f, BLUE, kFillModeSolid);

	moveController_->DebugGui(Vector2{ 0.0f,10.0f });
	weaponController_->DebugGui(Vector2{ 0.0f,90.0f });
}
