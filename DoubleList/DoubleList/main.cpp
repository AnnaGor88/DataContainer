//
//  main.cpp
//  DoubleList
//
//  Created by Анна Горячева on 28.05.2021.
//
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
    Element(int Data, Element* pNext=nullptr):Data(Data),pNext(pNext)
    {
        count++;
    }
    ~Element()
    {
        count--;
//        cout << "EDestructor:\t" << this << endl;
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
    DoubleList()
    {
        this->size=0;
        this->Head=nullptr; // nullptr в Headозначает,что список пуст
       // cout << "DLConstructor:\t" << this << endl;
    }
    ~DoubleList()
    {
        while(Head)
        {
            Tail=Head->pNext;
            delete Head;
            Head=Tail;
        }
    }
};

#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "");
    
    return 0;
}
