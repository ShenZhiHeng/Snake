#ifndef NODE_H
#define NODE_H

struct Node
{
private:
	int X;
	int Y;
public:
	Node(){}
	Node(int x,int y):X(x),Y(y){}
	void Set_X(int x)
	{
		this->X=x;
	}
	int Get_X()
	{
		return X;
	}
	void Set_Y(int y)
	{
		this->Y=y;
	}
	int Get_Y()
	{
		return Y;
	}
};
#endif