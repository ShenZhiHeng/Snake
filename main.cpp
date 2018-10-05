#pragma once
#include <iostream>
#ifndef CONIO_H
#define CONIO_H
#include <conio.h>
#endif
#ifndef WINDOWS_H
#define WINDOWS_H
#include <Windows.h>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")
#include "Face.h"
#include "Snake.h"
#include "Food.h"
using namespace std;

int direction=77;//默认向右前进
int getTimeCooling(Snake* snake);

void PlayMusic()
{
	PlaySound(L"1.wav",NULL,SND_FILENAME|SND_ASYNC);
}

int GameBegin(Face* face,Snake* snake,Food* food)
{
	if (snake->isMeetFood(food,direction))//判断是否碰到了食物
		snake->EatFood(face,food);
	else
	{
		snake->Move(face,direction);//没有吃食物就移动
		if (snake->Die())//判断是否撞死
			return 0;
	}
	face->ScreenFlush();
	return 1;
}
int main()
{
	Face face;
	Snake snake(&face);
	Food food(&face);
	PlayMusic();
	while(!snake.Die())
	{
		if (!_kbhit())//判断是否有键盘输入
		{
			static int Cool_Time=getTimeCooling(&snake);//根据蛇的长度设置冷却时间
			Sleep(Cool_Time);//冷却
			//Sleep(1);
			if(!GameBegin(&face,&snake,&food))
				break;
		}
		else
		{
			if(_getch()!=224)//屏蔽非法输入,这里正好借助了外层的while循环
				continue;
			direction=_getch();
			if(!GameBegin(&face,&snake,&food))
				break;
		}
	}
	
	cout<<"\t\tBia!!!,你死了！！！"<<endl;
	system("pause");
	return 0;
}

int getTimeCooling(Snake* snake)
{
	int snakeSize=snake->getSize();
	if(snakeSize<=6)
		return 400;
	else if(snakeSize<=14)
		return 200;
	else if(snakeSize<=20)
		return 100;
	else if(snakeSize<=30)
		return 50;
	else 
		return 20;
}
