#pragma once

#include "IState.h"
class ClearScene :public IState{
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
};
