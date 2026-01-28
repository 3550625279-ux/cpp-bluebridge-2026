#include "global.h"
using namespace std;
static HANDLE hConsole=NULL;
void initialDisplay(void);
void draw_snake();
void draw_food();
void draw_boundary();
void draw_UI();

void initialDisplay(void)
{
	if(!hConsole) hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
}

void set_cursor(int x,int y)
{
	COORD pos={(SHORT)x,(SHORT)y};
	SetConsoleCursorPosition(hConsole,pos);
}

void set_color(int color)
{
    if(!hConsole) initialDisplay();
    SetConsoleTextAttribute(hConsole, color);
}

void draw_snake()
{
	SnakeNode *current=head;
	while(current!=NULL)
	{
		int screen_x,screen_y;
		screen_x=cols+current->x;
		screen_y=rows+current->y;
		set_cursor(screen_x,screen_y);
		if (current == head)
		{
            set_color(COLOR_SNAKE_HEAD);
            printf("●");
        }
		else
		{
            set_color(COLOR_SNAKE_BODY);
            printf("○");
        }
        current = current->next;  
	}
}

void draw_food()
{
	int food_screen_x,food_screen_y;
	food_screen_x=food.x+cols;
	food_screen_y=food.y+rows;
	set_cursor(food_screen_x,food_screen_y);
	set_color(COLOR_FOOD);
	printf("★");
}

void draw_boundary()
{
	int left=cols;
	int right=cols+2*size+1;
	int top=rows;
	int bottom=rows+size;
	set_cursor(left,top);
	printf("┌");
	set_color(COLOR_BOUNDARY);
    for(int i = 0;i<2*size; i++)printf("─");
    printf("┐");
    set_cursor(left,bottom);
    printf("└");
    for(int i=0;i<2*size;i++) printf("─");
    printf("┘");
    for(int y=top;y<=bottom;y++)
    {
    	set_cursor(left,y);printf("|");
    	set_cursor(right,y);printf("|");
	}
}

void draw_UI()
{
	set_cursor((80-8)/2,2);
	set_color(COLOR_UI);
	printf("score: %d  length:%d",currscore,snake_length);
	int title_len = 11; // "Snake Game"
    int x = (80 - title_len) / 2; // 假设控制台宽80
    set_cursor(x, 0);
    set_color(COLOR_SNAKE_HEAD);
    printf("Snake Game");
    const char* hint = "WASD/方向键移动，ESC退出";
    int y = (80 - strlen(hint)) / 2;
    set_cursor(y, 1);
    set_color(9); // 淡蓝
    printf("%s", hint);
}

void draw_frame(void)
{
    kill_snake();
    draw_UI();
    draw_food();
    draw_snake();       // 必须在食物之后（避免覆盖）
    // 重置颜色，避免影响后续输出
    set_color(COLOR_UI);
}

void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;          // 光标闪烁频率 (1-100)，此处设为最小
    cursorInfo.bVisible = FALSE;    // 关键：设置为 FALSE 以隐藏
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void showCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;     // 关键：设置为 TRUE 以显示
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void kill_snake()
{
	while(record_head!=NULL)
	{
		int screen_x,screen_y;
		screen_x=cols+record_head->x;
		screen_y=rows+record_head->y;
		set_cursor(screen_x,screen_y);
		printf(" ");
		record_head=record_head->next;
	}
	int screen_x,screen_y;
		screen_x=cols+record_tail->x;
		screen_y=rows+record_tail->y;
		set_cursor(screen_x,screen_y);
		printf(" ");
	/*if(!isFood())
	{
		int screen_x,screen_y;
		screen_x=cols+tail->x;
		screen_y=rows+tail->y;
		set_cursor(screen_x,screen_y);
		cout<<' ';
	} 
	*/
	delete record_tail;
}

