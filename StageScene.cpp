#include "StageScene.h"
#include <Novice.h>

#include "ISceneCommand.h"

void StageScene::Initialize() {
	inputHandler_ = std::make_unique<StageSceneInputHandler>();
	selector_ = std::make_unique<Selector>();
}

void StageScene::Update() {
	IStageCommand* command{};

	inputHandler_->UpdateKeyState();

	if (selector_->GetSelectMode() == Selector::SelectMode::kSelector) {
		command = inputHandler_->SelectorHandleInput(selector_.get());
	} else if (selector_->GetSelectMode() == Selector::SelectMode::kUnit) {
		command = inputHandler_->UnitHandleInput(selector_->GetSelectUnit());
	}
	if (command) {
		command->Exec();
	}
}

void StageScene::Draw() {
	for (int32_t x = 0; x < 1280 / 32; x++) {
		Novice::DrawLine(x * 32, 0, x * 32, 720, 0xFFFFFFFF);
	};
	for (int32_t y = 0; y < 720 / 32; y++) {
		Novice::DrawLine(0, y*32, 1280, y*32, 0xFFFFFFFF);
	}

	selector_->Draw();
}
