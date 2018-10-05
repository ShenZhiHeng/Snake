#pragma once
#include "Face.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Face::Face()
{
	for (int i=0;i<23;i++)
	{
		mRect[0][i]=1;
	}
	for (int i=0;i<20;i++)
	{
		mRect[i][0]=1;
	}
	for (int i=1;i<19;i++)
	{
		for (int j=1;j<22;j++)
		{
			mRect[i][j]=0;
		}
	}
	for (int i=0;i<20;i++)
	{
		mRect[i][22]=1;
	}
	for (int i=0;i<23;i++)
	{
		mRect[19][i]=1;
	}
}
void Face::ScreenFlush()
{
	system("cls");
	for (int i=0;i<20;i++)
	{
		for (int j=0;j<23;j++)
		{
			if (1==mRect[i][j])
			{
				printf("¡ö");  
			}
			else
				printf("  ");
		}
		cout<<endl;
	}

}
void Face::DrawFood(int x,int y)
{
	mRect[x][y]=1;
	//this->ScreenFlush();
}
void Face::AddSnakeNode(int x,int y)
{
	mRect[x][y]=1;
	//this->ScreenFlush();
}

void Face::RemoveNode(int x,int y)
{
	mRect[x][y]=0;
	//this->ScreenFlush();
}