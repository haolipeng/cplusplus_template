//
// Created by Administrator on 2020\1\23 0023.
//

#ifndef CPLUSPLUS_TEMPLATE_MULTI_VERSION_MIN_H
#define CPLUSPLUS_TEMPLATE_MULTI_VERSION_MIN_H

#include <cstring>
#include <iostream>
using namespace std;

namespace TEMPLATE_MIN
{
    template <typename T> const T& min(const T& a, const T& b)
    {
        cout << "const T& min(const T& a, const T& b)"<<endl;
        return (a < b)? a: b;
    }

    const char* min(const char* a, const char* b)
    {
        cout << "char* min(const char* a, const char* b)"<<endl;
        return (strcmp(a,b) < 0)? a: b;
    }

    double min(double x, double y)
    {
        cout << "double min(double x, double y)"<<endl;
        return (x < y)? x:y;
    }
}
#endif //CPLUSPLUS_TEMPLATE_MULTI_VERSION_MIN_H
