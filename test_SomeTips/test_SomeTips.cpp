// test_SomeTips.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	char a[] = "ab";
	char* b = a;
	std::cout << *(b++) << std::endl; //表明表达式完了之后b才会+1
}