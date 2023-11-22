#include <Novice.h>

#include "MyMath.h"
#include "Matrix4x4.h"
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

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	for (int i = 0; i < 4; i++) {
		Novice::ScreenPrintf(x , y + kRowHeight * i, "%.02f", matrix.m[i][0]);
		Novice::ScreenPrintf(x + kColumWidth, y + kRowHeight * i, "%.02f", matrix.m[i][1]);
		Novice::ScreenPrintf(x + kColumWidth * 2, y + kRowHeight * i, "%.02f", matrix.m[i][2]);
		Novice::ScreenPrintf(x + kColumWidth * 3, y + kRowHeight * i, "%.02f", matrix.m[i][3]);
		Novice::ScreenPrintf(x + kColumWidth * 4, y + kRowHeight * i, "%s", label);
	}
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
		Vector3 axis = Normalize({1.0f,1.0f,1.0f});
		float angle = 0.44f;
		Matrix4x4 rotateMatrix = MakeRotateAxisAngle(axis,angle);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		MatrixScreenPrintf(0, 0, rotateMatrix, "rotateMatrix");
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
