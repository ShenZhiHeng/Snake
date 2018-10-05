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

int direction=77;//Ĭ������ǰ��
int getTimeCooling(Snake* snake);

void PlayMusic()
{
	PlaySound(L"1.wav",NULL,SND_FILENAME|SND_ASYNC);
}

int GameBegin(Face* face,Snake* snake,Food* food)
{
	if (snake->isMeetFood(food,direction))//�ж��Ƿ�������ʳ��
		snake->EatFood(face,food);
	else
	{
		snake->Move(face,direction);//û�г�ʳ����ƶ�
		if (snake->Die())//�ж��Ƿ�ײ��
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
		if (!_kbhit())//�ж��Ƿ��м�������
		{
			static int Cool_Time=getTimeCooling(&snake);//�����ߵĳ���������ȴʱ��
			Sleep(Cool_Time);//��ȴ
			//Sleep(1);
			if(!GameBegin(&face,&snake,&food))
				break;
		}
		else
		{
			if(_getch()!=224)//���ηǷ�����,�������ý���������whileѭ��
				continue;
			direction=_getch();
			if(!GameBegin(&face,&snake,&food))
				break;
		}
	}
	
	cout<<"\t\tBia!!!,�����ˣ�����"<<endl;
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
