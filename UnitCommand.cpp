#include "UnitCommand.h"

#include "Selector.h"
#include "Unit.h"

UintMoveCommand::UintMoveCommand(Unit* unit, int32_t x, int32_t y) { 
	unit->Move(x,y);
}

void UintMoveCommand::Exec() {}

UintMoveEndCommand::UintMoveEndCommand(Unit* unit, Selector* selector) { 
	unit->Draw(); 
	selector->Draw();
}

void UintMoveEndCommand::Exec() {}
