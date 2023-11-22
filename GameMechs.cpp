#include "GameMechs.h"

GameMechs::GameMechs()
{
	boardSizeX = 30;
	boardSizeY = 15;
	exitFlag = false;
	loseFlag = true;
	score = 0;
	input = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
	boardSizeX = boardX;
	boardSizeY = boardY;
	exitFlag = false;
	loseFlag = true;
	score = 0;
	input = 0;


}

// do you need a destructor?
GameMechs::~GameMechs(){}


bool GameMechs::getExitFlagStatus()
{
	return exitFlag;

}

char GameMechs::getInput()
{
	return input;
}

int GameMechs::getBoardSizeX()
{
	return boardSizeX;

}

int GameMechs::getBoardSizeY()
{
	return boardSizeY;

}


void GameMechs::setExitTrue()
{
	exitFlag = 1;

}

void GameMechs::setInput(char this_input)
{
	input = this_input;

}

void GameMechs::clearInput()
{
	input = 0;

}

int GameMechs::getScore()
{
	return score;
}

void GameMechs::incrementScore()
{
	score++;
}
