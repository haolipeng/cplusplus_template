//
// Created by Administrator on 2020\1\24 0024.
//

#ifndef CPLUSPLUS_TEMPLATE_PARTIALORDER_H
#define CPLUSPLUS_TEMPLATE_PARTIALORDER_H
#include <iostream>
using namespace std;

template <class T, class U> class C{
public:
    void f() { cout <<"Primary Template"<<endl;}
};

template <class U> class C<int, U>{
public:
    void f() { cout <<"T == int" <<endl;}
};

template <class T> class C<T, double >{
public:
    void f() { cout <<"U == double" <<endl;}
};

template <class T, class U> class C<T*, U>{
public:
    void f() {cout << "T* used"<<endl; }
};

template <class T, class U> class C<T, U*>{
public:
    void f() {cout << "U* used"<<endl; }
};

template <class T, class U> class C<T*, U*>{
public:
    void f() { cout<< "T* and U* used" <<endl; }
};

template <class T>
class C<T, T>
{
public:
    void f() { cout<< "T == U"<<endl; }
};

#endif //CPLUSPLUS_TEMPLATE_PARTIALORDER_H
