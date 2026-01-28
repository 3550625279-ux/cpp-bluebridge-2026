#include<iostream>
#include<stdio.h>
#include "global.h"
using namespace std;

SnakeNode*createNode(int x,int y)
{
	SnakeNode *p=new SnakeNode;
	if(p==NULL) return NULL;
	p->x=x;
	p->y=y;
	p->next=NULL;
	return p;
}

void initialSnake(int x,int y)
{
	if(head!=NULL)
	{
		emptyList();
		head=NULL;//需要衔接后面的清空链表函数，明确head和tail 
		tail=NULL;
		snake_length=0;
	}
	head=createNode(x,y);
	head->next=createNode(x-1,y);
	head->next->next=createNode(x-2,y);
	tail=head->next->next;
	snake_length=3;
}

void SnakeMoveHead(int x,int y)
{
	if(head==NULL)
	{
		head=createNode(x,y);
		tail=head;
		snake_length=1;
		return;
	}
	SnakeNode *ptr=createNode(x,y);
	ptr->next=head;
	head=ptr;
	snake_length++;
}

void SnakeMoveTail(void)
{
	if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
		snake_length=0;
		return;
	}
	SnakeNode *ptr=head;
	while(ptr->next!=tail)
		ptr=ptr->next;
	ptr->next=NULL;
/*	delete tail;
	tail=ptr;
	snake_length--;
	*/
	record_tail=tail;
	tail=ptr;
	snake_length--;
}

void SnakeEat(int x,int y)
{
	if(head==NULL)
	{
		head=createNode(x,y);
		tail=head;
		snake_length=1;
		return;
	}
	SnakeNode *ptr=createNode(x,y);
	tail->next=ptr;
	tail=ptr;
	snake_length++;
}

bool isOnSnake(int x,int y)
{
	if(head==NULL) return false;
	SnakeNode*ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->x==x&&ptr->y==y)
			return true;
		ptr=ptr->next;
	}
	return false;
}

void emptyList(void)
{
	if(head==NULL)	return;
	SnakeNode *curr=head;
	while(curr!=NULL)
	{
		SnakeNode *next=curr->next;
		delete curr;
		curr=next;
	}
	head=NULL;
	tail=NULL;
	snake_length=0;
}

int getSnakeLength()
{
	return snake_length;
}

