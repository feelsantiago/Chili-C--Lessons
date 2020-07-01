#include "Poo.h"
#include "Graphics.h"

Poo::Poo() {}

Poo::Poo(int x, int y, int vx, int vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}

void Poo::Update()
{
	x += vx;
	y += vy;

	const int right = x + Width;
	const int bottom = y + Height;

	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right > Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - Width;
		vx = -vx;
	}

	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom > Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - Height;
		vy = -vy;
	}
}
