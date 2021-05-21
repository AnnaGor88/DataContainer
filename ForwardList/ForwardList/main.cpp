//
//  main.cpp
//  ForwardList
//
//  Created by Анна Горячева on 26.04.2021.
//


#include "Header.h"
#include "Header2.h"
#include "Header3.h"
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
