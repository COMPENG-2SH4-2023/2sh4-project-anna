#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200 // array size and max list size

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList; // objPos array
        int sizeList; // number of elements in list
        int sizeArray; // size of the array

    public:
        objPosArrayList(); // default constructor
        ~objPosArrayList(); // destructor

        //getters
        int getSize();
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);

        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();


};

#endif