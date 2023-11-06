#include "ClearScene.h"

#include <Novice.h>

#include "KeyInput.h"

void ClearScene::Initialize() {}

void ClearScene::Update() {
	if (KeyInput::TriggerKey(DIK_SPACE)) {
		sceneNo_ = Scene::kTitle;
	}
}

void ClearScene::Draw() { 
	Novice::ScreenPrintf(1280/2, 720/2, "Clear"); 
}
