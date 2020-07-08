#pragma once
#include "Dude.h"
#include "Graphics.h"

class Box
{
private:
	int x;
	int y;
	int red = 255;
	bool incrementColor = false;

public:
	static constexpr int Size = 20;

public:
	void Update();
	void Draw(Graphics& gfx);
	void SetPosition(int x_pos, int y_pos);
	bool isTouchedBy(const Dude& dude);
};

