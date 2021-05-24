//
//  Element.h
//  ForwardList
//
//  Created by Анна Горячева on 24.05.2021.
//

#ifndef Element_h
#define Element_h
#pragma once
#include <iostream>
#include<exception>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define DELIMETER "\n----------------------------------\n"
#undef DEBUG
template <typename T>class Iterator;
template <typename T>class ForwardList;
template <typename T>
class Element
{
    T Data; // Значение элемента
    Element* pNext; // Указатель на следующий элемент
    static int count;
public:
    const Element* getpNext()const;
    T getData()const;
    Element(T Data, Element<T>* pNext=nullptr);
    ~Element();
    //Element operator++;
    friend class Iterator<T>;
    friend class ForwardList<T>;
    friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};

#endif /* Element_h */
