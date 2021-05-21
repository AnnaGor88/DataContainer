//
//  Header.h
//  ForwardList
//
//  Created by Анна Горячева on 19.05.2021.
//

#ifndef Header_h
#define Header_h
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
class ForwardList;
class Element
{
    int Data; // Значение элемента
    Element* pNext; // Указатель на следующий элемент
    static int count;
public:
    const Element* getpNext()const;
    int getData()const;
    Element(int Data, Element* pNext=nullptr);
    ~Element();
    
    //Element operator++;
    friend class Iterator;
    friend class ForwardList;
    friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};


#endif /* Header_h */
