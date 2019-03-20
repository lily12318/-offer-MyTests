#include <cstdio>
#include <string>
#include <stack>

class Solution {
public:
	bool hasPath(const char* matrix, int rows, int cols, const char* str)
	{
		if (str == nullptr || matrix == nullptr || rows <= 0 || cols <= 0) return false;
		char* Visited = new char[rows*cols]{ false };
		for (int i = 0; i < rows; ++i)
		{
			for (int k = 0; k < cols; ++k)
			{
					if (hasSubPath(matrix, rows, cols, i, k, 0, str, Visited)) return true;
			}
		}
		delete Visited;
		return false;
	}

	bool hasSubPath(const char* vMatrix, int vRows, int vCols, int vRowIdx, int vColIdx, int vCharIdx, const char* vStrChar, char* vVisited)
	{
		if (vStrChar[vCharIdx] == '\0') return true;
		bool hasPath = false;
		if (vRowIdx >= 0 && vRowIdx < vRows && vColIdx >= 0 && vColIdx < vCols && vMatrix[vRowIdx*vCols + vColIdx] == vStrChar[vCharIdx] 
			&& !vVisited[vRowIdx*vCols + vColIdx])
		{
			vVisited[vRowIdx*vCols + vColIdx] = true;
			++vCharIdx;
			hasPath = hasSubPath(vMatrix, vRows, vCols, vRowIdx - 1, vColIdx, vCharIdx, vStrChar, vVisited)
				|| hasSubPath(vMatrix, vRows, vCols, vRowIdx, vColIdx - 1, vCharIdx, vStrChar, vVisited)
				|| hasSubPath(vMatrix, vRows, vCols, vRowIdx + 1, vColIdx, vCharIdx, vStrChar, vVisited)
				|| hasSubPath(vMatrix, vRows, vCols, vRowIdx, vColIdx + 1, vCharIdx, vStrChar, vVisited);
			if (!hasPath)
			{
				vVisited[vRowIdx*vCols + vColIdx] = false;
				--vCharIdx;
			}
			
		}
		return hasPath;
	}

};

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	Solution solution;
	if (solution.hasPath(matrix, rows, cols, str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";

	Test("Test1", (const char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
	const char* matrix = "ABCESFCSADEE";
	const char* str = "SEE";

	Test("Test2", (const char*)matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "ABFB";

	Test("Test3", (const char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SLHECCEIDEJFGGFIE";

	Test("Test4", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEM";

	Test("Test5", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEEJIGOEM";

	Test("Test6", (const char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEMS";

	Test("Test7", (const char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAA";

	Test("Test8", (const char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAAA";

	Test("Test9", (const char*)matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
	const char* matrix = "A";
	const char* str = "A";

	Test("Test10", (const char*)matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
	const char* matrix = "A";
	const char* str = "B";

	Test("Test11", (const char*)matrix, 1, 1, str, false);
}

void Test12()
{
	Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();

	return 0;
}