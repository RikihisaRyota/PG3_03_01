#include "StageScene.h"

#include <Novice.h>

void StageScene::Initialize() { 
	enemy_.Initialize();
	player_.SetEnemy(&enemy_);
	player_.Initialize();
}

void StageScene::Update() { 
	enemy_.Update();
	player_.Update();
	if (player_.GetIsClear()) {
		sceneNo_ = Scene::kClear;
	}
}

void StageScene::Draw() {
	Novice::ScreenPrintf(1280 / 2, 720 / 2, "Stage"); 
	enemy_.Draw();
	player_.Draw();
}
