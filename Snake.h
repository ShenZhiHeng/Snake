#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include "Face.h"
#include "Node.h"
#include "Food.h"
using namespace std;

class Snake
{
private:
	list<Node> SnakeBody;
public:
	Snake(Face* face);
	int isMeetFood(Food* food,int direction);
	void EatFood(Face* face,Food* food);
	void Move(Face* face,int direction);
	int Die();
	int getSize()const{return SnakeBody.size();}
};
#endif