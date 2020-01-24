//
// Created by Administrator on 2020\1\24 0024.
//

#ifndef CPLUSPLUS_TEMPLATE_CONST_USE_H
#define CPLUSPLUS_TEMPLATE_CONST_USE_H

class Complex{
public:
    Complex(double r = 0, double i = 0):re(r),im(i)
    {
    }
    Complex& operator += (const Complex&);
    double real() const { return re; }
    double imag() const { return im; }
private:
    double re;
    double im;
};

Complex &Complex::operator+=(const Complex &) {
    return <#initializer#>;
}

#endif //CPLUSPLUS_TEMPLATE_CONST_USE_H
