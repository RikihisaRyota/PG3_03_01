#pragma once

#include <cstdint>
#include <vector>

class Unit;
class Selector {
public:
	enum SelectMode {
		kSelector,
		kUnit,

		kCount,
	};

	Selector();

	void Initialize();
	void Update();
	void Draw();

	void Move(int32_t x,int32_t y);
	void SelectUnit();


	void SetSelectMode(int32_t mode) { selectMode_ = mode; }
	const int32_t GetSelectMode() const { return selectMode_; }
	Unit* GetSelectUnit() { return selectedUnit_; }

private:
	
	int32_t mapX_;
	int32_t mapY_;
	int32_t mapSize_;

	int32_t selectMode_;
	std::vector<Unit*> unit_;
	Unit* selectedUnit_;
};
