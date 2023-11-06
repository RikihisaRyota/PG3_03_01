#include "GameManager.h"

#include <Novice.h>

#include "KeyInput.h"

GameManager::GameManager() {
	sceneArr_[static_cast<size_t>(Scene::kTitle)] = std::make_unique<TitleScene>();
	sceneArr_[static_cast<size_t>(Scene::kTitle)]->Initialize();
	sceneArr_[static_cast<size_t>(Scene::kStage)] = std::make_unique<StageScene>();
	sceneArr_[static_cast<size_t>(Scene::kStage)]->Initialize();
	sceneArr_[static_cast<size_t>(Scene::kClear)] = std::make_unique<ClearScene>();
	sceneArr_[static_cast<size_t>(Scene::kClear)]->Initialize();

	currentSceneID_ = static_cast<uint32_t>(Scene::kTitle);
}

GameManager::~GameManager() {}

int GameManager::Run() { 
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();
		// シーンのチェック
		prevSceneID_ = currentSceneID_;
		currentSceneID_ = sceneArr_[(static_cast<size_t>(currentSceneID_))]->GetSceneNo();
		// シーンチェック
		if (prevSceneID_ != currentSceneID_) {
			sceneArr_[(static_cast<size_t>(currentSceneID_))]->Initialize();
		}
		// 更新
		sceneArr_[(static_cast<size_t>(currentSceneID_))]->Update();
		// 描画
		sceneArr_[(static_cast<size_t>(currentSceneID_))]->Draw();
		
		Novice::EndFrame();
		if (KeyInput::TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}
	return 0;
}
