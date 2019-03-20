/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

#include <cstdio>

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows <= 0 || cols <= 0) return 0;
		bool* Visited = new bool[rows*cols]{false};
		int Step = movingCountCore(threshold, rows, cols, 0, 0, Visited);
		delete Visited;
		return Step;
	}

	int movingCountCore(int vThreshold, int vRows, int vCols, int vCurRow, int vCurCol, bool* vVisited)
	{
		int Step = 0;
		if (check(vThreshold, vRows, vCols, vCurRow, vCurCol, vVisited))
		{
			vVisited[vCurRow*vCols + vCurCol] = true;
			Step = 1 + movingCountCore(vThreshold, vRows, vCols, vCurRow - 1, vCurCol, vVisited)
				+ movingCountCore(vThreshold, vRows, vCols, vCurRow, vCurCol - 1, vVisited)
				+ movingCountCore(vThreshold, vRows, vCols, vCurRow + 1, vCurCol, vVisited)
				+ movingCountCore(vThreshold, vRows, vCols, vCurRow, vCurCol + 1, vVisited);
		}
		return Step;
	}

	bool check(int vThreshold, int vRows, int vCols, int vCurRow, int vCurCol, bool* vVisited)
	{
		if (vCurRow >= 0 && vCurRow < vRows && vCurCol >= 0 && vCurCol < vCols && (getDigitSum(vCurRow) + getDigitSum(vCurCol) <= vThreshold) && !vVisited[vCurRow*vCols + vCurCol])
			return true;
		return false;
	}

	int getDigitSum(int vNum)
	{
		int Sum = 0;
		while (vNum)
		{
			Sum += vNum % 10;
			vNum /= 10;
		}
		return Sum;
	}
};

// ====================���Դ���====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);
	Solution SolutionTest = Solution();
	if (SolutionTest.movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// ������ж���
void test1()
{
	test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
	test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
	test("Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
	test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
	test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
	test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
	test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
	test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
void test9()
{
	test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
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

	return 0;
}
