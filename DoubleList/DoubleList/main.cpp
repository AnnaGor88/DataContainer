//
//  main.cpp
//  DoubleList
//
//  Created by Анна Горячева on 28.05.2021.
//
#include <iostream>
using namespace std;

class DoubleList;
class Element
{
    int Data; // Значение элемента
    Element* pNext; // Указатель на следующий элемент
    Element* pPrew; // Указатель на предыдущий элемент
    static int count;
public:
    const Element* getpNext()const
    {
        return pNext;
    }
    int getData()const
    {
        return Data;
    }
    Element(int Data, Element* pNext=nullptr,Element* pPrew=nullptr):Data(Data),pNext(pNext),pPrew(pPrew)
    {
        count++;
    }
    ~Element()
    {
        count--;
        cout << "EDestructor:\t" << this << endl;
    }
    friend class DoubleList;
};
class DoubleList
{
    unsigned int size;
    Element* Head;
    Element* Tail;
public:
    unsigned int get_size()const
    {
        return size;;
    }
    const Element* getHead()const
    {
        return Head;
    }
    DoubleList()
    {
        this->size=0;
        this->Head=nullptr;
        cout << "DLConstructor:\t" << this << endl;
    }
    ~DoubleList()
    {
        while(Head)
        {
            //pop_front();
        }
    }
    
};

int main() {
    setlocale (LC_ALL, "");
    
    return 0;
}
