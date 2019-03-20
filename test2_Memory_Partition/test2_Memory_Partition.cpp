// test2_Memory_Partition.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int k = 1; //全局变量——全局（静态）存储区
int main()
{
	int i = 1; //局部变量———栈
	char *j; //局部变量——栈？
	static int m = 1; //静态变量——全局（静态）存储区
	const char* n = "hello"; //变量n位于栈上，其内容为地址，指向“hello”所在内存。"hello"在文字常量区，此时只有文字区一份拷贝；而语句“char a[] = "hello"”，a是位于栈上的6个元素，并将“hello”拷贝到它所占内存中，故栈贺文字常量区各有一份拷贝
	printf("栈区地址为：0X%x\n", &i); //i所在地址为此时栈的第一个地址

	j = (char *)malloc(2);
	printf("堆区地址为0X%x\n", j);
	free(j);
	printf("堆区地址为：0X%x\n", j);//此时j为空指针，还会指向堆的首地址吗? A:free(j)之后只是内存被释放，j还是指向那块内存
	printf("全局变量地址为：0X%x\n", &k);
	printf("静态变量地址为：0X%x\n", &m);
	printf("文字常量区地址为：0X%x\n", n);
	printf("程序区地址为：0X%x\n", &main);

	return 0;
}
