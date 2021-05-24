//
//  ForwardList.cpp
//  ForwardList
//
//  Created by Анна Горячева on 24.05.2021.
//

#include <stdio.h>
#include "Element.h"
#include "ForwardList.h"

#define tab "\t"
#define DELIMETER "\n----------------------------------\n"
#undef DEBUG
template <typename T>class Iterator;
template <typename T>class Element;

template <typename T>
unsigned int ForwardList<T>::get_size()const
{
    return size;;
}
template <typename T>
const Element<T>* ForwardList<T>::getHead()const
{
    return Head;
}
template <typename T>
Iterator<T> ForwardList<T>::begin()
{
    return Head;
}
template <typename T>
Iterator<T> end()
{
    return nullptr;
}

//Constructors
template <typename T>
ForwardList<T>::ForwardList()
{
    this->size=0;
    this->Head=nullptr; // nullptr в Headозначает,что список пуст
    cout << "LConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::ForwardList(const initializer_list<T>& il):ForwardList()
{
    //begin()возвращает итератор на начало контейнера
    //end()возвращает итератор на конец контейнера
    cout << typeid(il.begin()).name()<< endl;
//        for(const int* it = il.begin(); it != il.end(); it++)
//        {
//            push_back(*it);
//        }
    for(T i:il)
    {
        push_back(i);
    }
    cout << "IlConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::ForwardList (const ForwardList<T>& other):ForwardList()
{
    for(Element<T>* Temp=other.Head; Temp; Temp=Temp->pNext)
        push_back(Temp->Data);
    cout << "LCopyConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::ForwardList(ForwardList<T>&& other)
{
    this->size = other.size;
    this->Head = other.Head;
    other.Head = nullptr;
    cout << "LMoveConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::~ForwardList()
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
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
    //0.) Проверяем не является ли список самим собой
    if(this==&other)return *this;
    while(Head)pop_front(); // Очищаем список от старых значений
    for(Element<T>* Temp=other.Head; Temp; Temp=Temp->pNext) //Копируем список
        push_back(Temp->Data);
    cout << "LCopyAssignment:\t" << this << endl;
    return *this;
}
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)
{
    while(Head)pop_front();
    this->size = other.size;
    this->Head = other.Head;
    other.Head = nullptr;
    cout << "LMoveAssignment:\t" << this << endl;
    return  *this;
}
template <typename T>
T& ForwardList<T>::operator[](int index)
{
    if(index>=size)throw std::out_of_range("Out of range");
    Element<T>* Temp=Head;
    for(int i=0;i<index;i++)
    {
        Temp=Temp->pNext;
    }
    return Temp->Data;
}

// Adding elements:
template <typename T>
void ForwardList<T>::push_front(T Data)
{
//        Element* New= new Element(Data);
//        New->pNext=Head;
//        Head=New;
    Head=new Element<T>(Data,Head);
    size++;
}
template <typename T>
void ForwardList<T>::push_back(T Data)
{
    if(Head==nullptr)
    {
        push_front(Data);
        return;
    }
    Element<T>* New= new Element<T>(Data);
    Element<T>* Temp=Head;
    while(Temp->pNext != nullptr)
    {
        Temp=Temp->pNext;
    }
    Temp->pNext=New;
    size++;
}
template <typename T>
void ForwardList<T>::insert (int index, T Data)
{
    
    if(index>Element<T>::count)return;
    if(index==0)
    {
        push_front(Data);
        return;;
    }
    else
    {
        Element<T>* New= new Element<T>(Data);
        Element<T>* Temp=Head;
        for(int i=0;i<index-1;i++)
           Temp=Temp->pNext;
        New->pNext=Temp->pNext;
        Temp->pNext=New;
    }
    size++;
}

// Removing elements:
template <typename T>
void ForwardList<T>::pop_front()
{
   
    if(Head==nullptr)return;
    //1.Запоминаем адрес удаляемого элемента
    Element<T>* erase_element=Head;
    // 2.Исключаем элемент из списка
    Head=Head->pNext;
    //3.Удаляем элемент из памяти
    delete erase_element;
    size--;
}
template <typename T>
void ForwardList<T>::pop_back()
{
    if(Head==nullptr)return;
    if(Head->pNext==nullptr)
    {
        pop_front();
        return;
    }
    Element<T>* Temp=Head;
    while( Temp->pNext->pNext!= nullptr) //Доходим до предпоследнего элемента
    {
        Temp = Temp->pNext;
    }
    delete Temp->pNext;//Удаляем последний элемент из пвмяти
    Temp->pNext=nullptr; // говорим,что это конец списка
    size--;
}
template <typename T>
void ForwardList<T>::erase (int index)
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
    Element<T>* Temp=Head;
    for(int i=0;i<index-1;i++)      //Понимаю,что капец какая кривая функция,хоть и работает,но через одно место
       Temp=Temp->pNext;
    Element<T>* erase_element=Temp->pNext;
    Temp->pNext=Temp->pNext->pNext;
    delete erase_element;
    size--;
}
// Methods
template <typename T>
void ForwardList<T>::print()const
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
    for(Iterator<T> Temp=Head; Temp != nullptr;Temp++)
        //cout << Temp->Data << tab << Temp->pNext << endl;
        cout << *Temp <<tab;
    cout << endl;
    cout << "В списке " << size << " элементов\n";
    cout << "Общее количество " << Element<T>::count << " элементов\n";
    cout << DELIMETER << endl;
}

template <typename T>
ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
    ForwardList<T> cat=left;
    for(const Element<T>* Temp=right.getHead(); Temp; Temp=Temp->getpNext())
        cat.push_back(Temp->getData());
    return cat;
}
