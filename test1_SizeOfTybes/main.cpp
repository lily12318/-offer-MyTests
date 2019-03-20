/*
1. �������ָ����size�޷��õ����鱾���Ĵ�С������ֵ����ʱ�˻�Ϊָ��
2. ��������ָ���С����4�ֽ�
*/


#include <iostream>

//****************************************************************************************************
//FUNCTION:
int GetSize(int data[])
{
	return sizeof(data);
}

int GetSize2(int(&data)[5])
{
	return sizeof(data);
}

//****************************************************************************************************
//FUNCTION:
void SizeOfArrayAndPoint()
{
	int Array[] = { 1,2,3,4,5 };
	int* pArray = Array;

	std::cout << "Size Of Array And Point are: " << sizeof(Array) << "," << sizeof(pArray) << "," << GetSize(Array) << "," << GetSize2(Array) << std::endl;
}

//****************************************************************************************************
//FUNCTION:
void SizeOfDifTypePoint()
{
	int Array1[] = { 1,2,3,4,5 };
	float Array2[] = { 1.0,2.0,3.0,4.0,5.0 };
	char Str[] = "This is a Test String";

	int* pArray1 = Array1;
	float* pArray2 = Array2;
	char* pStr = Str;

	std::cout << "Size Of Different Type Point are: " << sizeof(pArray1) << "," << sizeof(pArray2) << "," << sizeof(pStr) << std::endl;
}

//****************************************************************************************************
//FUNCTION:
void main()
{
	SizeOfArrayAndPoint();
	SizeOfDifTypePoint();

	std::cout << std::endl;
	std::cout << "Size Of char is: " << sizeof(char) << std::endl;
	std::cout << "Size Of short is: " << sizeof(short) << std::endl;
	std::cout << "Size Of int is: " << sizeof(int) << std::endl;
	std::cout << "Size Of long is: " << sizeof(long) << std::endl;
	std::cout << "Size Of long long is: " << sizeof(long long) << std::endl;
	std::cout << "Size Of float is: " << sizeof(float) << std::endl;
	std::cout << "Size Of double is: " << sizeof(double) << std::endl;

	std::cout << std::endl;
	int a = 0;
	std::cout << "sizeof����������е������Ƿ������㣿\na = 0\n" << "sizeof(a++) = " << sizeof(a++) << std::endl << "sizeof(++a) = " << sizeof(++a) << std::endl << "a = " << a << std::endl;
}