#include "global.h"
using namespace std;
void initialGame()
{
	currDir=Right;
	gameOver=false;
	currscore=0;
	foods=0;
	food={0,0};
	srand((unsigned int)time(NULL));
	emptyList();
	initialSnake(size/2,size/2);
	generateFood();
	hideCursor(); 
}

void updateGame()
{
	//if(gameOver) return;
	record_head=head;
	record_tail=tail; 
	anxis new_head={head->x,head->y};
	switch(currDir)
	{
		case Up: new_head.y--;break;
		case Left: new_head.x--;break;
		case Down: new_head.y++;break;
		case Right: new_head.x++;break;
		default:break;
	}
	SnakeMoveHead(new_head.x,new_head.y);
	SnakeMoveTail();
	if(isBoard()||isSnake())
	{
		gameOver=true;
		return;
	}
	else if(isFood())
	{
		SnakeEat(record_tail->x,record_tail->y);
		Eatfood();
	}
}

void generateFood()
{
	bool isrightposition=false;
	while(!isrightposition)
	{
		food.x=rand()%(size-1)+1;
		food.y=rand()%(size-1)+1;
		isrightposition=!isOnSnake(food.x,food.y);
		if(isrightposition)
		break;
	}
}

bool isBoard()
{
	if(head==NULL||head->x<=0||head->x>=2*size||head->y<=0||head->y>=size)
		return true;
	else return false;
}

bool isSnake()
{
	if(snake_length<4||head==NULL) return false;
	SnakeNode *ptr=head->next;
	while(ptr!=NULL)
	{
		if(head->x==ptr->x&&head->y==ptr->y)
			return true;
		ptr=ptr->next;
	}
	return false;
}

bool isFood()
{
	if(head==NULL) return false;
	if(head->x==food.x&&head->y==food.y) return true;
	else return false;
}

void Eatfood()
{
	currscore+=foodscore;
	foods++;
	generateFood();
	if(currscore%50==0)
	{
		speed-=30;
	}
}

void showGameover()
{
	showCursor();
	system("cls");
	cout<<"Game over!"<<endl;
	printf("You have ate %d food,achieved %d scores\n",foods,currscore);
	cout<<"press 'r' to try again! or 'q' to quiz the game!"<<endl;
	fflush(stdin);
	char ch=getchar();
	if(ch=='r'||ch=='R')
	{
		restartGame();
		return;
	}
	else if(ch=='q'||ch=='Q')
		exit(0);
}

void restartGame()
{
	system("cls");
	initialGame(); 
	initialDisplay();
	draw_boundary();
	//可能初始化两次 
}


