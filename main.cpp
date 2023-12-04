#include <Novice.h>

#include "GameManager.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	GameManager* gameManager = new GameManager();
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	delete gameManager;
	return 0;
}
