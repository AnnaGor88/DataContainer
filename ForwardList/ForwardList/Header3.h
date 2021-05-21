//
//  Header3.h
//  ForwardList
//
//  Created by Анна Горячева on 21.05.2021.
//

#ifndef Header3_h
#define Header3_h
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
class ForwardList
{
    unsigned int size;
    Element* Head; // Указатель на начальный элемент списка
public:
    
    unsigned int get_size()const;
    const Element* getHead()const;
    Iterator begin();
    Iterator end();
    ForwardList();
    ForwardList(const initializer_list<int>& il);
    ForwardList (const ForwardList& other);
    ForwardList(ForwardList&& other);
    ~ForwardList();
    ForwardList& operator=(const ForwardList& other);
    ForwardList& operator=(ForwardList&& other);
    int& operator[](int index);
    void push_front(int Data);
    void push_back(int Data);
    void insert (int index, int Data);
    void pop_front();
    void pop_back();
    void erase (int index);
    void print()const;
};


#endif /* Header3_h */
