cplusplus_template

typename知识点
1.typename的目的是通知编译器，被限定的标识符应该被解释为一个类型，而不是创建一个类型！
typename Seq<T>::iterator It;
想创建一个类型：
typedef typename Seq<T>::iterator It;

2.用typename代替class

3.class template,function template,member template

4.模板特化
模板特化的类型必须出现在函数名后紧跟的尖括号中，泛化 vs 特化
特化的版本的个数是任意的。
标准库中的vector显示特化
template<class T,class Allocator = allocator<T> >
class vector {...};
偏特化后：
template<> class vector<bool, allocator<bool> > {...};

5.偏特化（半特化）
vector<bool>限定了对象类型（bool类型），但并没有指定参数allocator类型。
下面是一个实际的vector<bool>声明
template<class Allocator> class vector<bool, Allocator>;
template关键字后面和class关键字后面的尖括号里都是非空的参数列表。所以用户可以
提供一个自定义的allocator类型，即使参数列表中的类型bool是不变的。

6.类模板的半有序
选用哪个类模板进行实例化的规则，类似于函数模板中的半有序规则--应该选择“特化程度最高”的模板


