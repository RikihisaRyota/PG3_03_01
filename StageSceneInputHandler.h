#pragma once

class ISceneCommand;
class Selector;
class Unit;
class StageSceneInputHandler {
public:
	StageSceneInputHandler();
	void UpdateKeyState();

	ISceneCommand* SelectorHandleInput(Selector* selector);
	ISceneCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();
};
