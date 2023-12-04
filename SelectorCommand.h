#pragma once

#include <cstdint>

#include "ISceneCommand.h"

class Selector;
class SelectMoveCommand : public IStageCommand {
public:
	SelectMoveCommand(Selector* selector, int32_t x, int32_t y);
	void Exec() override;

private:
	Selector* selector_;
	int32_t x_;
	int32_t y_;
};

class SelectUnitCommand : public IStageCommand {
public:
	SelectUnitCommand(Selector* selector);
	void Exec() override;

private:
	Selector* selector_;
};