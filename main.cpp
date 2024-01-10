#include <Novice.h>

#include "Matrix4x4.h"
#include "MyMath.h"
#include "Quaternion.h"
#include "Vector3.h"

const char kWindowTitle[] = "学籍番号";

static const int kColumWidth = 60;
static const int kRowHeight = 20;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.03f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.03f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.03f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);
}

void QuaternionScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", quaternion.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", quaternion.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", quaternion.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%.02f", quaternion.w);
	Novice::ScreenPrintf(x + kColumWidth * 4, y, "%s", label);
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	for (int i = 0; i < 4; i++) {
		Novice::ScreenPrintf(x, y + kRowHeight * i, "%.03f", matrix.m[i][0]);
		Novice::ScreenPrintf(x + kColumWidth, y + kRowHeight * i, "%.03f", matrix.m[i][1]);
		Novice::ScreenPrintf(x + kColumWidth * 2, y + kRowHeight * i, "%.03f", matrix.m[i][2]);
		Novice::ScreenPrintf(x + kColumWidth * 3, y + kRowHeight * i, "%.03f", matrix.m[i][3]);
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
		Quaternion rotation0 = MakeRotateAxisAngleQuaternion({0.71f, 0.71f, 0.0f}, 0.3f);
		Quaternion rotation1 = MakeRotateAxisAngleQuaternion({0.71f, 0.0f, 0.71f}, 3.141592f);

		Quaternion interpolate0 = Slerp(rotation0, rotation1, 0.0f);
		Quaternion interpolate1 = Slerp(rotation0, rotation1, 0.3f);
		Quaternion interpolate2 = Slerp(rotation0, rotation1, 0.5f);
		Quaternion interpolate3 = Slerp(rotation0, rotation1, 0.7f);
		Quaternion interpolate4 = Slerp(rotation0, rotation1, 1.0f);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		QuaternionScreenPrintf(0, kRowHeight * 0, interpolate0, "interpolate0");
		QuaternionScreenPrintf(0, kRowHeight * 1, interpolate1, "interpolate1");
		QuaternionScreenPrintf(0, kRowHeight * 2, interpolate2, "interpolate2");
		QuaternionScreenPrintf(0, kRowHeight * 3, interpolate3, "interpolate3");
		QuaternionScreenPrintf(0, kRowHeight * 4, interpolate4, "interpolate4");
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
