#include "KeyInput.h"
#include <Novice.h>

void KeyInput::Input() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);


}

bool KeyInput::IsPressed(char keycode) {
	return keys[keycode] != 0;
}

bool KeyInput::IsTrigger(char keycode) {
	return preKeys[keycode] == 0 && keys[keycode] != 0;
}

bool KeyInput::IsRelease(char keycode) {
	return preKeys[keycode] != 0 && keys[keycode] == 0;
}

char KeyInput::keys[256] = { 0 };
char KeyInput::preKeys[256] = { 0 };