#include "Snake.h"
#include <conio.h>
#include <ctype.h>

Snake::Snake(Face* face)
{
	face->mRect[4][4]=1;
	face->mRect[4][5]=1;
	face->mRect[4][6]=1;
	SnakeBody.push_front(Node(4,4));
	SnakeBody.push_front(Node(4,5));
	SnakeBody.push_front(Node(4,6));
	//face->ScreenFlush();
}
int Snake::isMeetFood(Food* food,int direction)
{
	int snakehead_x=SnakeBody.front().Get_X();
	int snakehead_y=SnakeBody.front().Get_Y();
	switch(direction)
	{
	case 72://上
		if (snakehead_x-1==food->Get_FoodNodeX()&&snakehead_y==food->Get_FoodNodeY())
			return 1;
	case 80://下
		if (snakehead_x+1==food->Get_FoodNodeX()&&snakehead_y==food->Get_FoodNodeY())
			return 1;
	case 75://左
		if (snakehead_x==food->Get_FoodNodeX()&&snakehead_y-1==food->Get_FoodNodeY())
			return 1;
	case 77://右
		if (snakehead_x==food->Get_FoodNodeX()&&snakehead_y+1==food->Get_FoodNodeY())
			return 1;
	default:return 0;
	}
	return 0;
}
void Snake::EatFood(Face* face,Food* food)
{
	SnakeBody.push_front(Node(food->Get_FoodNodeX(),food->Get_FoodNodeY()));
	food->AutoCreateFoodNode(face);
}
void Snake::Move(Face* face,int direction)
{
	list<Node>::reverse_iterator ite=++SnakeBody.rbegin();
	face->RemoveNode(SnakeBody.back().Get_X(),SnakeBody.back().Get_Y());

	for (list<Node>::reverse_iterator it=SnakeBody.rbegin();ite!=SnakeBody.rend();it++,ite++)
	{
		it->Set_X(ite->Get_X());
		it->Set_Y(ite->Get_Y());
	}
	/*direction=_getch();
	while (!isascii(direction))
	{
	direction=_getch();
	}*/
	switch(direction)
	{
		case 72://上
			SnakeBody.front().Set_X(SnakeBody.front().Get_X()-1);break;
		case 80://下
			SnakeBody.front().Set_X(SnakeBody.front().Get_X()+1);break;
		case 75://左
			SnakeBody.front().Set_Y(SnakeBody.front().Get_Y()-1);break;
		case 77://右
			SnakeBody.front().Set_Y(SnakeBody.front().Get_Y()+1);break;
	}
	face->AddSnakeNode(SnakeBody.front().Get_X(),SnakeBody.front().Get_Y());
}
int Snake::Die()
{
	int snakehead_x=SnakeBody.front().Get_X();
	int snakehead_y=SnakeBody.front().Get_Y();
	if ( 0==snakehead_x || 19==snakehead_x || 0==snakehead_y || 22==snakehead_y)//碰墙
		return 1;
	for(list<Node>::iterator ite=++SnakeBody.begin();ite!=SnakeBody.end();ite++)
		if(snakehead_x==ite->Get_X() && snakehead_y==ite->Get_Y())//蛇头碰到蛇尾
			return 1;	
	return 0;

}