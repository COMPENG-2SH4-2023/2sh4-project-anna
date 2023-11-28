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

void GameMechs::generateFood(objPosArrayList* blockOff)
{
	srand(time(NULL));
	int got_one = 0; // indicates if unblocked position found
	int x_candidate,y_candidate; // random x and y pos
	objPos blockPos; // position of block
	int blockSize = blockOff->getSize(); // size of player area blocked off
	int i=0;

	while(!got_one)
	{
		// Generates Random Food Position
		x_candidate = (rand() % (boardSizeX - 2))+1;
		y_candidate = (rand() % (boardSizeY - 2))+1;

		// Checks if new position same as player position
		for(i=0; i<blockSize;i++)
		{
			blockOff->getElement(blockPos,i);

			// if block matches break to generate new pos
			if(blockPos.x == x_candidate && blockPos.y == y_candidate)
			{
				break;
			}
		}

		// if no block matches: generates food
		if(i == blockSize)
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
