#include "global.h"
using namespace std;

void initialInput()
{
	currDir=Stop;
	isValidin=false;
}

bool input_kbhit()
{
	if(_kbhit()) return true;
	else return false;
}

char input_getch()
{
	int ch=_getch();
	return (char)ch;
}

bool isOppositeDir(SnakeDirection old_dir,SnakeDirection new_dir)
{
	if(fabs(old_dir-new_dir)==2)
		return true;
	else return false;
}

void input_poccess()
{
	if(!input_kbhit())
	{
		isValidin=false;
		return;
	}
	isValidin=true;
	char key=input_getch();
	SnakeDirection old_dir=currDir,new_dir;
	isValidin=false;
	switch(key)
	{
		case 'w': case 'W': 
			new_dir=Up;
			break;
		case 'a': case 'A':
			new_dir=Left;
			break;
		case 's': case 'S':
			new_dir=Down;
			break;
		case 'd': case 'D':
			new_dir=Right;
			break;
		default:return;
	}
	isValidin=!isOppositeDir(old_dir,new_dir);
	if(isValidin)
		currDir=new_dir;
}


