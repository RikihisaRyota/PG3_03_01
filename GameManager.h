#pragma once

#include <memory>

#include "ClearScene.h"
#include "IState.h"
#include "TitleScene.h"
#include "StageScene.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	int Run();

private:
	std::unique_ptr<IState> sceneArr_[static_cast<size_t>(Scene::kCount)];

	uint32_t currentSceneID_;
	uint32_t prevSceneID_;
};
