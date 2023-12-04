#include "SelectorCommand.h"

#include "Selector.h"

SelectMoveCommand::SelectMoveCommand(Selector* selector, int32_t x, int32_t y) { 
	selector->Move(x,y);
}

void SelectMoveCommand::Exec() {

}

SelectUnitCommand::SelectUnitCommand(Selector* selector) { 
	selector->SelectUnit(); 
}

void SelectUnitCommand::Exec() {}
