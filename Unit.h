#pragma once

#include <cstdint>

class Selector;
class Unit {
public:
	Unit() = default;

	void Initialize(int32_t id);
	void Update();
	void Draw();

	void Move(int32_t x, int32_t y);
	void MoveEnd(Selector* selector);

private:
	int32_t mapX_ = 0;
	int32_t mapY_ = 0;
	int32_t mapSize_ = 32;
	int32_t id_ = 0;
	bool isSelected_ = false;
};
