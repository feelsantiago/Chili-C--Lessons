#pragma once
#include "Graphics.h"

class Score
{
private:
	int x = 50;
	int y = 25;
	int size = 0;

public:
	void Draw(Graphics& gfx);
	void IncrementScore();
};

