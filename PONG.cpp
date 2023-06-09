#include <raylib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdbool.h>
#include <math.h>
#include "Character.h"

#define WIDTH 640 //width is 640px screen width
#define HEIGHT 480 //height is 480px screen height

//struct player1 
//{
//	/*int p1x;
//	int p1y;
//	int width = 20;
//	int height = 70;
//	int score = 0;*/
//};

//struct player2
//{
//	int p2x;
//	int p2y;
//	int width = 20;
//	int height = 70;
//	int score = 0;
//};

struct cpu
{
	int cpux;
	int cpuy;
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
	float j = 10.0;
};

//const char* intTochar(int a);
bool checkCollision(int x1, float x2, int y1, float y2, int w1, int h1, float j);

	Character player1;
	Character player2;
	int score;
int main()
{
	/*player1.p1x = 20;
	player1.p1y = 100;*/

	/*player2.p2x = WIDTH - 35;
	player2.p2y = 100;*/

	player1 = Character(20, 100);
	player2 = Character(WIDTH -35, 100);

	struct cpu cpu;
	cpu.cpux = WIDTH - 35;
	cpu.cpuy = 100;

	struct ball ball;
	ball.x = (WIDTH / 2) - ball.j;
	ball.y = 120;
	ball.Ballx = -5;
	ball.Bally = -5;



	InitWindow(WIDTH, HEIGHT, "PONG CLONE By Mark Ballinger");
	SetTargetFPS(60);



	do
	{
		BeginDrawing();
		ClearBackground(BLACK);// clears backgournd and sets it black
		DrawRectangle(0, 0, (WIDTH / 2), HEIGHT, BLACK);
		DrawRectangle((WIDTH / 2), 0, (WIDTH / 2), HEIGHT, WHITE);
		//DrawRectangle(player1.p1x, player1.p1y, player1.width, player1.height, WHITE); // draws a paddle using variables from the player struct
		player1.Draw(WHITE);
		//DrawRectangle(player2.x, player2.y, player2.width, player2.height, BLACK);// draws a paddle using variables from the CPU struct
		player2.Draw(BLACK);
		//DrawText(intTochar(player1.score), (WIDTH / 2) - 200, 30, 48, GREEN);// sets players score onto the screen not working
		//DrawText(intTochar(player2.score), (WIDTH / 2) + 200, 30, 48, GREEN);// sets cpu score onto screen not working odd
		DrawText(TextFormat("Score: %04i", player1.GetScore()), (WIDTH / 2) - 200, 80, 20, RED);
		DrawText(TextFormat("Score: %04i", player2.GetScore()), (WIDTH / 2) + 200, 80, 20, RED);

		if (checkCollision(player1.GetX(), ball.x, player1.GetY(), ball.y, player1.GetWIDTH(), player1.GetHEIGHT(), ball.j) 
			|| checkCollision(player2.GetX(), ball.x, player2.GetY(), ball.y, player2.GetWIDTH(), player2.GetHEIGHT(), ball.j))
		{
			ball.Ballx = -1 * ball.Ballx;	//if collides with ball and player is a player multiply to reverse the balls trajectory
		}

		cpu.cpuy = ball.y;// makes sure the cpu y position is always equal to balls y position

		if (ball.x < (WIDTH / 2)) DrawCircle(ball.x, ball.y, ball.j, WHITE); //this function draws a rectangle usig vairABLES From ball struct

		else DrawCircle(ball.x, ball.y, ball.j, BLACK);
		EndDrawing();

		ball.x += ball.Ballx;
		ball.y += ball.Bally;

		if (ball.x < 5)
		{
			player2.IncScore();
			ball.x = (WIDTH / 2) - ball.j;
			ball.y = 120;
			ball.Ballx = -5;
		}
		else if (ball.x > WIDTH - 5)
		{

			player1.IncScore();
			ball.x = (WIDTH / 2) - ball.j;
			ball.y = 120;
			ball.Ballx = 5;
		}
		if (ball.y < 5)
		{
			ball.Bally = -1 * ball.Bally;
		}
		else if (ball.y > HEIGHT - 5)
		{
			ball.Bally = -(ball.Bally);
		}


		// key inputs for player paddle
		if (IsKeyDown(KEY_W)) //|| IsKeyDown(KEY_UP))
		{
			if (player1.GetY() < 5);
			else player1.SetY(-5) ;
		}
		else if (IsKeyDown(KEY_S)) //|| IsKeyDown(KEY_DOWN))
		{
			if (player1.GetY() > (HEIGHT - player1.GetHEIGHT()));
			else player1.SetY(+5);
		}
		if (IsKeyDown(KEY_UP))// || IsKeyDown(KEY_UP))
		{
			if (player2.GetY() < 5);//1 (HEIGHT - player2.height));
			else player2.SetY(-5);
		}
		else if (IsKeyDown(KEY_DOWN))// || IsKeyDown(KEY_DOWN))
		{
			if (player2.GetY() > (HEIGHT - player2.GetHEIGHT()));
			else player2.SetY(+5);
		}
		
	} while (!WindowShouldClose());
		
	CloseWindow();

	return 0;
}

//const char* intTochar(int a) {
//	std::stringstream ss;
//	ss << a;
//	std::string str;
//	ss >> str;
//
//	return str.c_str();
//}

bool checkCollision(int x1, float x2, int y1, float y2, int w1, int h1, float j) 
{                  // question for cliff should i change j to r for trajectory ? i think j is the correct statement
	if (x1 <= x2 + j && y1 <= y2 + j &&
		x2 <= x1 + w1 && y2 <= y1 + h1)
	{
		return true;
	}
	else return false;
}
