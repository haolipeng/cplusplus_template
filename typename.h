//
// Created by Administrator on 2020\1\22 0022.
//

#ifndef CPLUSPLUS_TEMPLATE_TYPENAME_H
#define CPLUSPLUS_TEMPLATE_TYPENAME_H

#include <iostream>
using namespace std;

template <class T> class X{
    //without typename, you should get an error:
    typename T::id i;
public:
    void f() { i.g(); }
};

//id是类Y的一个嵌套类型
class Y{
public:
    class id{
    public:
        void g(){
            cout<< "Y::id::g() function called!" <<endl;
        }
    };
};

#endif //CPLUSPLUS_TEMPLATE_TYPENAME_H
