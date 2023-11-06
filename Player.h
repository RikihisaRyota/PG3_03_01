#pragma once
class Enemy;
class Player {
public:
	struct Bullet {
		int x_;
		int y_;
		int radius_;
		int isAlive_;
	};

public:
	void Initialize();
	void Update();
	void Draw();
	bool GetIsClear() { return isClear_; }
	void SetEnemy(Enemy* enemy) { enemy_ = enemy; }

private:
	static const int kMaxBullet = 10;
	Enemy* enemy_;
	int x_;
	int y_;
	int radius_;
	Bullet bullet_[kMaxBullet];
	bool isClear_;
};