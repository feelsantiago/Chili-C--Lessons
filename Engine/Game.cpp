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
}

void Game::ComposeFrame()
{
	// const definitions
	const int moviment = 100;

	// target variables 
	int x = 400;
	int y = 300;
	int color = 255;

	// moviment
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= moviment;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += moviment;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= moviment;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += moviment;
	}

	// change color
	if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
		color = 0;
	}

	// point shape 
	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {
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

}
