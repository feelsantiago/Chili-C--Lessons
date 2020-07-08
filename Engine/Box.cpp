#include "Box.h"

void Box::SetPosition(int x_pos, int y_pos)
{
	x = x_pos;
	y = y_pos;
}

bool Box::isTouchedBy(const Dude& dude)
{
	const int duderight = dude.GetX() + dude.GetWidth();
	const int dudebottom = dude.GetY() + dude.GetHeight();
	const int boxright = x + Size;
	const int boxbottom = y + Size;

	return duderight >= x &&
		dude.GetX() <= boxright &&
		dudebottom >= y &&
		dude.GetY() <= boxbottom;
}

void Box::Update()
{
	if (red == 0)
	{
		incrementColor = true;
	}
	else if (red == 255)
	{
		incrementColor = false;
	}

	if (incrementColor)
	{
		red++;
	}
	else
	{
		red--;
	}
}

void Box::Draw(Graphics& gfx)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			gfx.PutPixel(j + x, i + y, 255, red, red);
		}
	}
}
