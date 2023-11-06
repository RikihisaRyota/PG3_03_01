#include "Enemy.h"

#include <Novice.h>

void Enemy::Initialize() { 
	x_ = 1280 / 2; 
	y_ += radius_;
	radius_ = 20;
	direction_ = false;
}

void Enemy::Update() { 
	const int kSpeed = 2;
	if (direction_) {
		x_ -= kSpeed;
	} else {
		x_ += kSpeed;
	}
	if (x_ -radius_< 0 ||
		x_ + radius_ > 1280) {
		direction_ ^= true;
	}
}

void Enemy::Draw() { 	
	Novice::DrawEllipse(x_,y_,radius_,radius_,0.0f,0x0000FFFF,kFillModeSolid);
}
