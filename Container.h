//
// Created by Administrator on 2020\1\22 0022.
//

#ifndef CPLUSPLUS_TEMPLATE_CONTAINER_H
#define CPLUSPLUS_TEMPLATE_CONTAINER_H
#include <memory>
using namespace std;

//想将第二个参数传递为标准容器，如list，vector
//内部模板的第1个参数使用U,是因为标准序列容器的分配器必须使用与序列容器中包含对象的类型相同的类型对自己进行参数化
template <class T, template <class U, class = allocator<U> > class Seq >
class Container{
    Seq<T> seq;
public:
    void push_back(const T& t)
    {
        seq.push_back(t);
    }

    //容器中的begin和end函数返回的是迭代器iterator类型
    typename Seq<T>::iterator begin() { return seq.begin(); }
    typename Seq<T>::iterator end() { return seq.end(); }
};
#endif //CPLUSPLUS_TEMPLATE_CONTAINER_H
