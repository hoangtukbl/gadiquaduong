﻿#include "Truck.h"

Truck::Truck(int type) {
	loadImage(type);
	mX = mY = 1;
}

Truck::Truck(int type, int x, int y) {
	mX = x + LEFT_GAMEBOARD + GAMEBOARD_WIDTH;
	mY = y + TOP_GAMEBOARD;
	loadImage(type);
}

void Truck::drawToScreen() {
	for (int i = 0; i < image.size(); i++) {
		Common::gotoXY(mX, mY + i);
		cout << image[i] << endl;
	}
}

void Truck::eraseFromScreen()
{
	for (int i = 0; i < image.size(); i++) {
		Common::gotoXY(mX, mY + i);
		for (int j = 0; j < image[i].length(); j++)
			putchar(' ');
	}
}

void Truck::move()
{
}

void Truck::loadImage(int type)
{
	//Hình ảnh của obj
	string file;
	switch (type)
	{
	case 0:
		file = "ASCII\\truck1.txt";
		_height = 4;
		_width = 19;
		mSpeed = -1;
		break;
	case 1:
		file = "ASCII\\truck2.txt";
		_height = 4;
		_width = 13;
		mSpeed = -1;
		break;
	default:
		break;
	}
	ifstream in(file);
	
	string s;
	while (!in.eof()) {
		getline(in, s);
		image.push_back(s);
	}
	in.close();
}

bool Truck::checkPos() {
	if ((mX + mSpeed) > LEFT_GAMEBOARD) return true;
	return false;
}

void Truck::updatePos()
{
	if (checkPos())
		mX += mSpeed;
	else
		//mX = LEFT_GAMEBOARD + 1;
		mX = GAMEBOARD_WIDTH + _width;
}
