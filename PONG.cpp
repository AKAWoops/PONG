// PONG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <raylib.h>
#include <iostream>
#define WIDTH 640 //width is 640px screen width
#define HEIGHT 480 //height is 480px screen height

struct player 
{
	int x;
	int y;
	int width = 20;
	int height = 70;
	int score = 0;
};

struct ball 
{
	float x;
	float y;
	float Ballx;
	float Bally;
	float j = 0;


};

const char* intTochar(int a);
bool chackCollision(int x1, float x2, int y1, float y2, int w1, int h1, float r);


int main()
{
	struct player player;
	player.x = 5;
	player.y = 50;

	struct ball ball;
	ball.x = (WIDTH / 2) - ball.j;
	ball.y = 120;
	ball.Ballx = -5;
	ball.Bally = -5;

	InitWindow(WIDTH, HEIGHT, "pong");
	SetTargetFPS(60);





	BeginDrawing();
	ClearBackground(BLACK);
	DrawRectangle(0, 0, (WIDTH / 2), HEIGHT, BLACK);
	DrawRectangle((WIDTH / 2), 0, (WIDTH / 2), HEIGHT, WHITE);
	DrawRectangle(player.x, player.y, player.width, player.height, WHITE);
	//DrawText(intTochar(player.score), (WIDTH / 2) - 200, 30, 48, WHITE);

	if (checkCollision(player.x, ball.x, player.y, ball.y, player.width, player.height, ball.j)
	{
	//if collides with ball and player is a player multiply to reverse the balls trajectory
	}
	
		while (!WindowShouldClose());
		
		CloseWindow();
	}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
