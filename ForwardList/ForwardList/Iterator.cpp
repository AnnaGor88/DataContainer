//
//  Iterator.cpp
//  ForwardList
//
//  Created by Анна Горячева on 24.05.2021.
//

#include <stdio.h>
#include "Iterator.h"
#include "Element.h"

template <typename T>
Iterator<T>::Iterator(Element<T>* Temp):Temp(Temp)
{
#ifdef DEBUG
    cout << "IConstructor:\t" << this << endl;
#endif
}
template <typename T>
Iterator<T>::~Iterator()
{
#ifdef DEBUG
    cout << "IDestructor:\t" << this << endl;
#endif
}
template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    Temp=Temp->pNext;
    return *this;
}
template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator old=*this;
    Temp=Temp->pNext;
    return old;
}
template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other)const
{
    return this->Temp==other.Temp;
}
template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other)const
{
    return this->Temp!=other.Temp;
}
template<typename T>
const Element<T>* Iterator<T>:: operator->()const
{
    return Temp;
}
template<typename T>
Element<T>* Iterator<T>::operator->()
{
    return Temp;
}
template<typename T>
const T& Iterator<T>::operator*()const
{
    return Temp->Data;
}
template<typename T>
T& Iterator<T>::operator*()
{
    return Temp->Data;
}
