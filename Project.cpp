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
    gameMechanics->generateFood( ); //generates snakefood, passes in player position to avoid

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
        //Update player direction
        playerObject -> updatePlayerDir();
        //Move player
        playerObject -> movePlayer();
	
	}
	//debug-use keys
    	if(gameMechanics->getInput() == 'p')
	{
		gameMechanics->incrementScore();
		//gameMechanics->clearInput();
	}
	if(gameMechanics->getInput() == 'l')
	{
		gameMechanics->setLoseFlag();
	}

}
void DrawScreen(void)
{
    MacUILib_clearScreen();    
    //recall: there are 10 rows, i.e. i-positions or movements on the y-axis, and 20 columns, i.e. j-positions or movements on the x-axis.
    char matrix[gameMechanics->getBoardSizeY()][gameMechanics->getBoardSizeX()];
    //objPos test = objPos(4, 3, '!'); //test object with x-pos=4, y-pos =3, symbol of '!'
    objPos tempPos; // temporarory position of Player Object
    playerObject -> getPlayerPos(tempPos);
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
    //do we need to call the destructor explicitly? called automatically at end of program?
}
