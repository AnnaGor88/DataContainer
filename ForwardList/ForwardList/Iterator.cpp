//
//  Iterator.cpp
//  ForwardList
//
//  Created by Анна Горячева on 21.05.2021.
//

#include <stdio.h>
#include "Header.h"
#include "Header2.h"
Iterator::Iterator(Element* Temp):Temp(Temp)
{
#ifdef DEBUG
    cout << "IConstructor:\t" << this << endl;
#endif
}
Iterator::~Iterator()
{
#ifdef DEBUG
    cout << "IDestructor:\t" << this << endl;
#endif
}
Iterator& Iterator::operator++()
{
    Temp=Temp->pNext;
    return *this;
}
Iterator Iterator::operator++(int)
{
    Iterator old=*this;
    Temp=Temp->pNext;
    return old;
}
bool Iterator::operator==(const Iterator& other)const
{
    return this->Temp==other.Temp;
}
bool Iterator::operator!=(const Iterator& other)const
{
    return this->Temp!=other.Temp;
}
const Element* Iterator::operator->()const
{
    return Temp;
}
Element* Iterator::operator->()
{
    return Temp;
}
const int& Iterator::operator*()const
{
    return Temp->Data;
}
int& Iterator::operator*()
{
    return Temp->Data;
}
