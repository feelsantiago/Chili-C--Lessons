#include "Score.h"

void Score::Draw(Graphics& gfx)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gfx.PutPixel(j + x, i + y, 0, 0, 255);
		}
	}
}

void Score::IncrementScore()
{
	size += 10;
}
