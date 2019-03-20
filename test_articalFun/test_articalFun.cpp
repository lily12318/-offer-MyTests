// test_articalFun.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>


unsigned reverse(unsigned x) // Assuming 32 bit integers
{
	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
	x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
	x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
	x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
	return (x >> 16) | (x << 16);
}

int main()
{
	const unsigned n = 81;
	const unsigned b = 5;
	const unsigned m = 1u << b;
	const unsigned s = (n + m - 1) / m;
	const unsigned bits = (sizeof(unsigned) * CHAR_BIT) - b - log(s)/log(2);
	unsigned TempMax = 0;
	for (int i = 0; i < n; ++i)
	{
		const unsigned f = i / s;
		const unsigned p = i % s;
		const unsigned j = (reverse(f) >> bits) + p;
		
		std::cout << i << " " << j;
		if (j >= n)
		{
			std::cout << " " << i;
		}
		std::cout << std::endl;

		TempMax = TempMax > j ? TempMax : j;
	}
	std::cout << "\n" << TempMax << "\n";
    std::cout << "Hello World!\n";
}