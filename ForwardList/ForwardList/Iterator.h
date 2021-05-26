//
//  Iterator.h
//  ForwardList
//
//  Created by Анна Горячева on 24.05.2021.
//

#ifndef Iterator_h
#define Iterator_h
#pragma once
//#include <iostream>
//using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;
//template <typename T>class Iterator;
//template <typename T>class ForwardList;
//template <typename T>class Element;

#include"Element.h"


template <typename T>
class Iterator
{
    Element<T>* Temp;
public:
    Iterator(Element<T>* Temp=nullptr);
    ~Iterator();
    Iterator& operator++();
    Iterator<T> operator++(int);
    bool operator==(const Iterator<T>& other)const;
    bool operator!=(const Iterator<T>& other)const;
    const Element<T>* operator->()const;
    Element<T>* operator->();
    const T& operator*()const;
    T& operator*();
};

#endif /* Iterator_h */
