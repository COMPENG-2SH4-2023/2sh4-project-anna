#include "objPosArrayList.h"
#include <iostream>

using namespace std;

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
    cout << "CONSTRUCTOR" << endl;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    cout << "DELETE" << endl;
}

int objPosArrayList::getSize()
{
    cout << "get size: " << sizeList << endl;
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    for(int i=sizeList; i>0; i--)
    {
        aList[i].setObjPos(aList[i-1]);
    }
    aList[0].setObjPos(thisPos); // sets first element to head obj
    sizeList++;
    cout << "HEAD ADDED" << endl;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray) //FULL
    {
        cout << "size list == size array" << endl;
        return;
    }
    aList[sizeList].setObjPos(thisPos);
    sizeList++;
    cout << "TAIL ADDED" << endl;
}

void objPosArrayList::removeHead()
{
    for(int i=0; i<=sizeList;i++)
    {
        aList[i].setObjPos(aList[i+1]);
    }
    sizeList--;
    cout << "HEAD REMOVED" << endl;
}

void objPosArrayList::removeTail()
{
    aList[sizeList].setObjPos(0,0,0);
    sizeList--;
    cout << "TAIL REMOVED" << endl;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    aList[0].getObjPos(returnPos);
    cout << "GET HEAD" <<  endl;
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    aList[sizeList-1].getObjPos(returnPos);
    cout <<"sizeList: " << sizeList << endl;
    cout << "GET TAIL" <<  endl;
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    aList[index].getObjPos(returnPos);
    cout << "GET ELEMENT" <<  endl;
}