#include <raylib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdbool.h>
#include <math.h>


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
	float j = 10.0;


};

const char * intTochar(int a);
bool checkCollision(int x1, float x2, int y1, float y2, int w1, int h1, float j);


int main()
{
	struct player player;
	player.x = 20;
	player.y = 100;

	struct player cpu;
	cpu.x = WIDTH - 35;
	cpu.y = 100;

	struct ball ball;
	ball.x = (WIDTH / 2) - ball.j;
	ball.y = 120;
	ball.Ballx = -5;
	ball.Bally = -5;



	InitWindow(WIDTH, HEIGHT, "PONG CLONE");
	SetTargetFPS(60);



	do
	{

		BeginDrawing();
		ClearBackground(BLACK);// clears backgournd and sets it black
		DrawRectangle(0, 0, (WIDTH / 2), HEIGHT, BLACK);
		DrawRectangle((WIDTH / 2), 0, (WIDTH / 2), HEIGHT, WHITE);
		DrawRectangle(player.x, player.y, player.width, player.height, WHITE); // draws a paddle using variables from the player struct
		DrawRectangle(cpu.x, cpu.y, cpu.width, cpu.height, BLACK);// draws a paddle using variables from the CPU struct
		DrawText(intTochar(player.score), (WIDTH / 2) - 200, 30, 48, WHITE);// sets players score onto the screen not working
		DrawText(intTochar(cpu.score), (WIDTH / 2) + 200, 30, 48, BLACK);// sets cpu score onto screen not working odd

		if (checkCollision(player.x, ball.x, player.y, ball.y, player.width, player.height, ball.j) || checkCollision(cpu.x, ball.x, cpu.y, ball.y, cpu.width, cpu.height, ball.j))
		{
			ball.Ballx = -1 * ball.Ballx;	//if collides with ball and player is a player multiply to reverse the balls trajectory
		}

		cpu.y = ball.y;

		if (ball.x < (WIDTH / 2)) DrawCircle(ball.x, ball.y, ball.j, WHITE);

		else DrawCircle(ball.x, ball.y, ball.j, BLACK);
		EndDrawing();

		ball.x += ball.Ballx;
		ball.y += ball.Bally;

		if (ball.x < 5)
		{
			cpu.score++;
			ball.x = (WIDTH / 2) - ball.j;
			ball.y = 120;
			ball.Ballx = -5;

		}
		else if (ball.x > WIDTH - 5)
		{

			player.score++;
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
		}// key inputs for player paddle
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
		{

			if (player.y < 5);
			else player.y -= 5;
		}
		else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
		{
			if (player.y > (HEIGHT - player.height));
			else player.y += 5;
		}

	} while (!WindowShouldClose());
		
	CloseWindow();

	return 0;
}

const char* intTochar(int a) {
	std::stringstream ss;
	ss << a;
	std::string str;
	ss >> str;

	return str.c_str();
}

bool checkCollision(int x1, float x2, int y1, float y2, int w1, int h1, float j) 
{
	if (x1 <= x2 + j && y1 <= y2 + j &&
		x2 <= x1 + w1 && y2 <= y1 + h1)
	{
		return true;
	}
	else return false;
}
