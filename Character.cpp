#include "Character.h"
#include <raylib.h>

Character::Character()
{
	x = 20;
	y = 100;
}

Character::Character(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Character::Draw()
{
	DrawRectangle(x, y, width, height, PURPLE); // draws a paddle using variables from the player struct
	//DrawRectangle(x, y, width, height, BLACK);
}

int Character::GetScore()
{
	return score;
}

void Character::IncScore()
{
	score++;
}

int Character::GetX()
{
	return x;
}

int Character::GetY()
{
	return y;
}

void Character::SetX(int _x)
{
	x += _x;
}

void Character::SetY(int _y)
{
	y += _y;
}

int Character::GetWIDTH()
{
	return width;
}

int Character::GetHEIGHT()
{
	return height;
}
