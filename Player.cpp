#include "Player.h"

// construct player
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*'); //temp object to be used for head
    playerPosList = new objPosArrayList(); //array list for snake
    playerPosList->insertHead(tempPos); //sets the head of the snake
}

// destructor
Player::~Player()
{
    // delete any heap members here
	delete playerPosList; //only have one position list to delete
}

// return the reference to the playerPos arrray list
objPosArrayList* Player::getPlayerPos()
{
	return playerPosList;
}

// updates player direction based on user input
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

// prcesses direction, heads border, updates lose flag, and player size
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
 
    objPos currHead; //holds position information of current head
    playerPosList->getHeadElement(currHead);

    //PROCESSING DIRECTION
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
    
    //want to check if new location of currHead is the same as any elements already in snake body
	if(checkPlayerCollision()==true)
	{
		mainGameMechsRef->setLoseFlag();
		mainGameMechsRef->setExitTrue();
	}
    
    //new current head should be inserted to head of list
    playerPosList->insertHead(currHead);

    // if food consumed
    if(checkFoodConsumption() == true)
    {
        mainGameMechsRef->generateFood(playerPosList); //generate new food
	    mainGameMechsRef->incrementScore(); // increment score
    }
    else
    {
        // remove the tail 
        playerPosList->removeTail();  
    }
}

// returns bool indicating if food has bee consumed
bool Player::checkFoodConsumption()
{
    objPos currHead; //holds position information of current head
    playerPosList->getHeadElement(currHead);
    objPos currFood;
    mainGameMechsRef->getFoodPos(currFood);

    // if the snake head is not the same position as the food
    if(currHead.x == currFood.x && currHead.y == currFood.y)
    {
        return true;
    }
    return false;
}

// returns bool indicating if player has collided with itself
bool Player::checkPlayerCollision()
{
    objPos tempBody; 
    objPos currHead; //holds position information of current head
    playerPosList->getHeadElement(currHead); 

    for(int i = 1; i < playerPosList->getSize(); i++)
    {
	   playerPosList->getElement(tempBody, i);
	   if(tempBody.x == currHead.x && tempBody.y == currHead.y)
	   {
            return true;
	   }
    }
    return false;
}

