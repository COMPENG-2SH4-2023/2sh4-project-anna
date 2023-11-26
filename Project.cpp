#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

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
    //initialize gameMechanics object on the heap
    gameMechanics = new GameMechs();
    //intialize playerObject on the heap
    playerObject = new Player(gameMechanics);
    objPos *no_food_here = new objPos();
    playerObject->getPlayerPos(*no_food_here);
    gameMechanics->generateFood(*no_food_here); //generates snakefood, passes in player position to avoid
						//I think we then need to delete no_food_here in here?

}

void GetInput(void)
{
	
	if(MacUILib_hasChar() != 0)
	{
		gameMechanics->setInput(MacUILib_getChar());
	} 
   
}

void RunLogic(void)
{
	if(gameMechanics->getInput() != 0) //if there is usable input, run this logic
	{
		switch(gameMechanics->getInput())
		{
			case ' ': //exit
				gameMechanics->setExitTrue();
				break;
			default:
                break;
		}
	}
	//debug-use keys
    	if(gameMechanics->getInput() == 'p') //give a point
	{
		gameMechanics->incrementScore();
		gameMechanics->clearInput();
	}
	if(gameMechanics->getInput() == 'l') //set loseflag on
	{
		gameMechanics->setLoseFlag();
		gameMechanics->clearInput();
	}
	//Update player direction
        playerObject -> updatePlayerDir();
        //Move player
        playerObject -> movePlayer();

}
void DrawScreen(void)
{
    MacUILib_clearScreen();    
    char matrix[gameMechanics->getBoardSizeY()][gameMechanics->getBoardSizeX()]; //creates matrix with set board size
    objPos tempPos; // temporarory position of Player Object
    playerObject -> getPlayerPos(tempPos);
    objPos temp_food; // temporary variable to get food object
    gameMechanics->getFoodPos(temp_food); //get the position of the snake food
    for(int i = 0; i < gameMechanics->getBoardSizeY(); i++)
    {
	    for(int j = 0; j < gameMechanics->getBoardSizeX(); j++)
	    {
		    if(i == 0 || i == gameMechanics->getBoardSizeY() - 1 || j == 0 || j == gameMechanics->getBoardSizeX() - 1)
		    {
			    matrix[i][j] = '#';
		    }
            	    else if(j == tempPos.x && i == tempPos.y) //get player data for printing
            	    {
                	    matrix[i][j] = tempPos.symbol;
            	    }
		    else if(j == temp_food.x && i == temp_food.y) //get snake food data for printing
		    {
			    matrix[i][j] = temp_food.symbol;
		    }
		    else
		    {
			    matrix[i][j] = ' ';
		    }
	    }
    }

    for(int i = 0; i < gameMechanics->getBoardSizeY(); i++)
    {
	    for(int j = 0; j < gameMechanics->getBoardSizeX(); j++)
	    {
		    MacUILib_printf("%c", matrix[i][j]);
	    }
	    MacUILib_printf("\n");
    }
    MacUILib_printf("The score is %d and loseFlag is set to %d\n", gameMechanics->getScore(), gameMechanics->getLoseFlagStatus());
																  


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    delete gameMechanics;
    delete playerObject;
}
