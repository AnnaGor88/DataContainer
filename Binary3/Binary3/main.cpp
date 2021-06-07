//
//  main.cpp
//  Binary3
//
//  Created by Анна Горячева on 02.06.2021.
//

#include <iostream>
using namespace std;
#define tab "\t"
#undef DEBUG
class Tree
{
  class Element
    {
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data,Element* pLeft = nullptr, Element* pRight = nullptr)
        {
            this->Data=Data;
            this->pLeft=pLeft;
            this->pRight=pRight;
#ifdef DEBUG
            cout << "EConstructor:\t" << this << endl;
#endif
        }
        ~Element()
        {
#ifdef DEBUG
            cout <<"EDestructor:\t" << this << endl;
#endif
        }
        bool is_leaf()const
        {
            return pLeft==pRight;
        }
        friend class Tree;
    }*Root; // Указатель на корневой элемент
public:
    Element* getRoot()
    {
        return Root;
    }
    const Element* getRoot()const
    {
        return Root;
    }
    Tree() :Root(nullptr)
    {
        cout << "TConstructor:\t" << this << endl;
    }
    Tree(const initializer_list<int>& il) :Tree()
    {
        cout << typeid(il.begin()).name()<< endl;
        for(int const* it=il.begin(); it!=il.end();it++)
        {
            Insert(*it);
        }
    }
    Tree (const Tree& other) :Tree()
    {
        copyTree(other.Root);
        cout <<"CopyConstructor:\t" << this << endl;
    }
    Tree& operator==(const Tree& other)
    {
        if(this==&other)return *this;
        clear();
        copyTree(other.Root);
        cout <<"CopyAssignment:\t" << this << endl;
        return *this;
    }
    ~Tree()
    {
        clear(Root);
        cout <<"TDestructor:\t" << this << endl;
    }
    void Insert(const int& Data)
    {
        Insert(Data,Root);
    }
    void erase(const int& Data)
    {
        erase(Data,Root);
    }
    int minValue()
    {
        return minValue(Root);
    }
    int maxValue()
    {
        return maxValue(Root);
    }
    int size()
    {
        return size(Root);
    }
    int sum()
    {
        return sum(Root);
    }
    double avg()
    {
        return avg(Root);
    }
    void print()
    {
        print(Root);
        cout << endl;
    }
    void clear()
    {
        clear(Root);
    }
    
private:
    void copyTree(Element* Root)
    {
        if(Root==nullptr)return;
        Insert(Root->Data);
        copyTree(Root->pLeft);
        copyTree(Root->pRight);
    }
    void Insert(const int& Data, Element* Root) // Здесь Element* Root - это указатель на ветку дерево (поддерево)
    {
       if(this->Root==nullptr)
       {
           this->Root= new Element(Data);
       }
        if(Root==nullptr)return;
        if(Data < Root->Data)
        {
            if(Root->pLeft==nullptr) // Если текущий элемент(Root) не имеет левого потомка
            {
                Root->pLeft= new Element(Data); // Создаем его
            }
            else // В противном случае идем дальше
            {
                Insert(Data, Root->pLeft);
            }
        }
        if(Data>Root->Data)
        {
//            if(Root->pRight==nullptr)  //Если текущий элемент (Root) не имеет правого потомка
//            {
//                Root->pRight = new Element(Data);
//            }
//            else
//            {
//                Insert(Data, Root->pRight);
//            }
            if(Root->pRight)Insert(Data, Root->pRight);
            else Root->pRight = new Element(Data);
        }
    }
    void erase(const int& Data, Element*& Root)
    {
        if(Root==nullptr)return;
        erase(Data,Root->pLeft);
        erase(Data,Root->pRight);
        if(Data==Root->Data)
        {
            if(Root->is_leaf())
            {
                delete Root;
                Root=nullptr;
            }
            else
            {
                if(Root->pLeft)
                {
                    Root->Data = maxValue(Root->pLeft);
                    erase(maxValue(Root->pLeft),Root->pLeft);
                    
                }
                else
                {
                    Root->Data = minValue(Root->pRight);
                    erase(minValue(Root->pRight),Root->pRight);
                }
            }
        }
//        if(Root)erase(Data,Root->pLeft);
//        if(Root)erase(Data,Root->pRight);
    }
    
    int minValue(Element* Root)
    {
//        if(Root->pLeft==nullptr)return Root->Data;
//        else return minValue(Root->pLeft);
        return Root->pLeft==nullptr?Root->Data:minValue(Root->pLeft);
    }
    int maxValue(Element* Root)
    {
//        if(Root->pRight==nullptr)return Root->Data;
//        else return maxValue(Root->pRight);
        return Root->pRight?maxValue(Root->pRight): Root->Data;
    }
    int size(Element* Root)
    {
        //Количество элементов дерева
//        if(Root==nullptr)return 0;
//        else return size(Root->pLeft)+size(Root->pRight)+1;
        return Root==nullptr?0:size(Root->pLeft)+size(Root->pRight)+1;
    }
    int sum(Element* Root)
    {
        return Root?sum(Root->pLeft)+sum(Root->pRight)+Root->Data : 0;
    }
    double avg(Element* Root)
    {
        return double(sum(this->Root))/size(this->Root);
    }
    void print(Element* Root)
    {
        if(Root==nullptr)return;
        print(Root->pLeft);
        cout << Root << tab << Root->Data << endl;
        print(Root->pRight);
    }
    void clear(Element*& Root)
    {
        if(Root==nullptr)return;
        clear(Root->pLeft);
        clear(Root->pRight);
        delete Root;
        Root=nullptr;
    }
};

int main() {
    setlocale (LC_ALL, "");
    //int n; // Размер дерева
    //cout << "введите количество элементов: "; cin >> n;
    //Tree tree;
//    for(int i=0; i<n; i++)
//    {
//        tree.Insert(rand()%100);
//    }
    Tree tree = {50,25,16,32,64,55,77};
//    tree.Insert(50);
//    tree.Insert(25);
//    tree.Insert(16);
//    tree.Insert(32);
//    tree.Insert(11);
//    tree.Insert(18);
//    tree.Insert(30);
//    tree.Insert(36);
//
//    tree.Insert(64);
//    tree.Insert(55);
//    tree.Insert(80);
//    tree.Insert(54);
//    tree.Insert(58);
//    tree.Insert(77);
//    tree.Insert(85);
    Tree tree2;
    tree=tree;
    tree2.print();
    tree.print();
    cout << endl;
    cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
    cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
    cout << "Количество элементов: " << tree.size()<< endl;
    cout << "Сумма элементов дерева: " << tree.sum()<< endl;
    cout << "Среднее арифметическое элементов дерева: " << tree.avg()<< endl;
    int value;
    cout << "Введите удаляемое значение: "; cin >> value;
    tree.erase(value);
    tree.print();
    tree.clear();
    cout << tree.getRoot()<<endl;
    tree.print();
    return 0;
}
