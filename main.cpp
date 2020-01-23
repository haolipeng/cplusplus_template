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

#include <bitset>
#include <string>
template <class charT, size_t N>
basic_string<charT> bitsetToString(const bitset<N>& bs){
    return bs. template to_string<charT, char_traits<charT>, allocator<charT> >();
}

void test_biset_tostring()
{
    bitset<10> bs;
    bs.set(1);
    bs.set(5);
    cout<< bs <<endl;

    string s = bitsetToString<char>(bs);
    cout << s <<endl;
}

//推导出数组的维数
template <size_t R, size_t C, typename T>
void init1(T a[R][C])
{
    for (size_t i= 0; i < R; i++) {
        for(size_t j = 0; j < C; j++)
        {
            a[i][j] = T();
        }
    }
}

//a声明是一个二维数组的引用
template <size_t R, size_t C, typename T>
void init2(T (&a) [R][C])
{
    for (size_t i= 0; i < R; i++) {
        for(size_t j = 0; j < C; j++)
        {
            a[i][j] = T();
        }
    }
}

void test_ref_array()
{
    int a[10][20];
    init1<10, 20>(a);
    init2(a);
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

    test_biset_tostring();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}