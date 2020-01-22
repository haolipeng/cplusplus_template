#include <iostream>
#include <cstddef>
#include <memory>
#include <vector>
#include <list>
#include "common.h"
#include "Container.h"
#include "typename.h"
using namespace std;

///////////////////////////////////技术点//////////////////////////////////////////////
//1.可以为模板的所有参数都提供默认值，但声明一个实例时必须使用一堆空的尖括号，这样编译器就知道说明了一个类模板
//2.模板参数可以是另一个模板
void test_typename()
{
    X<Y> xy;
    xy.f();
}

template <class T,template <class U, class = allocator<U> > class Seq>
void printSeq(Seq<T>& seq)
{
    //这里要求iterator是类型，所以需要加typename
    for (typename Seq<T>::iterator p = seq.begin(); p != seq.end(); p++) {
        cout<< *p <<endl;
    }
}

void test_print_stl_container()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    printSeq(v);

    list<double > lst;
    lst.push_back(1.2);
    lst.push_back(3.4);
    printSeq(lst);
}

int main() {
    //use a vector
    Container<int, vector> container;
    container.push_back(1);
    container.push_back(2);
    auto p = container.begin();
    while(p != container.end())
    {
        cout << *p++ << endl;
    }

    //use a list
    Container<int, list> lContainer;
    lContainer.push_back(3);
    lContainer.push_back(4);
    for(list<int>::iterator p2 = lContainer.begin(); p2 != lContainer.end(); p2++)
    {
        cout<< *p2 <<endl;
    }

    test_typename();

    test_print_stl_container();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}