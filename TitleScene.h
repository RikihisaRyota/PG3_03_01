#pragma once

#include "IState.h"
class TitleScene : public IState {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

};
