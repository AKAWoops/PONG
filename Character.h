#pragma once
class Character
{
private:
	

	int x;
	int y;
	int width = 20;
	int height = 70;
	int score = 0;


public:
	Character();
	Character(int _x, int _y);
	
	void Draw();
	int GetScore();
	void IncScore();

	int GetX();
	int GetY();
	void SetX(int _x);
	void SetY(int _y);
	int GetWIDTH();
	int GetHEIGHT();
};

