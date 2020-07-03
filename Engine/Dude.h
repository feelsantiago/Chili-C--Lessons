#pragma once

#include "Poo.h"

class Dude
{
public:
	int x = 400;
	int y = 300;

	static constexpr int Width = 20;
	static constexpr int Height = 20;

public:
	void Update();
	// read-only reference
	bool IsColliding(const Poo& poo);
};

