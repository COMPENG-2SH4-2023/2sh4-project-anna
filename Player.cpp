#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*'); //temp object to be used for head
    playerPosList = new objPosArrayList(); //array list for snake
    playerPosList->insertHead(tempPos); //sets the head of the snake

    //for debugging: insert another 4 segments
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    // delete any heap members here
	delete playerPosList; //only have one position list to delete
}

objPosArrayList* Player::getPlayerPos()
{
	return playerPosList;
    
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
    
    objPos currHead; //holds position information of current head
    playerPosList->getHeadElement(currHead);

    switch(myDir)
    {
        case UP:
            currHead.y--;
	    break;
        case DOWN:
            currHead.y++; 
            break;
        case RIGHT:
            currHead.x++;
	    break;
        case LEFT:
            currHead.x--; 
            break;
        case STOP:
            break;
    }

    //HEAD BORDER
    // border sizes
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    if(currHead.y == 0)
    {
        currHead.y = boardY-2;
    }
    else if(currHead.y == boardY-1)
    {
        currHead.y = 1;
    }
    else if(currHead.x == 0)
    {
        currHead.x = boardX-2;
    }
    else if(currHead.x == boardX-1)
    {
        currHead.x = 1;
    }
    //new current head should be inserted to head of list
    playerPosList->insertHead(currHead);

    playerPosList->getHeadElement(currHead);
    objPos currFood;
    mainGameMechsRef->getFoodPos(currFood);

    // if the snake head is not the same position as the food
   if(currHead.x != currFood.x || currHead.y != currFood.y)
   {
    //then remove the tail 
    playerPosList->removeTail();  
   }

}

