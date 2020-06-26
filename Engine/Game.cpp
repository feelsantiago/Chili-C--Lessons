/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	/* Moviment */

	// up
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!upMaxVelocity)
		{
			vy = -1;
			upMaxVelocity = true;
		}
	}
	else 
	{
		upMaxVelocity = false;
	}
	
	// down
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!bottomMaxVelocity)
		{
			vy = 1;
			bottomMaxVelocity = true;
		}
	}
	else
	{
		bottomMaxVelocity = false;
	}

	// left
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!leftMaxVelocity)
		{
			vx = -1;
			leftMaxVelocity = true;
		}
	}
	else
	{
		leftMaxVelocity = false;
	}
	
	// right
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!rightMaxVelocity)
		{
			vx = 1;
			rightMaxVelocity = true;
		}
	}
	else
	{
		rightMaxVelocity = false;
	}

	// reset velocity
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vx = 0;
		vy = 0;
	}

	// update velocity
	x += vx;
	y += vy;

	/* Boundary Checks */

	// out of bounds
	if (x + 5 >= gfx.ScreenWidth) 
	{
		x = gfx.ScreenWidth - 6;
		vx = 0;
	} 
	else if (x - 5 < 0)
	{
		x = 5;
	}

	if (y + 5 >= gfx.ScreenHeight) 
	{
		y = gfx.ScreenHeight - 6;
		vy = 0;
	}
	else if (y - 5 < 0)
	{
		y = 5;
	}

	const int leftEdge = x - 5;
	const int rightEdge = x + 5;
	const int topEdge = y - 5;
	const int bottomEdge = y + 5;

	const int boxLeftEdge = boxX - 6;
	const int boxRightEdge = boxX + 6;
	const int boxTopEdge = boxY - 6;
	const int boxBottomEdge = boxY + 6;

	// overlaps box
	if (leftEdge < boxRightEdge &&
		rightEdge > boxLeftEdge &&
		topEdge < boxBottomEdge &&
		bottomEdge > boxBottomEdge)
	{
		isColliding = true;
	} 
	else
	{
		isColliding = false;
	}

	// change color
	if (wnd.kbd.KeyIsPressed(VK_CONTROL) || isColliding)
	{
		color = 0;
	}
	else
	{
		color = 255;
	}

	shapeIsChange = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
	// point shape 
	if (shapeIsChange) {
		gfx.PutPixel(x, 1 + y, 255, color, 255);
		gfx.PutPixel(x, 1 + y, 255, color, 255);
		gfx.PutPixel(x, 1 + y, 255, color, 255);
		gfx.PutPixel(x, 1 + y, 255, color, 255);
		gfx.PutPixel(x, 1 + y, 255, color, 255);
		gfx.PutPixel(x, 1 + y, 255, color, 255);
	}
	// cross-line shape
	else
	{
		// Left Line
		gfx.PutPixel(-5 + x, y, 255, color, 255);
		gfx.PutPixel(-4 + x, y, 255, color, 255);
		gfx.PutPixel(-3 + x, y, 255, color, 255);

		// Right Line
		gfx.PutPixel(3 + x, y, 255, color, 255);
		gfx.PutPixel(4 + x, y, 255, color, 255);
		gfx.PutPixel(5 + x, y, 255, color, 255);

		// Upper Line
		gfx.PutPixel(x, -5 + y, 255, color, 255);
		gfx.PutPixel(x, -4 + y, 255, color, 255);
		gfx.PutPixel(x, -3 + y, 255, color, 255);

		// Bottom Line
		gfx.PutPixel(x, 3 + y, 255, color, 255);
		gfx.PutPixel(x, 4 + y, 255, color, 255);
		gfx.PutPixel(x, 5 + y, 255, color, 255);
	}

	// drawn box
	// upper line
	gfx.PutPixel(boxX, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 1, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 2, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 3, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 4, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 5, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY, 0, 255, 0);

	// bottom line
	gfx.PutPixel(boxX, boxY + 6, 0, 255, 0);
	gfx.PutPixel(boxX + 1, boxY + 6, 0, 255, 0);
	gfx.PutPixel(boxX + 2, boxY + 6, 0, 255, 0);
	gfx.PutPixel(boxX + 3, boxY + 6, 0, 255, 0);
	gfx.PutPixel(boxX + 4, boxY + 6, 0, 255, 0);
	gfx.PutPixel(boxX + 5, boxY + 6, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 6, 0, 255, 0);

	// left line
	gfx.PutPixel(boxX, boxY, 0, 255, 0);
	gfx.PutPixel(boxX, boxY + 1, 0, 255, 0);
	gfx.PutPixel(boxX, boxY + 2, 0, 255, 0);
	gfx.PutPixel(boxX, boxY + 3, 0, 255, 0);
	gfx.PutPixel(boxX, boxY + 4, 0, 255, 0);
	gfx.PutPixel(boxX, boxY + 5, 0, 255, 0);
	gfx.PutPixel(boxX, boxY + 6, 0, 255, 0);

	// right line
	gfx.PutPixel(boxX + 6, boxY, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 1, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 2, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 3, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 4, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 5, 0, 255, 0);
	gfx.PutPixel(boxX + 6, boxY + 6, 0, 255, 0);
}
