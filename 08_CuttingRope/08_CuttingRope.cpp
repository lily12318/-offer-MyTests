// 08_CuttingRope.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

class Solution {
public:
	//动态规划
	int maxProductAfterCutting_solution1(int length)
	{
		_ASSERT(length > 0);
		if (length == 1) return 0;
		if (length == 2) return 1;
		if (length == 3) return 2;

		int* Product = new int[length];
		Product[1] = 1;
		Product[2] = 2;
		Product[3] = 3;
		
		for (int i = 4; i <= length; ++i)
		{
			int Max = 0;
			int Temp = 0;
			for (int k = 1; k < i; ++k)
			{
				Temp = Product[k] * Product[i - k];
				if (Max < Temp) Max = Temp;
			}
			Product[i] = Max;
		}
		return Product[length];
	}

	//贪婪法 当n>=5时, 2*(n-2) >= n, 3*(n-3) >= n, 3*(n-3) >= 2*(n-2)始终成立。所以，当剩余的绳子长度大于等于5时，应剪成3和(n-3)，再继续循环
	int maxProductAfterCutting_solution2(int length)
	{
		_ASSERT(length > 0);
		if (length == 1) return 0;
		if (length == 2) return 1;
		if (length == 3) return 2;

		int NumOf3 = length / 3;
		if ((length - 3*NumOf3)  == 1)
		{
			--NumOf3;
		}
		int NumOf2 = (length - 3 * NumOf3) / 2;
		return pow(3, NumOf3)*pow(2, NumOf2);
	}
};

void test(const char* vTestName, int vLength, int vExpect)
{
	Solution solution = Solution();
	int Result1 = solution.maxProductAfterCutting_solution1(vLength);
	int Result2 = solution.maxProductAfterCutting_solution2(vLength);
	if (Result1 == vExpect)
		std::cout << "Solution1 for " << vTestName  << " Passed!\n";
	else
		std::cout << "Solution1 for " << vTestName << " Failed!\n";
	if (Result2 == vExpect)
		std::cout << "Solution2 for " << vTestName << " Passed!\n";
	else
		std::cout << "Solution2 for " << vTestName << " Failed!\n";
}

//边界值测试
void test1()
{
	int Length = 1;
	test("test1", Length, 0);
}

void test2()
{
	int Length = 2;
	test("test2", Length, 1);
}

void test3()
{
	int Length = 3;
	test("test3", Length, 2);
}

void test4()
{
	int Length = 4;
	test("test4", Length, 4);
}

void test5()
{
	int Length = 5;
	test("test5", Length, 6);
}

void test6()
{
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7()
{
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}

void test8()
{
	int length = 8;
	int expected = 18;
	test("test8", length, expected);
}

void test9()
{
	int length = 9;
	int expected = 27;
	test("test9", length, expected);
}

void test10()
{
	int length = 10;
	int expected = 36;
	test("test10", length, expected);
}

void test11()
{
	int length = 50;
	int expected = 86093442;
	test("test11", length, expected);
}

int main()
{

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();

	return 0;
}
