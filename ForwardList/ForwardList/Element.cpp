//
//  Element.cpp
//  ForwardList
//
//  Created by Анна Горячева on 21.05.2021.
//

#include <stdio.h>
#include "Header.h"
#include "Header2.h"
int Element::count=0; // инициализация статической переменной
const Element* Element::getpNext()const
{
    return pNext;
}
int Element::getData()const
{
    return Data;
}
Element::Element(int Data, Element* pNext):Data(Data),pNext(pNext)
{
    count++;
#ifdef DEBUG
    cout << "EConstructor:\t" << this << endl;
#endif //DEBUG
}
Element::~Element()
{
    count--;
#ifdef DEBUG
    cout << "EDestructor:\t" << this << endl;
#endif //5DEBUG
}
