#include "Dude.h"
#include "Poo.h"
#include "Graphics.h"

void Dude::Update()
{
	const int right = x + Dude::Width;
	const int bottom = y + Dude::Height;

	if (x < 0)
	{
		x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - Dude::Width;
	}

	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - Dude::Height;
	}
}

bool Dude::IsColliding(Poo poo)
{
	const int dudeRight = x + Dude::Width;
	const int dudeBottom = y + Dude::Height;
	const int pooRight = poo.x + Poo::Width;
	const int pooBottom = poo.y + Poo::Height;

	return
		dudeRight >= poo.x &&
		x <= pooRight &&
		dudeBottom >= poo.y &&
		y <= pooBottom;
}
