#pragma once
class Poo
{
public:
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;

	static constexpr int Width = 24;
	static constexpr int Height = 24;

public:
	Poo();
	Poo(int x, int y, int vx, int vy);
	void Update();
};

