#pragma once
#include <cstdint>

enum class Scene {
	kTitle,
	kStage,
	kClear,

	kCount,
};

class IState {
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IState();

	uint32_t GetSceneNo() { return static_cast<uint32_t>(sceneNo_); }

protected:
	static Scene sceneNo_;
};