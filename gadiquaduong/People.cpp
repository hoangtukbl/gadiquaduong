#include "People.h"

People::People()
{
}

People::~People()
{
}

void People::setCoords(int x, int y) {
	this->mX = x;
	this->mY = y;
}
int People::getmX() {
	return this->mX;
}
int People::getmY() {
	return this->mY;
}
pair<int, int> People::getCoords(int, int) {
	return pair<int, int>(mX, mY);
}

void People::drawToScr() {
	for (int i = 0; i < image.size(); i++) {
		Common::gotoXY(this->getmX(), this->getmY() + i);
		cout << this->image[i] <<endl;
	}
}
void People::eraseFromScr() {
	for (int i = 0; i < image.size(); i++) {
		Common::gotoXY(this->getmX(), this->getmY() + i);
		for (int j = 0; j < image[i].length(); j++)
			putchar(' ');
	}
}


void People::Up() {
	this->mY -= 5;
}
void People::Down() {
	this->mY += 5;
}
void People::Left() {
	this->mX -= 4;
}
void People::Right() {
	this->mX += 4;
}
void People::move() {
    int _input = Common::getConsoleInput();
	switch (_input)
	{
	case 2:{
		this->eraseFromScr();
		this->Up();
		this->drawToScr();
		break;}
	case 3:{
		this->eraseFromScr();
		this->Left();
		this->drawToScr();
		break;}
	case 4:{
		this->eraseFromScr();
		this->Right();
		this->drawToScr();
		break;}
	case 5:{
		this->eraseFromScr();
		this->Down();
		this->drawToScr();
		break;}
	default:
		break;
	}
}
void People::loadImage(int type) {
	string file;
	if (type == 1) {
		file = "ASCII\\life.txt";
		_height = 3;
		_width = 3;
	}
	ifstream fin(file);
	string s;
	while (!fin.eof()) {
		getline(fin, s);
		this->image.push_back(s);
	}
}