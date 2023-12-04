#include "TitleScene.h"
#include "KeyInput.h"
#include <Novice.h>

void TitleScene::Initialize() {
}

void TitleScene::Update() {
	if (KeyInput::IsTrigger(DIK_SPACE)) {
		sceneNo_ = Scene::kStage;
	}
}

void TitleScene::Draw() { 
	Novice::ScreenPrintf(1280 / 2, 720 / 2, "Title"); }
