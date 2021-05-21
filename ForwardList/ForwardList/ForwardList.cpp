//
//  ForwardList.cpp
//  ForwardList
//
//  Created by Анна Горячева on 19.05.2021.
//

#include <stdio.h>
#include "Header.h"
#include "Header2.h"
#include "Header3.h"

unsigned int ForwardList::get_size()const
{
    return size;;
}
const Element* ForwardList::getHead()const
{
    return Head;
}

Iterator ForwardList::begin()
{
    return Head;
}
Iterator ForwardList::end()
{
    return nullptr;
}

//Constructors

ForwardList::ForwardList()
{
    this->size=0;
    this->Head=nullptr; // nullptr в Headозначает,что список пуст
    cout << "LConstructor:\t" << this << endl;
}
ForwardList::ForwardList(const initializer_list<int>& il):ForwardList()
{
    //begin()возвращает итератор на начало контейнера
    //end()возвращает итератор на конец контейнера
    cout << typeid(il.begin()).name()<< endl;
//        for(const int* it = il.begin(); it != il.end(); it++)
//        {
//            push_back(*it);
//        }
    for(int i:il)
    {
        push_back(i);
    }
    cout << "IlConstructor:\t" << this << endl;
}
ForwardList::ForwardList (const ForwardList& other):ForwardList()
{
    for(Element* Temp=other.Head; Temp; Temp=Temp->pNext)
        push_back(Temp->Data);
    cout << "LCopyConstructor:\t" << this << endl;
}
ForwardList::ForwardList(ForwardList&& other)
{
    this->size = other.size;
    this->Head = other.Head;
    other.Head = nullptr;
    cout << "LMoveConstructor:\t" << this << endl;
}
ForwardList::~ForwardList()
{
    /*while(Head!=nullptr)
    {
        Element* New=Head->pNext;
        delete Head;
        Head=New;
    }*/
    while(Head)pop_front();
        //pop_back();//very slow
    cout << "LDestructor:\t" << this << endl;
}


//    Operators:

ForwardList& ForwardList::operator=(const ForwardList& other)
{
    //0.) Проверяем не является ли список самим собой
    if(this==&other)return *this;
    while(Head)pop_front(); // Очищаем список от старых значений
    for(Element* Temp=other.Head; Temp; Temp=Temp->pNext) //Копируем список
        push_back(Temp->Data);
    cout << "LCopyAssignment:\t" << this << endl;
    return *this;
}
ForwardList& ForwardList::operator=(ForwardList&& other)
{
    while(Head)pop_front();
    this->size = other.size;
    this->Head = other.Head;
    other.Head = nullptr;
    cout << "LMoveAssignment:\t" << this << endl;
    return  *this;
}

int& ForwardList::operator[](int index)
{
    if(index>=size)throw std::out_of_range("Out of range");
    Element* Temp=Head;
    for(int i=0;i<index;i++)
    {
        Temp=Temp->pNext;
    }
    return Temp->Data;
}

// Adding elements:
void ForwardList::push_front(int Data)
{
//        Element* New= new Element(Data);
//        New->pNext=Head;
//        Head=New;
    Head=new Element(Data,Head);
    size++;
}
void ForwardList::push_back(int Data)
{
    if(Head==nullptr)
    {
        push_front(Data);
        return;
    }
    Element* New= new Element(Data);
    Element* Temp=Head;
    while(Temp->pNext != nullptr)
    {
        Temp=Temp->pNext;
    }
    Temp->pNext=New;
    size++;
}

void ForwardList::insert (int index, int Data)
{
    
    if(index>Element::count)return;
    if(index==0)
    {
        push_front(Data);
        return;;
    }
    else
    {
        Element* New= new Element(Data);
        Element* Temp=Head;
        for(int i=0;i<index-1;i++)
           Temp=Temp->pNext;
        New->pNext=Temp->pNext;
        Temp->pNext=New;
    }
    size++;
}

// Removing elements:

void ForwardList::pop_front()
{
   
    if(Head==nullptr)return;
    //1.Запоминаем адрес удаляемого элемента
    Element* erase_element=Head;
    // 2.Исключаем элемент из списка
    Head=Head->pNext;
    //3.Удаляем элемент из памяти
    delete erase_element;
    size--;
}
void ForwardList::pop_back()
{
    if(Head==nullptr)return;
    if(Head->pNext==nullptr)
    {
        pop_front();
        return;
    }
    Element* Temp=Head;
    while( Temp->pNext->pNext!= nullptr) //Доходим до предпоследнего элемента
    {
        Temp = Temp->pNext;
    }
    delete Temp->pNext;//Удаляем последний элемент из пвмяти
    Temp->pNext=nullptr; // говорим,что это конец списка
    size--;
}

void ForwardList::erase (int index)
{
    if(index>=size)return;
    if(index==0)
    {
        pop_front();
        return;;
    }
    if(index==size-1)
    {
        pop_back();
        return;
    }
    Element* Temp=Head;
    for(int i=0;i<index-1;i++)      //Понимаю,что капец какая кривая функция,хоть и работает,но через одно место
       Temp=Temp->pNext;
    Element* erase_element=Temp->pNext;
    Temp->pNext=Temp->pNext->pNext;
    delete erase_element;
    size--;
}
// Methods

void ForwardList::print()const
{
//        // Для того,чтобы ходить по списку нужны: итератор и цикл
//        Element* Temp = Head; // Temp - итератор. Итератор - указатель,при помощи которого можно получить доступ к элементам структуры данных
//        while(Temp != nullptr)
//        {
//            cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
//            Temp = Temp->pNext; //Переход на следующий элемент
//        }
//        for(Element* Temp=Head;Temp;Temp++)//Temp=Temp->pNext)
//        cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
//        cout << DELIMETER << endl;
    for(Iterator Temp=Head; Temp != nullptr;Temp++)
        //cout << Temp->Data << tab << Temp->pNext << endl;
        cout << *Temp <<tab;
    cout << endl;
    cout << "В списке " << size << " элементов\n";
    cout << "Общее количество " << Element::count << " элементов\n";
    cout << DELIMETER << endl;
}

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
    ForwardList cat=left;
    for(const Element* Temp=right.getHead(); Temp; Temp=Temp->getpNext())
        cat.push_back(Temp->getData());
    return cat;
}
