//
//  Header2.h
//  ForwardList
//
//  Created by Анна Горячева on 21.05.2021.
//

#ifndef Header2_h
#define Header2_h
#include <iostream>
#include<exception>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define DELIMETER "\n----------------------------------\n"
#undef DEBUG
#pragma once
class Iterator
{
    Element* Temp;
public:
    Iterator(Element* Temp=nullptr);
    ~Iterator();
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& other)const;
    bool operator!=(const Iterator& other)const;
    const Element* operator->()const;
    Element* operator->();
    const int& operator*()const;
    int& operator*();
};

#endif /* Header2_h */
