#ifndef GLOBAL_H
#define GLOBAL_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime> 
#include<conio.h>
#include<cmath>
#include <windows.h>

#define COLOR_SNAKE_HEAD    10  // ÁÁÂÌ
#define COLOR_SNAKE_BODY     2  // ÂÌ
#define COLOR_FOOD          12  // ÁÁºì
#define COLOR_BOUNDARY      14  // »Æ
#define COLOR_UI            15  // °×
#define COLOR_BG             8  // »Ò
#define size 20
#define cols 5
#define rows 5 

struct SnakeNode
{
	int x;
	int y;
	SnakeNode*next;
};
struct anxis
{
	int x;
	int y;
};
enum SnakeDirection
{
	Stop=0,
	Up=1,
	Left=2,
	Down=3,
	Right=4
};


extern SnakeNode *head;
extern SnakeNode *tail;
extern SnakeNode *record_head;
extern SnakeNode *record_tail;
extern int snake_length;
extern anxis food;
extern SnakeDirection currDir;
extern bool gameOver;
extern int foods;
extern int foodscore;
extern int currscore;
extern bool isValidin;
extern int speed;


SnakeNode*createNode(int x,int y);
void initialSnake(int x,int y);
void SnakeMoveHead(int x,int y);
void SnakeMoveTail();
void SnakeEat(int x,int y);
bool isOnSnake(int x,int y);
void emptyList(void);
int getSnakeLength();
void initialGame();
void updateGame();
void generateFood();
bool isBoard();
bool isSnake();
bool isFood();
void Eatfood();
void showGameover();
void restartGame();
void initialInput();
bool input_kbhit();
char input_getch();
bool isOppositeDir(SnakeDirection old_dir,SnakeDirection new_dir);
void input_poccess();
void draw_frame(void);
void draw_boundary();
void clear_screen(void);
void set_cursor(int x, int y);
void set_color(int color);
void initialDisplay(void);
void hideCursor(void);
void showCursor(void);
void kill_snake();
#endif
