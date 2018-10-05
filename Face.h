#ifndef FACE_H
#define FACE_H

class Face
{
public:
	int mRect[20][23];
public:
	Face();
	void DrawFood(int x,int y);
	void AddSnakeNode(int x,int y);
	void RemoveNode(int x,int y);
	void ScreenFlush();
};
#endif