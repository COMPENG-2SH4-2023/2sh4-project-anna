#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}
void DrawScreen(void)
{
    MacUILib_clearScreen();    
    //recall: there are 10 rows, i.e. i-positions or movements on the y-axis, and 20 columns, i.e. j-positions or movements on the x-axis.
    char matrix[10][20];
    objPos test = objPos(4, 3, '!'); //test object with x-pos=4, y-pos =3, symbol of '!'
    for(int i = 0; i < 10; i++)
    {
	    for(int j = 0; j < 20; j++)
	    {
		    if(i == 0 || i == 9 || j == 0 || j == 19)
		    {
			    matrix[i][j] = '#';
		    }
		    else if(j == test.x && i == test.y)
		    {
			    matrix[i][j] = test.symbol;
		    }
		    else
		    {
			    matrix[i][j] = ' ';
		    }
	    }
    }

    for(int i = 0; i < 10; i++)
    {
	    for(int j = 0; j < 20; j++)
	    {
		    MacUILib_printf("%c", matrix[i][j]);
	    }
	    MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
