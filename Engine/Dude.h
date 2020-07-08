#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void ClampToScreen();
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd );
	void SetDirty();
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	int IsDirty() const;
private:
	int x = 400;
	int y = 300;
	bool dirty = false;
	static constexpr int speed = 1;
	static constexpr int width = 20;
	static constexpr int height = 20;
};