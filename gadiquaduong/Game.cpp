#include "Game.h"

Game::Game()
{
	srand(time(NULL));
	Common::clearConsole();
	_level = 1;
	_numOfLane = 4;
	initGameData();
}

Game::~Game()
{
}
void movevehical(vector<Lane> _lane) {
	while (true){
		for (int i = 0; i < _lane.size(); i++) {
			khoathread.lock();
			_lane[i].moveLane();
			khoathread.unlock();
		}
	Sleep(10);
	}
}
void movehuman(People x) {
	while (true) {
		x.move();
	}
}
void Game::playGame()
{
	drawBoardGame();
	human.setCoords(47,26);
	human.loadImage(1);
	human.drawToScr();

	for (int i = 0; i < _lane.size(); i++)
	 	_lane[i].printLane();

	thread vehi(movevehical,_lane);
	thread humanmove(movehuman,human);
	

	vehi.join();
	humanmove.join();

}

void Game::initGameData()
{
	for (int i = 0; i < _numOfLane; i++) {
		_lane.push_back(Lane(3, i));
	}
}

void Game::drawBoardGame()
{
	int left = LEFT_GAMEBOARD, top = TOP_GAMEBOARD;
	int boxW = GAMEBOARD_WIDTH, boxH = 5;

	Common::setConsoleColor(BRIGHT_WHITE, BLACK);

	int box;
	for (int j = 0; j < boxW; j++) {
		Common::gotoXY(left + j, top - 4);
		putchar(205);
	}
	for (int j = 0; j < boxH; j++) {
		Common::gotoXY(left, top - 4 + j);
		putchar(186);
		Common::gotoXY(left + boxW, top - 4 + j);
		putchar(186);
	}

	Common::gotoXY(left, top - 4);
	putchar(201);
	Common::gotoXY(left + boxW, top - 4);
	putchar(187);

	for (int i = 0; i < _numOfLane; i++) {
		box = i * boxH;
		for (int j = 0; j < boxW; j++) {
			Common::gotoXY(left + j, top + box);
			putchar(205);
			Common::gotoXY(left + j, top + boxH + box);
			putchar(205);
		}

		for (int j = 0; j < boxH; j++) {
			Common::gotoXY(left, top + j + box);
			putchar(186);
			Common::gotoXY(left + boxW, top + j + box);
			putchar(186);
		}

		Common::gotoXY(left, top + box);
		putchar(204);
		Common::gotoXY(left + boxW, top + box);
		putchar(185);
		Common::gotoXY(left, top + boxH + box);
		putchar(204);
		Common::gotoXY(left + boxW, top + boxH + box);
		putchar(185);
	}
	Common::gotoXY(left, top);
	putchar(204);
	Common::gotoXY(left + boxW, top);
	putchar(185);

	for (int j = 0; j < boxW; j++) {
		Common::gotoXY(left + j, top + boxH * _numOfLane + 5);
		putchar(205);
	}
	for (int j = 0; j < 5; j++) {
		Common::gotoXY(left, top + boxH * _numOfLane + j);
		putchar(186);
		Common::gotoXY(left + boxW, top + boxH * _numOfLane + j);
		putchar(186);
	}

	Common::gotoXY(left, top + boxH * _numOfLane + 5);
	putchar(200);
	Common::gotoXY(left + boxW, top + boxH * _numOfLane + 5);
	putchar(188);

	Common::gotoXY(left, top + boxH * _numOfLane);
	putchar(204);
	Common::gotoXY(left + boxW, top + boxH * _numOfLane);
	putchar(185);
}

void Game::setLevel(int level)
{
	_level = level;
}

int Game::getLevel()
{
	return _level;
}
