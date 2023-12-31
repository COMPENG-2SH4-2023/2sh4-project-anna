#include "GameMechs.h"

GameMechs::GameMechs() //this constructor creates a game of default board size
{
	boardSizeX = 30;
	boardSizeY = 15;
	exitFlag = false;
	loseFlag = false;
	score = 0;
	input = 0;

}

GameMechs::GameMechs(int boardX, int boardY) //this constructor creates a game with a specified size and
{
	boardSizeX = boardX;
	boardSizeY = boardY;
	exitFlag = false;
	loseFlag = false;
	score = 0;
	input = 0;


}

// do you need a destructor?
GameMechs::~GameMechs(){} //yes


bool GameMechs::getExitFlagStatus() //returns exit flag status
{
	return exitFlag;

}

char GameMechs::getInput() //returns the current input
{
	return input;
}

int GameMechs::getBoardSizeX() //returns board size in the x-direction
{
	return boardSizeX;

}

int GameMechs::getBoardSizeY() //returns board size in the y-directions
{
	return boardSizeY;

}


void GameMechs::setExitTrue() //sets exit to true so the game ends
{
	exitFlag = 1;

}

void GameMechs::setInput(char this_input) //sets the input
{
	input = this_input;

}

void GameMechs::clearInput() //clears the input
{
	input = 0;

}

int GameMechs::getScore() //returns the score
{
	return score;
}

void GameMechs::incrementScore() //adds one to the score each call
{
	score++;
}

bool GameMechs::getLoseFlagStatus() //returns whehter the game has been lost
{
	return loseFlag;
}

void GameMechs::setLoseFlag() //sets the flag to 1 for a lost game
{
	loseFlag = 1;
}

void GameMechs::generateFood(objPosArrayList* blockOff) //takes in the list of snake body segments to avoid, and generates a location for new snake food that excludes the snake body locations
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

void GameMechs::getFoodPos(objPos &returnPos) //returns the current position of the food 
{
	returnPos = foodPos;

}
