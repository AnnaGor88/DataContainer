//
//  Element.cpp
//  ForwardList
//
//  Created by Анна Горячева on 24.05.2021.
//

#include <stdio.h>
#include "Element.h"
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define DELIMETER "\n----------------------------------\n"
#undef DEBUG
template <typename T>
const Element<T>* Element<T>::getpNext()const
{
    return pNext;
}
template <typename T>
T Element<T>::getData()const
{
    return Data;
}
template <typename T>Element<T>::Element(T Data, Element<T>* pNext):Data(Data),pNext(pNext)
{
    count++;
#ifdef DEBUG
    cout << "EConstructor:\t" << this << endl;
#endif //DEBUG
}
template <typename T>
Element<T>::~Element()
{
    count--;
#ifdef DEBUG
    cout << "EDestructor:\t" << this << endl;
#endif //5DEBUG
}
//Element operator++;


template <typename T>
int Element<T>::count=0; // инициализация статической переменной
