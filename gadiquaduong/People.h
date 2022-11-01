#pragma once
#include "Common.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <thread>
#include <queue>
#include <iostream>

class People {
protected:
	short mX;
	short mY;
	vector<string> image;
	short _height, _width;
public:
	People();
	~People();
	int getmX();
	int getmY();
	void setCoords(int x, int y);
	pair<int, int> getCoords(int, int);
	virtual void drawToScr();
	virtual void eraseFromScr();
	virtual void move();
	//void loadImage(int type);
	virtual void loadImage(int type);
	virtual void Up();
	virtual void Down();
	virtual void Left();
	virtual void Right();

};
