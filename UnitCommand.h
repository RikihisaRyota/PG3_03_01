#pragma once

#include "ISceneCommand.h"

#include <cstdint>

class Unit;
class Selector;
class UintMoveCommand : public IStageCommand {
public:
	UintMoveCommand(Unit* unit, int32_t x, int32_t y);
	void Exec() override;
private:
	Unit* unit_;
	int32_t x_;
	int32_t y_;
};

class UintMoveEndCommand : public IStageCommand {
public:
	UintMoveEndCommand(Unit* unit, Selector* selector);
	void Exec() override;

private:
	Unit* unit_;
	Selector* selector_;
};