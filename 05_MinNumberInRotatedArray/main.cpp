#include <cstdio>
#include <exception>

int Min(int* rotateArray, int vLow, int vHigh)
{
	int MinNum = rotateArray[vLow];
	for (int i = vLow+1; i <= vHigh; ++i)
	{
		if (rotateArray[i] < MinNum) MinNum = rotateArray[i];
	}

	return MinNum;
}

int Min(int* rotateArray, int length)
{
	if (length <= 0) return 0;
	int Low = 0;
	int High = length - 1;
	int Mid;
	while (Low < High && rotateArray[Low] >= rotateArray[High])
	{
		Mid = (Low + High) / 2;
		
		if (rotateArray[Low] == rotateArray[Mid] && rotateArray[Low] == rotateArray[High])
			return Min(rotateArray, Low, High);

		if (rotateArray[Mid] <= rotateArray[High])
			High = Mid;
		else
			Low = Mid + 1;
	}
	return rotateArray[Low];
}

// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char* argv[])
{
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入nullptr
	Test(nullptr, 0, 0);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字2
	int array7[] = { 1, 1, 1, 0, 1 };
	Test(array7, sizeof(array7) / sizeof(int), 0);

	return 0;
}

