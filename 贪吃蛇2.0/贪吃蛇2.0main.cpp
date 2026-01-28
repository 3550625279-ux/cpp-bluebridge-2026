#include "global.h"
 
SnakeNode *head=NULL;
SnakeNode *tail=NULL;
SnakeNode *record_head=NULL;
SnakeNode *record_tail=NULL;
int snake_length=0;
int currscore=0;
int foods=0;
anxis food={0,0};
SnakeDirection currDir=Stop;
bool gameOver=false;
int foodscore=10;
bool isValidin=false;
int speed=200;
int main()
{
	initialGame();
	initialDisplay();
	draw_boundary();
	while(!gameOver)
	{
		input_poccess();
		updateGame();
		draw_frame();
		Sleep(speed);
		if(gameOver)
		{
			speed=200;
			showGameover(); 
		}
	}
	return 0;
}
