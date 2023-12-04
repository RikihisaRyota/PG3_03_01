#pragma once

#include <cstdint>

class Unit;
class Selector {
public:
	Selector();

	void Initialize();
	void Update();
	void Draw();

	void Move(int32_t x,int32_t y);
	void SelectUint();

private:
	int32_t mapX_;
	int32_t mapY_;
	int32_t mapSize_;

	int32_t selectMode_;
	Unit* unit_;
	Unit* selectedUnit_;
};
