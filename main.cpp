#include <iostream>
#include <cstddef>
#include <memory>
#include <vector>
#include <list>
using namespace std;

//默认模板参数
template <class T, size_t N = 100>
class Stack{
    T data[N];
    size_t count;
public:
    void push(const T& t)
    {

    }
};

//Array容器类型
template <class T>
class Array{
    enum { INIT = 10 };
    T* data;
    size_t  capacity;
    size_t  count;
public:
    Array()
    {
        count = 0;
        capacity = INIT;
        data = new T[capacity];
    }

    virtual ~Array() {
        count = 0;
        capacity = INIT;
        delete[] data;
    }

    void push_back(const T& t)
    {
        if(count == capacity)
        {
            //容量扩大一倍
            size_t newCap = 2 * capacity;
            T*  newData = new T[capacity];
            for (size_t i = 0; i < count; ++i) {
                newData[i] = data[i];
            }

            delete []data;
            data = newData;
            capacity = newCap;
        }
        data[count++] = t;
    }

    void pop_back()
    {
        if(count > 0)
            count--;
    }

    T* begin() { return data; }
    T* end() { return data + count; }
};

//想将第二个参数传递为标准容器，如list，vector
template <class T, template <class U, class = allocator<U> > class Seq >
class Container{
    Seq<T> seq;
public:
    void append(const T& t)
    {
        seq.push_back(t);
    }

    //容器中的begin和end函数返回的是迭代器iterator类型
    typename Seq<T>::iterator begin() { return seq.begin(); }
    typename Seq<T>::iterator end() { return seq.end(); }
};

//1.可以为模板的所有参数都提供默认值，但声明一个实例时必须使用一堆空的尖括号，这样编译器就知道说明了一个类模板
//2.模板参数可以是另一个模板
int main() {
    Container<int, vector> container;
    container.append(1);
    container.append(2);
    auto p = container.begin();
    while(p != container.end())
    {
        cout << *p++ << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}