// 09_NumberOf1InBinary.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

//My answer
int NumberOf1_Solution1(int n) {
	int Count = 32;
	int NumOf1 = 0;
	while (Count--)
	{
		if (n & 1) ++NumOf1;
		n = n >> 1;
	}
	return NumOf1;
}

//解法1:移动标记1做与运算检测每一位是否为1
int NumberOf1_Solution2(int n) {
	int NumOf1 = 0;
	int flag = 1;
	while (flag)
	{
		if (n & flag) ++NumOf1;
		flag = flag << 1;
	}
	return NumOf1;
}

//解法2：有多少个1就循环多少次
int NumberOf1_Solution3(int n) {
	int NumOf1 = 0;
	while (n)
	{
		++NumOf1;
		n = n & (n-1);
	}
	return NumOf1;
}

// ====================测试代码====================
void Test(int number, unsigned int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	actual = NumberOf1_Solution3(number);
	if (actual == expected)
		printf("Solution3: Test for %p passed.\n", number);
	else
		printf("Solution3: Test for %p failed.\n", number);

	printf("\n");
}

int main(int argc, char* argv[])
{
	// 输入0，期待的输出是0
	Test(0, 0);

	// 输入1，期待的输出是1
	Test(1, 1);

	// 输入10，期待的输出是2
	Test(10, 2);

	// 输入0x7FFFFFFF，期待的输出是31
	Test(0x7FFFFFFF, 31);

	// 输入0xFFFFFFFF（负数），期待的输出是32
	Test(0xFFFFFFFF, 32);

	// 输入0x80000000（负数），期待的输出是1
	Test(0x80000000, 1);

	return 0;
}

