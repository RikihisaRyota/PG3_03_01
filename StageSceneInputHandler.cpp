#include "StageSceneInputHandler.h"

StageSceneInputHandler::StageSceneInputHandler() {}

void StageSceneInputHandler::UpdateKeyState() {}

ISceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) { return nullptr; }

ISceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) { return nullptr; }

bool StageSceneInputHandler::CheckUndoStatus() { return false; }
