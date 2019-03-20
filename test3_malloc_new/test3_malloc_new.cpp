#include "stdio.h"
#include "pch.h"
#include <iostream>

int main()
{
	//检测错误的时间不同
	//int* p1 = new float[2]; //编译时指出错误
	int *p2 = (int*)malloc(3 * sizeof(float));  //编译时无法指出错误
}
