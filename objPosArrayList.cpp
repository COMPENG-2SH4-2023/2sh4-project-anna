#include "objPosArrayList.h"

// set default objPos Array List
objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

// destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// return size of list
int objPosArrayList::getSize()
{
    return sizeList;
}

// insert head object at head position
void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList == sizeArray) //FULL
    {
        return;
    }
    for(int i=sizeList; i>0; i--)
    {
        aList[i].setObjPos(aList[i-1]);
    }
    aList[0].setObjPos(thisPos); // sets first element to head obj
    sizeList++;
}

// insert tail object at tail position
void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray) //FULL
    {
        return;
    }
    aList[sizeList].setObjPos(thisPos);
    sizeList++;
}

// remove head object from head position
void objPosArrayList::removeHead()
{   
    if(sizeList == 0) // if no elements
    {
        return;
    }
    for(int i=0; i<=sizeList;i++)
    {
        aList[i].setObjPos(aList[i+1]);
    }
    sizeList--;
}

// remove tail object from tail position
void objPosArrayList::removeTail()
{
    if(sizeList == 0) // if no elements
    {
        return;
    }
    aList[sizeList].setObjPos(0,0,0);
    sizeList--;
}

// gets head element and sets in returnPos
void objPosArrayList::getHeadElement(objPos &returnPos)
{
    aList[0].getObjPos(returnPos);
}

// gets tail element and sets in returnPos
void objPosArrayList::getTailElement(objPos &returnPos)
{
    aList[sizeList-1].getObjPos(returnPos);
}

// gets element at given index and sets in returnPos
void objPosArrayList::getElement(objPos &returnPos, int index)
{
    aList[index].getObjPos(returnPos);
}
