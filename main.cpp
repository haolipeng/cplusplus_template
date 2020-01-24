#include <iostream>
#include <cstddef>
#include <memory>
#include <vector>
#include <list>
#include "common.h"
#include "Container.h"
#include "typename.h"
#include "multi_version_min.h"
using namespace std;

///////////////////////////////////技术点//////////////////////////////////////////////
//1.可以为模板的所有参数都提供默认值，但声明一个实例时必须使用一堆空的尖括号，这样编译器就知道说明了一个类模板
//2.模板参数可以是另一个模板
// 测试typename的用法，告诉编译器此标识符是一个类型
void test_typename()
{
    X<Y> xy;
    xy.f();
}

//打印stl容器中的值
template <class T,template <class U, class = allocator<U> > class Seq>
void printSeq(Seq<T>& seq)
{
    //这里要求iterator是类型，所以需要加typename
    for (auto p = seq.begin(); p != seq.end(); p++) {
        cout<< *p <<endl;
    }
}

class Test{
public:
    void operator() ()
    {
        cout<< "void operator() ()" <<endl;
    }

    void operator() (const char* pStr)
    {
        cout<< "void operator() (const char* pStr)" <<endl;
    }
};

void test_operator()
{
    Test test;
    test();
    test("haolipeng");
    cout<<"test_operator() end"<<endl;
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

//测试通过函数参数推导出数组的维数
void test_ref_array()
{
    int a[10][20];
    init1<10, 20>(a);
    init2(a);
}

//测试不同版本的min函数
void test_multi_min_function()
{
    const char* s1 = "knights who";
    const char* s2 = "say hello";

    cout<< TEMPLATE_MIN::min(1,2) <<endl;
    cout<< TEMPLATE_MIN::min(1.0 ,2.0) <<endl;
    cout<< TEMPLATE_MIN::min(1 ,2.0) <<endl;
    cout<< TEMPLATE_MIN::min(s1, s2) <<endl;
    cout<< TEMPLATE_MIN::min<>(s1, s2) <<endl;//加上空尖括号强迫编译器使用模板，因为生成一个const char*模板来使用
}

//以stl容器为模板参数的类模板
void test_use_vector_list()
{
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
    for(int & p2 : lContainer)
    {
        cout<< p2 <<endl;
    }
}

namespace My
{
    template <class T1, class T2>
    struct pair{
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair():first(T1()), second(T2()) {

        }

        pair(const T1& a, const T2& b):first(a),second(b){

        }

        template <class U1, class U2>
        explicit pair(const pair<U1, U2>& p) :first(p.first), second(p.second) {}
    };
}

//鱼类
class Fish{

};

//鸟类
class Bird{

};

//鲫鱼
class Catfish : public Fish{

};

//麻雀
class Sparrow : public Bird{

};

//类模板的半有序
#include "partialOrder.h"
void test_partial_order()
{
    C<float,int>().f();//Primary Template
    C<int,float>().f();//T == int
    C<float,double>().f();//U == double
    C<float,float>().f();//T == U
    C<float*,float>().f();//T* used
    C<float,float*>().f();//U* used
    C<float*,int*>().f();//T* and U* used
}

int main() {
    My::pair<Fish, Bird> p2(My::pair<Catfish, Sparrow>());

    test_use_vector_list();

    test_typename();

    test_print_stl_container();

    test_biset_tostring();

    test_multi_min_function();

    test_operator();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}