#include <vector>
#include <stack>
#include "..\Utilities\List.h"

using namespace std;

class Solution {
public:
/*
	//My answer_1
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> Vec;
		if (head == nullptr) return Vec;
		insertNodeValueToVector(&head, Vec);
		return Vec;
	}

	void insertNodeValueToVector(ListNode** vNode, vector<int>& vioPrintResult)
	{
		if (*vNode == nullptr) return;
		insertNodeValueToVector(&(*vNode)->m_pNext, vioPrintResult);
		vioPrintResult.push_back((*vNode)->m_nValue);
	}*/

	//My answer_2
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> Vec;
		if (head == nullptr) return Vec;
		
		std::stack<int> Stack;
		ListNode* Node = head;
		while (Node != nullptr)
		{
			Stack.push(Node->m_nValue);
			Node = Node->m_pNext;
		}

		while (!Stack.empty())
		{
			Vec.push_back(Stack.top());
			Stack.pop();
		}
		return Vec;
	}
};

// ====================测试代码====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	Solution solution;
	solution.printListFromTailToHead(pHead);
	printf("\n");
}

// 1->2->3->4->5
void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test3()
{
	printf("\nTest3 begins.\n");

	Test(nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}