#include <Novice.h>

#include "Vector3.h"

const char kWindowTitle[] = "学籍番号";


static const int kColumWidth = 60;
static const int kRowHeight = 20;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		VectorScreenPrintf;
		/*VectorScreenPrintf(0, 0, resultAdd, "	: Add");
		VectorScreenPrintf(0, kRowHeight, resultSub, "	: Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMul, "	: Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f	:	Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f	:	Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, "	: Normalize");*/
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
