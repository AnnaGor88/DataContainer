//
//  main.cpp
//  ForwardList
//
//  Created by Анна Горячева on 26.04.2021.
//

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
#ifdef DEBUG
        cout << "EConstructor:\t" << this << endl;
#endif //DEBUG
    }
    ~Element()
    {
        count--;
#ifdef DEBUG
        cout << "EDestructor:\t" << this << endl;
#endif //5DEBUG
    }
    //Element operator++;
    friend class Iterator;
    friend class ForwardList;
    friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

int Element::count=0; // инициализация статической переменной

class Iterator
{
    Element* Temp;
public:
    Iterator(Element* Temp=nullptr):Temp(Temp)
    {
#ifdef DEBUG
        cout << "IConstructor:\t" << this << endl;
#endif
    }
    ~Iterator()
    {
#ifdef DEBUG
        cout << "IDestructor:\t" << this << endl;
#endif
    }
    Iterator& operator++()
    {
        Temp=Temp->pNext;
        return *this;
    }
    Iterator operator++(int)
    {
        Iterator old=*this;
        Temp=Temp->pNext;
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
    const Element* operator->()const
    {
        return Temp;
    }
    Element* operator->()
    {
        return Temp;
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

class ForwardList
{
    unsigned int size;
    Element* Head; // Указатель на начальный элемент списка
public:
    
    unsigned int get_size()const
    {
        return size;;
    }
    const Element* getHead()const
    {
        return Head;
    }
    
    Iterator begin()
    {
        return Head;
    }
    Iterator end()
    {
        return nullptr;
    }
    
    //Constructors
    
    ForwardList()
    {
        this->size=0;
        this->Head=nullptr; // nullptr в Headозначает,что список пуст
        cout << "LConstructor:\t" << this << endl;
    }
    ForwardList(const initializer_list<int>& il):ForwardList()
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
    ForwardList (const ForwardList& other):ForwardList()
    {
        for(Element* Temp=other.Head; Temp; Temp=Temp->pNext)
            push_back(Temp->Data);
        cout << "LCopyConstructor:\t" << this << endl;
    }
    ForwardList(ForwardList&& other)
    {
        this->size = other.size;
        this->Head = other.Head;
        other.Head = nullptr;
        cout << "LMoveConstructor:\t" << this << endl;
    }
    ~ForwardList()
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
    
    ForwardList& operator=(const ForwardList& other)
    {
        //0.) Проверяем не является ли список самим собой
        if(this==&other)return *this;
        while(Head)pop_front(); // Очищаем список от старых значений
        for(Element* Temp=other.Head; Temp; Temp=Temp->pNext) //Копируем список
            push_back(Temp->Data);
        cout << "LCopyAssignment:\t" << this << endl;
        return *this;
    }
    ForwardList& operator=(ForwardList&& other)
    {
        while(Head)pop_front();
        this->size = other.size;
        this->Head = other.Head;
        other.Head = nullptr;
        cout << "LMoveAssignment:\t" << this << endl;
        return  *this;
    }
    
    int& operator[](int index)
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
    void push_front(int Data)
    {
//        Element* New= new Element(Data);
//        New->pNext=Head;
//        Head=New;
        Head=new Element(Data,Head);
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
       
        if(Head==nullptr)return;
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
    
    void erase (int index)
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
    
    void print()const
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
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
    ForwardList cat=left;
    for(const Element* Temp=right.getHead(); Temp; Temp=Temp->getpNext())
        cat.push_back(Temp->getData());
    return cat;
}

//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define BASE_CHECK
#ifdef BASE_CHECK
//#define ADDING_ELEMENTS_CHECK
//#define REMOVING_CHECK
#endif
int main()
{
    setlocale(LC_ALL,"");
#ifdef BASE_CHECK
    int n;
    int index;
    cout << "Введите размер списка: "; cin >> n;
    cout << DELIMETER << endl;
    ForwardList list;
    for(int i=0; i<n; i++)
    {
        list.push_front(rand()%100);
        //list.push_back(rand()%100);
    }
#endif
//    list.print();
//    list.pop_front();
//    list.print();
//    list.pop_back();
//    list.print();
//    cout << DELIMETER << endl;
//    list.print();
//    cout << DELIMETER << endl;
    cout << "List ready"<<endl;
#ifdef REMOVING_CHECK
//    cout << "Введите  индекс удаляемого значения: "; cin >> index;
//    list.erase(index);
//    list.print();
    cout << DELIMETER << endl;
    int value;
    cout << "Введите добавляемое значение: "; cin >> value;
    list.push_front(222);
    list.print();
#endif
#ifdef COPY_METHODS_CHECK
    int n;
    cout << "Введите размер списка: "; cin>>n;
    ForwardList list;
    for(int i=0;i<n;i++)
    {
        list.push_back(rand()%100);
    }
    list=list;
    list.print();
    cout << DELIMETER << endl;
    //ForwardList list2=list; //CopyConstructor
    ForwardList list2; // DefaultConstructor
    list2=list; // CopyAssignment
    list2.print();
#endif
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
#ifdef OPERATOR_PLUS_CHECK
    ForwardList list1;
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(8);
    list1.push_back(13);
    list1.push_back(21);
    
    ForwardList list2;
    list2.push_back(34);
    list2.push_back(55);
    list2.push_back(89);
    list2.push_back(144);
    cout << DELIMETER  << endl;
    ForwardList list3;
    list3= list1+list2;
    list3.print();
    cout << DELIMETER  << endl;
#endif

    
    int arr[]={3,5,8,12,21};
//    for(int i:arr)
//    {
//        cout << i << tab;
//    }
//    cout << endl;
    ForwardList list={3,5,8,12,21};
    for(int i:list)
    {
        cout << i << tab;
    }
    cout << endl;
   // cout << sizeof(Element) << endl;
    
//    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
//    {
//        cout << arr[i] << "\t";
//    }
//    cout << endl;
 //   ForwardList list = {3,5,8,13,21};
   // list.print();
//    try
//    {
//        for(int i=0;i<list.get_size();i++)
//        {
//            list[i] = rand() % 100;
//        }
//        for(int i=0;i<10;i++)
//        {
//           cout << list[i] <<tab;
//        }
//    }
//    catch(const std::exception& e)
//    {
//        cerr << e.what() << endl; // Метод what возвр сообщение об ошибке
//    }
//    ForwardList list;
//    for(int i=0; i<5; i++)
//    {
//        list.push_front(rand()%100);
//    }
//    list.print();
//    ForwardList list3=list;
    
    return 0;
}
