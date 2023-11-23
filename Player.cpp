#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    char input = mainGameMechsRef -> getInput();
    switch(input) 
    {
        case 'w':
        case 'W':
            if(myDir != DOWN)
            {
                myDir = UP;
            }     
            break;
        case 's':
        case 'S':
            if(myDir != UP)
            {
                myDir = DOWN;
            }    
            break;
        case 'd':
        case 'D':
            if(myDir != LEFT)
            {
                myDir = RIGHT;
            }    
            break;
        case 'a':
        case 'A':
            if(myDir != RIGHT)
            {
                myDir = LEFT;
            }    
            break; 
        default:
            break;
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    //PROCESSING DIRECTION
    switch(myDir)
    {
        case UP:
            playerPos.y = playerPos.y -1;
            break;
        case DOWN:
            playerPos.y = playerPos.y +1;
            break;
        case RIGHT:
           playerPos.x = playerPos.x + 1;
            break;
        case LEFT:
            playerPos.x = playerPos.x - 1;
            break;
        case STOP:
            break;
    }

    //HEAD BORDER
    // border sizes
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    if(playerPos.y == 0)
    {
        playerPos.y = boardY-2;
    }
    else if(playerPos.y == boardY-1)
    {
        playerPos.y = 1;
    }
    else if(playerPos.x == 0)
    {
        playerPos.x = boardX-2;
    }
    else if(playerPos.x == boardX-1)
    {
        playerPos.x = 1;
    }

}

