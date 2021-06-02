//
//  main.cpp
//  List
//
//  Created by Анна Горячева on 28.05.2021.
//

#include <iostream>
using namespace std;
#define tab "\t"
#define delimiter "\n------------------------------------------\n"
#undef DEBUG

class List
{
    class Element
    {
        int Data;
        Element* pPrew;
        Element* pNext;
    public:
        Element(int Data, Element* pNext=nullptr,Element* pPrew=nullptr)
                {
            this->Data=Data;
            this->pNext=pNext;
            this->pPrew=pPrew;
#ifdef DEBUG
            cout << "EConstructor:\t" << this << endl;
#endif
        }
                ~Element()
                {
#ifdef DEBUG
            cout << "EDestructor:\t" << this << endl;
#endif
        }
        friend class List;
        friend List operator+(const List& left, const List& right);
        friend class Iterator;
    };
    
    Element* Head;
    Element* Tail;
    unsigned int size;
public:
    class ReverseIterator
    {
        Element* Temp;
    public:
        ReverseIterator(Element* Temp=nullptr) :Temp(Temp)
        {
#ifdef DEBUG
            cout << "RITConstructor:\t" << this << endl;
#endif
        }
        ~ReverseIterator()
        {
#ifdef DEBUG
            cout << "RITDestructor:\t" << this << endl;
#endif
        }
        // Operators
        ReverseIterator operator++(int)
        {
            cout << "PostFixIncrement:\t" << this << endl;
            ReverseIterator old = *this;
            Temp=Temp->pPrew;
            return old;
        }
        ReverseIterator& operator++()
        {
            Temp=Temp->pPrew;
            cout << "PreFixIncrement:\t" << this << endl;
            return *this;
        }
        ReverseIterator& operator--()
        {
            Temp=Temp->pNext;
            return *this;;
        }
        ReverseIterator operator--(int)
        {
            ReverseIterator old=*this;
            Temp=Temp->pNext;
            return old;
        }
        bool operator==(const ReverseIterator& other)const
        {
            return this->Temp==other.Temp;
        }
        bool operator!=(const ReverseIterator& other)const
        {
            return this->Temp!=other.Temp;
        }
        const int& operator*()const
        {
            return Temp->Data;
        }
        int& operator*()
        {
            return Temp->Data;
        }
    };
    ReverseIterator rbegin()
    {
        return Tail;
    }
    const ReverseIterator rbegin()const
    {
        return Tail;
    }
    ReverseIterator rend()
    {
        return nullptr;
    }
   const  ReverseIterator rend()const
    {
        return nullptr;
    }
    class Iterator
    {
        Element* Temp;
    public:
        Iterator(Element* Temp=nullptr) :Temp(Temp)
        {
#ifdef DEBUG
            cout << "ITConstructor:\t" << this << endl;
#endif
        }
        ~Iterator()
        {
#ifdef DEBUG
            cout << "ITDestructor:\t" << this << endl;
#endif
        }
        // Operators
        Iterator operator++(int)
        {
            cout << "PostFixIncrement:\t" << this << endl;
            Iterator old = *this;
            Temp=Temp->pNext;
            return old;
        }
        Iterator& operator++()
        {
            Temp=Temp->pNext;
            cout << "PreFixIncrement:\t" << this << endl;
            return *this;
        }
        Iterator& operator--()
        {
            Temp=Temp->pPrew;
            return *this;;
        }
        Iterator operator--(int)
        {
            Iterator old=*this;
            Temp=Temp->pPrew;
            return old;
        }
        bool operator==(const Iterator& other)const
        {
            return this->Temp==other.Temp;
        }
        bool operator!=(const Iterator& other)const
        {
            return this->Temp!=other.Temp;
        }
        const int& operator*()const
        {
            return Temp->Data;
        }
        int& operator*()
        {
            return Temp->Data;
        }
    };
    Iterator begin()
    {
        return Head;
    }
    const Iterator begin()const
    {
        return Head;
    }
    Iterator end()
    {
        return nullptr;
    }
   const  Iterator end()const
    {
        return nullptr;
    }
    List()
    {
        Head=Tail=nullptr;
        size=0;
        cout << "LConstructor:\t" << this << endl;
    }
    List (const initializer_list<int>&il):List()
    {
        for(const int* it = il.begin(); it!=il.end(); it++)
        {
            push_back(*it);
        }
    }
    List(const List& other):List()
    {
        for(Element* Temp = other.Head; Temp; Temp=Temp->pNext)
        {
            push_back(Temp->Data);
        }
        cout << "CopyConstructor:\t" << this << endl;
    }
    List& operator=(List&& other)
    {
        while(Head)pop_front();
        this->size = other.size;
        this->Head = other.Head;
        this->Tail = other.Tail;
        other.Head = other.Tail = nullptr;
        cout << "LMoveAssignment:\t" << this << endl;
        return *this;
    }
    List(List&& other)
    {
        this->size = other.size;
        this->Head = other.Head;
        this->Tail = other.Tail;
        other.Head = other.Tail = nullptr;
        cout << "LMoveConstructor:\t" << this << endl;
    }
    List (int size)
    {
        for(int i=0; i<size; i++)
        {
            push_front(NULL);
        }
    }
    ~List()
    {
        while(Tail)
        {
            pop_front();
        }
        cout << "LDestructor:\t" << this << endl;
    }
    // Adding elements
    void push_front(int Data)
    {
       
        if(Head==nullptr && Tail == nullptr)
        {
            Head=Tail=new Element(Data);
            size++;
            return;
        }
        // Head = new Element(Data,Head);
//        New->pNext = Head;
//        Head->pPrew=New;
//        Head=New;
        Head = Head->pPrew = new Element(Data,Head);
        size++;
    }
    void print_reverse()
    {
        for(Element* Temp=Tail; Temp; Temp=Temp->pPrew)
        {
            cout << Temp << endl << Temp->pPrew << tab << Temp->Data << tab << Temp->pNext << endl;
        }
        cout << "Количество элементов списка: " << size << endl;
    }
    
    // Operators
    
    List& operator=(const List& other)
    {
        if(this==&other)return *this;
        while(Head)pop_front();
        for(Element* Temp = other.Head; Temp; Temp=Temp->pNext)
        {
            push_back(Temp->Data);
        }
        cout << "CopyAssignment:\t" << this << endl;
        return *this;
    }
    void push_back(int Data)
    {
        if(Head == nullptr && Tail == nullptr)
        {
            Head=Tail=new Element(Data);
            size++;
            return;
        }
//        Element* New = new Element(Data);
//        New->pPrew=Tail;
//        Tail->pNext=New;
//        Tail=New;
        Tail=Tail->pNext = new Element (Data, nullptr, Tail);
        size++;
    }
    
    // Removing elements:
    void pop_front()
    {
        if(Head == Tail)
        {
            delete Head;
            Head=Tail=nullptr;
            size--;
            return;
        }
        Head = Head->pNext;
        delete Head->pPrew;
        Head->pPrew = nullptr;
        size--;
    }
    void pop_back()
    {
        if(Head == Tail)
        {
            delete Head;
            Head=Tail=nullptr;
            size--;
            return;
        }
        Tail= Tail->pPrew;
        delete Tail->pNext;
        Tail->pNext = nullptr;
        size --;
    }
    void insert (int index, int Data)
    {
        if(index>size)return;
        if(index==size)
        {
            push_back(Data);
            return;
        }
        if(index==0)
        {
            push_front(Data);
            return;;
        }
        Element* Temp;
        if(index<size/2)
        {
            Temp=Head;
            for(int i=0; i<index;i++)
                Temp = Temp->pNext;
        }
        else
        {
            Temp=Tail;
            for(int i=0; i<size-index-1; i++)
                Temp= Temp->pPrew;
        }
//        Element* New = new Element(Data);
//        New->pNext=Temp;
//        New->pPrew=Temp->pPrew;
//        Temp->pPrew->pNext=New;
//        Temp->pPrew=New;
        Temp->pPrew=Temp->pPrew->pNext = new Element (Data,Temp,Temp->pPrew);
        size++;
            }
    void erase(int index)
    {
        
        if(index==0)
        {
            pop_front();
            return;
        }
        if(index==size-1)
        {
            pop_back();
            return;
        }
        if(index>=size)
        {
            return;
        }
           Element* Temp;
        if(index<size/2)
        {
            Temp=Head;
            for(int i=0; i<index;i++)
                Temp=Temp->pNext;
        }
        else
        {
            Temp=Tail;
        for(int i=0; i<size-index-1;i++)
            Temp=Temp->pPrew;
        }
        Temp->pPrew->pNext=Temp->pNext;
        Temp->pNext->pPrew=Temp->pPrew;
        delete Temp;
        size--;
    }
    //Methods
    void print()
    {
        for(Element* Temp=Head; Temp; Temp=Temp->pNext)
        {
            cout << Temp << endl << Temp->pPrew << tab << Temp->Data << tab << Temp->pNext << endl;
        }
        cout << "Количество элементов списка: " << size << endl;
    }
    friend List operator+(const List& left, const List& right);
};

List operator+(const List& left, const List& right)
{
    List cat=left;
    for(List::Element* Temp=right.Head;Temp; Temp=Temp->pNext)
        cat.push_back(Temp->Data);
    for(List::Iterator it = right.begin(); it!=right.end(); it++)
    {
        cat.push_back(*it);
    }
//    for(int i:right)cat.push_back(i);
    return cat;
}

//#define BASE_CHECK
//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
#define RITERATOR_CHECK
//#define ITERATOR_CHECK
int main() {
    setlocale (LC_ALL, "");
#ifdef BASE_CHECK
    int n;
    cout << "Введите размер списка: "; cin >> n;
    List list;
    for (int i=0; i<n; i++)
    {
        list.push_back(rand()%100);
    }
    list.print();
//    cout << delimiter << endl;
//    list.print_reverse();
//    cout << delimiter << endl;
//    list.pop_front();
//    list.print();
//    list.print_reverse();
//    cout << delimiter << endl;
    int index;
    int value;
    cout << "Введите индекс добавляемого : " ;cin>>index;
    cout << "Введите число: " ;cin>>value;
    list.insert(index,value);
    list.print();
    list.print_reverse();
    cout << delimiter << endl;
    cout << "Введите индекс удаляемого элемента: " ;cin>>index;
    list.erase(index);
    list.print();
    list.print_reverse();
#endif
#ifdef COPY_METHODS_CHECK
    List list;
    list.push_back(3);
    list.push_back(5);
    list.push_back(8);
    list.push_back(13);
    list.push_back(21);
    list=list;
    list.print();
    List list2 = list;  // CopyConstructor
    list2.print();
    list2.print_reverse();
    List list3;
    list3.print();
    list3.print_reverse();
#endif
#ifdef OPERATOR_PLUS_CHECK
    List list1 = { 3, 5, 8, 13, 21};
//    list1.print();
//    list1.print_reverse();
    List list2 = {34,55,89};
    cout << delimiter << endl;
//    List list3 = list1 + list2; // MoveConstructor
    List list3;
    list3=list1+list2;
    cout << delimiter << endl;
    list3.print();
#endif
#ifdef ITERATOR_CHECK
    List list = {3,5,8,13,21};
    for (int i:list)
    {
        cout << i << tab;
    }
    cout << endl;
    for(List::Iterator it = list.begin(); it!=list.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
#endif
#ifdef RITERATOR_CHECK
    List list = {3,5,8,13,21};
    for (int i:list)
    {
        cout << i << tab;
    }
    cout << endl;
    for(List::ReverseIterator it = list.rbegin(); it!=list.rend(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
#endif
    return 0;
}
