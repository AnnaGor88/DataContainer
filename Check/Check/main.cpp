//
//  main.cpp
//  Check
//
//  Created by Анна Горячева on 07.05.2021.
//

#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define DELIMETER "\n----------------------------------\n"
#undef DEBUG

class Element
{
    int Data; // Значение элемента
    Element* pNext; // Указатель на следующий элемент
    static int count;
public:
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
    ForwardList(const ForwardList& other):ForwardList(other.Head)
    {
//        this->size=other.size;
//        this->Head=other.Head;
       // copy(this->Head,this->size,other.Head);
        cout << "CopyConstructor:\t" << this << endl;
    }
    ForwardList(ForwardList& other)
    {
        this->size=other.size;
        this->Head=other.Head;
        cout << "MoveConstructor:\t"<<this<< endl;
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
        for(Element* Temp=Head;Temp;Temp=Temp->pNext)
        cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
        cout << DELIMETER << endl;
        cout << "В списке " << size << " элементов\n";
        cout << "Общее количество " << Element::count << " элементов\n";
        cout << DELIMETER << endl;
    }
};


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
#endif
    
//    int arr[]={3,5,8,12,21};
//    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
//    {
//        cout << arr[i] << "\t";
//    }
//    cout << endl;
    
   // ForwardList list = {3,5,8,13,21};
  //  list.print();
//    for(int i=0;i<list.getsize();i++)
//    {
//        cout << list[i] << \t;
//    }
    ForwardList list;
    for(int i=0; i<5; i++)
    {
        list.push_front(rand()%100);
    }
    list.print();
    ForwardList list3=list;
    return 0;
}

