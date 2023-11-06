#include "Player.h"

#include <cmath>

#include "Enemy.h"
#include "KeyInput.h"
void Player::Initialize() {
	x_ = 1280 / 2;
	y_ = 720 / 2;
	radius_ = 20;
	for (size_t i = 0; i < kMaxBullet; ++i) {
		bullet_[i].x_ = 0;
		bullet_[i].y_ = 0;
		bullet_[i].radius_ = 0;
		bullet_[i].isAlive_ = false;
	}
	isClear_ = false;
}

void Player::Update() {
	int moveX = 0;
	int moveY = 0;
	static const int kSpeed = 3;
	if (KeyInput::PushKey(DIK_A)) {
		moveX -= kSpeed;
	}
	if (KeyInput::PushKey(DIK_D)) {
		moveX += kSpeed;
	}
	if (KeyInput::PushKey(DIK_W)) {
		moveY -= kSpeed;
	}
	if (KeyInput::PushKey(DIK_S)) {
		moveY += kSpeed;
	}
	x_ += moveX;
	y_ += moveY;

	if (KeyInput::TriggerKey(DIK_SPACE)) {
		for (size_t i = 0; i < kMaxBullet; ++i) {
			if (!bullet_[i].isAlive_) {
				bullet_[i].x_ = x_;
				bullet_[i].y_ = y_;
				bullet_[i].radius_ = radius_ / 2;
				bullet_[i].isAlive_ = true;
				break;
			}
		}
	}
	static const int kBulletSpeed = 5;
	for (size_t i = 0; i < kMaxBullet; ++i) {
		if (bullet_[i].isAlive_) {
			bullet_[i].y_ -= kBulletSpeed;
			int x = bullet_[i].x_ - enemy_->GetX();
			int y = bullet_[i].y_ - enemy_->GetY();
			float distance = float(std::sqrt(x * x + y * y));
			if (distance <= float(bullet_[i].radius_) + float(enemy_->GetRadius())) {
				isClear_ = true;
			}
			if (bullet_[i].y_ + bullet_[i].radius_ <= 0.0f) {
				bullet_[i].isAlive_ = false;
			}
		}
	}
}

void Player::Draw() {
	for (size_t i = 0; i < kMaxBullet; ++i) {
		if (bullet_[i].isAlive_) {
			Novice::DrawEllipse(bullet_[i].x_, bullet_[i].y_, bullet_[i].radius_, bullet_[i].radius_, 0.0f,
			    0x00FF00FF, kFillModeSolid);
		}
	}
	Novice::DrawEllipse(x_, y_, radius_, radius_, 0.0f, 0xFF0000FF, kFillModeSolid);
}
