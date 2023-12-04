#include "StageSceneInputHandler.h"

#include <Novice.h>

#include "Selector.h"
#include "KeyInput.h"
#include "Unit.h"


StageSceneInputHandler::StageSceneInputHandler() {}

void StageSceneInputHandler::UpdateKeyState(){ 
	if (KeyInput::IsTrigger(DIK_W)) {
	
	}
	if (KeyInput::IsTrigger(DIK_S)) {

	}
	if (KeyInput::IsTrigger(DIK_A)) {

	}
	if (KeyInput::IsTrigger(DIK_D)) {

	}
	if (KeyInput::IsTrigger(DIK_SPACE)) {

	}

}

IStageCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) { 
	selector->Draw();
	return nullptr; 
}

IStageCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) {
	unit->Draw();
	return nullptr; }

bool StageSceneInputHandler::CheckUndoStatus() { return false; }
