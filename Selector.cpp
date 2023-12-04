#include "Selector.h"

#include <Novice.h>

#include "Unit.h"

Selector::Selector() { 
	unit_.resize(4);
	for (size_t i = 0; i < 4; i++) {
		unit_.at(i) = new Unit();
	}
}

void Selector::Initialize() {

}

void Selector::Update() {}

void Selector::Draw() { 
	Novice::DrawBox(
	    mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFF0000FF,
	    kFillModeWireFrame);
}

void Selector::Move(int32_t x, int32_t y) { 
	mapX_ = x; 
	mapY_ = y; 
}

void Selector::SelectUnit() {}
