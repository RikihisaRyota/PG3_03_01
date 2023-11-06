#pragma once
class Enemy {
public:
	void Initialize();
	void Update();
	void Draw();

	int GetRadius() { return radius_; }
	int GetX() { return x_; }
	int GetY() { return y_; }

private:
	int x_;
	int y_;
	int radius_;
	bool direction_;
};
