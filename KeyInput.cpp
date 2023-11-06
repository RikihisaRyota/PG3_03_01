#include "KeyInput.h"

#include "Input.h"

bool KeyInput::PushKey(BYTE keyNumber) { return Input::GetInstance()->PushKey(keyNumber); }

bool KeyInput::TriggerKey(BYTE keyNumber) { return Input::GetInstance()->TriggerKey(keyNumber); }

