#pragma once

#include <memory>

#include "IState.h"
#include "StageSceneInputHandler.h"
#include "Selector.h"

class StageScene : public IState {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	std::unique_ptr<StageSceneInputHandler> inputHandler_;
	std::unique_ptr<Selector> selector_;

};
