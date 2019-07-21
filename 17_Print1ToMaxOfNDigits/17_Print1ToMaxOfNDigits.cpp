#include <iostream>
#include <string>

void printNum(const std::string& vStr)
{
	int i = 0;
	int Len = vStr.size();
	bool IsFirstBit = false;
	for (int i = 0; i < Len; i++)
	{
		if (IsFirstBit == false && vStr[i] != '0')
			IsFirstBit = true;
		if (IsFirstBit == true)
			std::cout << vStr[i];
	}
	std::cout << std::endl;
}

void printToDigits(const std::string& vStr, int vDigit)
{
	if (vDigit == 0)
	{
		printNum(vStr);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		std::string TempStr = vStr + std::to_string(i);
		printToDigits(TempStr, vDigit - 1);
	}
}

void printToMaxOfDigits(int vDigit)
{
	if (vDigit <= 0)
	{
		std::cout << "please input a positive integer!";
		return;
	}
	printToDigits("", vDigit);
}

int main()
{
	int n;
	std::cin >> n;
	printToMaxOfDigits(n);
	return 0;
}