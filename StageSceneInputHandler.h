#pragma once

class IStageCommand;
class Selector;
class Unit;
class StageSceneInputHandler {
public:
	StageSceneInputHandler();
	void UpdateKeyState();

	IStageCommand* SelectorHandleInput(Selector* selector);
	IStageCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();

private:
	Selector* selector_;
	Unit* selectUnit_;
};
