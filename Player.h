#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef); // constructor
        ~Player(); // destructor

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
        bool checkPlayerCollision();
	 
    private:
        objPosArrayList *playerPosList;   // list of player pos objects       
        enum Dir myDir;
    
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif
