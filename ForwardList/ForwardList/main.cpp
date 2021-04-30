//
//  main.cpp
//  ForwardList
//
//  Created by Анна Горячева on 26.04.2021.
//

#include <iostream>
using namespace std;

#define tab "\t"
#define DELIMETER "\n----------------------------------\n"

class Element
{
    int Data; // Значение элемента
    Element* pNext; // Указатель на следующий элемент
    static int count;
public:
    Element(int Data, Element* pNext=nullptr):Data(Data),pNext(pNext)
    {
        count++;
        cout << "EConstructor:\t" << this << endl;
    }
    ~Element()
    {
        count--;
        cout << "EDestructor:\t" << this << endl;
    }
    friend class ForwardList;
};

int Element::count=0; // инициализация статической переменной

class ForwardList
{
    unsigned int size;
    Element* Head; // Указатель на начальный элемент списка
public:
    ForwardList()
    {
        this->size=0;
        this->Head=nullptr; // nullptr в Headозначает,что список пуст
        cout << "LConstructor:\t" << this << endl;
    }
    ~ForwardList()
    {
        cout << "LDestructor:\t" << this << endl;
    }
    
    // Adding elements:
    void push_front(int Data)
    {
        Element* New= new Element(Data);
        New->pNext=Head;
        Head=New;
        size++;
    }
    void push_back(int Data)
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
    
    void insert (int index, int Data)
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
    
    void pop_front()
    {
        //1.Запоминаем адрес удаляемого элемента
        Element* erase_element=Head;
        // 2.Исключаем элемент из списка
        Head=Head->pNext;
        //3.Удаляем элемент из памяти
        delete erase_element;
        size--;
    }
    void pop_back()
    {
        Element* Temp=Head;
        while( Temp->pNext->pNext!= nullptr) //Доходим до предпоследнего элемента
        {
            Temp = Temp->pNext;
        }
        delete Temp->pNext;//Удаляем последний элемент из пвмяти
        Temp->pNext=nullptr; // говорим,что это конец списка
        size--;
    }
    
    void erase (int index)
    {
        if(index>Element::count)return;
        if(index==0)
        {
            pop_front();
            return;;
        }
        Element* Temp=Head;
        for(int i=0;i<index-2;i++)      //Понимаю,что капец какая кривая функция,хоть и работает,но через одно место
           Temp=Temp->pNext;
        delete Temp->pNext;
        Temp->pNext=Temp->pNext->pNext;
        size--;
    }
    // Methods
    
    void print()const
    {
        // Для того,чтобы ходить по списку нужны: итератор и цикл
        Element* Temp = Head; // Temp - итератор. Итератор - указатель,при помощи которого можно получить доступ к элементам структуры данных
        while(Temp != nullptr)
        {
            cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
            Temp = Temp->pNext; //Переход на следующий элемент
        }
        cout << DELIMETER << endl;
        cout << "В списке " << size << " элементов\n";
        cout << "Общее количество " << Element::count << " элементов\n";
        cout << DELIMETER << endl;
    }
    
};



//#define ADDING_ELEMENTS_CHECK
int main()
{
    setlocale(LC_ALL,"");
    int n;
    int index;
    cout << "Введите размер списка: "; cin >> n;
    cout << DELIMETER << endl;
    ForwardList list;
    for(int i=0; i<n; i++)
    {
       // list.push_front(rand()%100);
        list.push_back(rand()%100);
    }
//    list.print();
//    list.pop_front();
//    list.print();
//    list.pop_back();
//    list.print();
    cout << DELIMETER << endl;
    list.print();
    cout << DELIMETER << endl;
    cout << "Введите  индекс удаляемого значения: "; cin >> index;
    list.erase(index);
    list.print();
    cout << DELIMETER << endl;
    int value;
#ifdef ADDING_ELEMENTS_CHECK
    cout << "Введите  индекс добавляемого значения: "; cin >> index;
    cout << "Введите добавляемое значение: "; cin >> value;
    //list.push_back(value);
    list.insert(index,value);
    list.print();
    
    ForwardList list2;
    cout << "Введите размер списка: "; cin >> n;
    for(int i=0;i<n;i++)
    {
        list2.push_back(rand()%100);
    }
    list2.print();
#endif
    return 0;
}
