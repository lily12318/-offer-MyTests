#include <cstdio>
#include <cstring>

void ReplaceBlank(char str[], int length)
{
	if (str == nullptr)return;
	int NumTab = 0;
	int OriginalLength = 0;
	int AfterLength = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++OriginalLength;
		if (str[i] == ' ')
		{
			++NumTab;
		}
	}
	AfterLength = OriginalLength + 2 * NumTab;

	char* p1 = str + OriginalLength;
	char* p2 = str + AfterLength;
	while (p1 < p2)
	{
		if (*p1 == ' ')
		{
			*p2-- = '0';
			*p2-- = '2';
			*p2-- = '%';
		}
		else
			*p2-- = *p1;
		p1--;
	}
}

// ====================���Դ���====================
void Test(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
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

	return 0;
}

