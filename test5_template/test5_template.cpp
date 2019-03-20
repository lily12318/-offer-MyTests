// test5_template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

//函数模板
template <class T>
T inc(T n)
{
	return 1 + n;
}

//类模板
template<typename T2>
class test
{
public:
	test(T2 v);
	T2 getValue() { return value; }
private:
	T2 value;
};

template<typename T2>
test<T2>::test(T2 v)
{
	value = v;
}

int main()
{
	cout << inc<double>(5.5)<< endl; //实例化的模板函数
	cout << inc<int>(5.5) << endl;
	
	test<char> TestClass('a');  //实例化的模板类
	test<int> TestClass2('a');
	cout << TestClass.getValue() << endl;
	cout << TestClass2.getValue() << endl;
}

