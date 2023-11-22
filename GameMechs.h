#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
	bool loseFlag; //added
	int score; //added	
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); //added 
        bool getExitFlagStatus();
        void setExitTrue();
	void getLoseFlagStatus(); //aded
	void setLoseFlag(); //added
        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();
	int getScore(); //added
     	void incrementScore(); //added 

};

#endif
