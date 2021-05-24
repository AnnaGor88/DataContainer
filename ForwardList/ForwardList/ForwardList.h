//
//  ForwardList.h
//  ForwardList
//
//  Created by Анна Горячева on 24.05.2021.
//

#ifndef ForwardList_h
#define ForwardList_h
#pragma once
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
template <typename T>class Iterator;
template <typename T>class Element;
template <typename T>
class ForwardList
{
    unsigned int size;
    Element<T>* Head; // Указатель на начальный элемент списка
public:
    
    unsigned int get_size()const;
    const Element<T>* getHead()const;
    Iterator<T> begin();
    Iterator<T> end();
    ForwardList();
    ForwardList(const initializer_list<T>& il);
    ForwardList (const ForwardList<T>& other);
    ForwardList(ForwardList<T>&& other);
    ~ForwardList();
    ForwardList<T>& operator=(const ForwardList<T>& other);
    ForwardList<T>& operator=(ForwardList<T>&& other);
    T& operator[](int index);
    void push_front(T Data);
    void push_back(T Data);
    void insert (int index, T Data);
    void pop_front();
    void pop_back();
    void erase (int index);
    void print()const;
};

#endif /* ForwardList_h */
