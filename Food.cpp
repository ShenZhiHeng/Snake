#pragma once
#include "Food.h"
#include <stdlib.h>
#include <time.h>

Food::Food(Face* face)
{
	srand((unsigned)time(NULL));
	do//使食物产生在面板里
	{
		FoodNode.Set_X(rand()%18+1);//获得1到18之间的随机数
		FoodNode.Set_Y(rand()%21+1);//获得1到21之间的随机数
	}while(FoodNode.Get_X()==0 || FoodNode.Get_X()==19 || FoodNode.Get_Y()==0 ||FoodNode.Get_Y()==22);
	face->DrawFood(FoodNode.Get_X(),FoodNode.Get_Y());
}
void Food::Set_FoodNodeX(int x)
{
	FoodNode.Set_X(x);
}
void Food::Set_FoodNodeY(int y)
{
	FoodNode.Set_Y(y);
}
int Food::Get_FoodNodeX()
{
	return FoodNode.Get_X();
}
int Food::Get_FoodNodeY()
{
	return FoodNode.Get_Y();
}
void Food::AutoCreateFoodNode(Face* face)
{
	srand((unsigned)time(NULL));
	do//使食物产生在面板里
	{
		FoodNode.Set_X(rand()%18+1);//获得1到18之间的随机数
		FoodNode.Set_Y(rand()%21+1);//获得1到21之间的随机数
	}while(FoodNode.Get_X()==0 || FoodNode.Get_X()==19 || FoodNode.Get_Y()==0 ||FoodNode.Get_Y()==22);
	face->DrawFood(FoodNode.Get_X(),FoodNode.Get_Y());
}