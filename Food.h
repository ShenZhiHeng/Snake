#ifndef FOOD_H
#define FOOD_H
#include "Face.h"
#include "Node.h"

class Food
{
private:
	Node FoodNode;
public:
	Food(Face* face);
	void Set_FoodNodeX(int x);
	void Set_FoodNodeY(int y);
	int Get_FoodNodeX();
	int Get_FoodNodeY();
	void AutoCreateFoodNode(Face* face);
};
#endif