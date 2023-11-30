#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 150000

bool exitFlag;
//other global variables:
GameMechs* gameMechanics;
Player* playerObject;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(gameMechanics->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
    gameMechanics = new GameMechs(); //initialize gameMechanics object on the heap
    playerObject = new Player(gameMechanics); //intialize playerObject on the heap

	objPosArrayList* playerBody = playerObject->getPlayerPos(); //gets list of player body segments to avoid when generating food
    	gameMechanics->generateFood(playerBody); //generates new snake food while avoiding snake body

}

void GetInput(void)
{
	
	if(MacUILib_hasChar() != 0) //if there is a valid character input from the keyboard
	{
		gameMechanics->setInput(MacUILib_getChar()); //gets the keyboard character for the gamemechanics object
	} 
   
}

void RunLogic(void)
{
	if(gameMechanics->getInput() != 0) //if there is usable input, run this logic
	{
		switch(gameMechanics->getInput())
		{
			case ' ': //this is the user key to end the game and exit
				gameMechanics->setExitTrue();
				break;
			default:
                break;
		}
	}
        playerObject -> updatePlayerDir(); //Update player direction
        playerObject -> movePlayer(); //move the player object on the board



}
void DrawScreen(void)
{
    MacUILib_clearScreen();    
    MacUILib_printf("Welcome to the Snake Feeding Frezy Game! Press w to move snake up, s for down, a for left, and d for right. To quit, press the spacebar.\n");
    bool drawn; //this flag is used in the logic routine for drawing the snake body
    char matrix[gameMechanics->getBoardSizeY()][gameMechanics->getBoardSizeX()]; //creates matrix with set board size

    objPosArrayList* playerBody = playerObject->getPlayerPos(); //new var to hold reference to whole player body
    objPos tempBody;

    objPos temp_food; // temporary variable to get food object
    gameMechanics->getFoodPos(temp_food); //get the position of the snake food

    for(int i = 0; i < gameMechanics->getBoardSizeY(); i++)
    {
	    for(int j = 0; j < gameMechanics->getBoardSizeX(); j++)
	    {
		    drawn = false; 
		    for(int k = 0; k < playerBody->getSize(); k++)
		    {
			    playerBody->getElement(tempBody, k); //checking every location for snake body segments
			    if(tempBody.x == j && tempBody.y == i)
			    {
				    matrix[i][j] = tempBody.symbol;
				    drawn = true;
				    break;
			    }
		    }

		    if(drawn) continue; //if player body was drawn don't do anything below

		    if(i == 0 || i == gameMechanics->getBoardSizeY() - 1 || j == 0 || j == gameMechanics->getBoardSizeX() - 1) //draws static border of game
		    {
			    matrix[i][j] = '#'; 
		    }
		    else if(j == temp_food.x && i == temp_food.y) //get snake food data for printing
		    {
			    matrix[i][j] = temp_food.symbol;
		    }
		    else //any place on board that does not have some other symbol should be blank
		    {
			    matrix[i][j] = ' ';
		    }
	    }
    }

    for(int i = 0; i < gameMechanics->getBoardSizeY(); i++) //this loop prints the finished matrix to the screen
    {
	    for(int j = 0; j < gameMechanics->getBoardSizeX(); j++)
	    {
		    MacUILib_printf("%c", matrix[i][j]);
	    }
	    MacUILib_printf("\n");
    }
    MacUILib_printf("Your score: %d", gameMechanics->getScore()); //show user their current score 
																  


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
	if(gameMechanics->getLoseFlagStatus() == 1 && gameMechanics->getExitFlagStatus() == 1) //this condition is met if the snake has touched itself and thus loseflag is enabled
	{
		MacUILib_clearScreen();
		MacUILib_printf("Game ended. You scored: %d", gameMechanics->getScore());
	}
	else
	{

    		MacUILib_clearScreen();    
	}
  
    MacUILib_uninit();
    delete gameMechanics; //deleting heap variables
    delete playerObject;
}
