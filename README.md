cplusplus_template

typename知识点
1.typename的目的是通知编译器，被限定的标识符应该被解释为一个类型，而不是创建一个类型！
typename Seq<T>::iterator It;
想创建一个类型：
typedef typename Seq<T>::iterator It;

2.用typename代替class

3.class template,function template,member template
4.模板特化
