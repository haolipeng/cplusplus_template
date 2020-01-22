//
// Created by Administrator on 2020\1\22 0022.
//

#ifndef CPLUSPLUS_TEMPLATE_COMMON_H
#define CPLUSPLUS_TEMPLATE_COMMON_H
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
#endif //CPLUSPLUS_TEMPLATE_COMMON_H
