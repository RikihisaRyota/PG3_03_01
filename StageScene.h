#pragma once
#include "IState.h"

#include "Enemy.h"
#include "Player.h"
class StageScene : public IState {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	Enemy enemy_;
	Player player_;
};
