#include "Unit.h"

#include <Novice.h>

#include "Selector.h"

void Unit::Initialize(int32_t id) { 
	id_ = id; 
}

void Unit::Update() {}

void Unit::Draw() { 
	Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

void Unit::Move(int32_t x, int32_t y) { 
	mapX_ = x;
	mapY_ = y;
}

void Unit::MoveEnd(Selector* selector) { selector->Draw(); }
