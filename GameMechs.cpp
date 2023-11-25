#include "GameMechs.h"

GameMechs::GameMechs()
{
	boardSizeX = 30;
	boardSizeY = 15;
	exitFlag = false;
	loseFlag = false;
	score = 0;
	input = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
	boardSizeX = boardX;
	boardSizeY = boardY;
	exitFlag = false;
	loseFlag = false;
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

bool GameMechs::getLoseFlagStatus()
{
	return loseFlag;
}

void GameMechs::setLoseFlag()
{
	loseFlag = 1;
}

void GameMechs::generateFood(objPos blockOff)
{
	int x_bit[boardSizeX - 2] = {0}; 
	int y_bit[boardSizeY - 2] = {0};	
	srand(time(NULL));
	int got_one = 0;
	while(!got_one)
	{
		int x_candidate = (rand() % (boardSizeX - 3)) + 1;
		int y_candidate = (rand() % (boardSizeY - 3)) + 1;
		if(blockOff.x == x_candidate && blockOff.y == y_candidate)
		{
			continue; // go back to start of loop and try again
		}
		else
		{
			foodPos.x = x_candidate;
			foodPos.y = y_candidate;
			foodPos.symbol = 'o';
			got_one = 1;
		}
	}

}

void GameMechs::getFoodPos(objPos &returnPos)
{
	returnPos = foodPos;

}
