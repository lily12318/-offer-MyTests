#include <iostream>

struct ListNode
{
	int m_Value;
	ListNode* m_pNext;
};

ListNode* CreateNode(int value)
{
	ListNode* pHead = new ListNode();
	pHead->m_Value = value;
	pHead->m_pNext = nullptr;
	return pHead;
}

void DeleteNode(ListNode** vHead, ListNode* pToBeDeleted)
{
	if (!*vHead || !pToBeDeleted)
		return;
	//只有一个节点
	if (*vHead == pToBeDeleted && pToBeDeleted->m_pNext == nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*vHead = nullptr;
	}
	//删除尾节点
	else if (pToBeDeleted->m_pNext == nullptr)
	{
		ListNode* TempNode = *vHead;
		while (TempNode->m_pNext != pToBeDeleted)
			TempNode = TempNode->m_pNext;
		TempNode->m_pNext = nullptr;
		delete pToBeDeleted;
	}
	//删除头节点或者删除中间节点
	else
	{
		ListNode* Temp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_Value = Temp->m_Value;
		pToBeDeleted->m_pNext = Temp->m_pNext;
		delete Temp;
	}
}


bool Test(ListNode* pListHead, ListNode* pToBeDeleted,ListNode* pTargetListHead)
{
	DeleteNode(&pListHead, pToBeDeleted);
	ListNode* p1 = pListHead;
	ListNode* p2 = pTargetListHead;
	while (p1 != nullptr && p2 != nullptr && p1->m_Value == p2->m_Value)
	{
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}
	if (p1 == nullptr && p2 == nullptr) return true;
	else return false;
}

void DestroyList(ListNode* vListHead)
{
	ListNode* TempNode = vListHead;
	while (TempNode != nullptr)
	{
		vListHead = vListHead->m_pNext;
		delete TempNode;
		TempNode = vListHead;
	}
}

void main()
{
	//可能出现内存泄漏,需要学习剑指offer的参考代码。做到内存安全

	//删除中间的节点
	ListNode* p1 = CreateNode(1);
	ListNode* p2 = CreateNode(2);
	ListNode* p3 = CreateNode(3);
	p2->m_pNext = p3;
	p1->m_pNext = p2;
	ListNode* pTest1 = CreateNode(1);
	ListNode* pTest2 = CreateNode(3);
	pTest1->m_pNext = pTest2;
	std::cout << Test(p1, p2, pTest1);
	
	DestroyList(p1);
	DestroyList(pTest1);

	//空链表
	std::cout << Test(nullptr, nullptr, nullptr);

	//一个节点的链表
	ListNode* p1_2 = CreateNode(1);
	std::cout << Test(p1_2, p1_2, nullptr);


	//删除头节点
	ListNode* p1_3 = CreateNode(1);
	ListNode* p2_3 = CreateNode(2);
	p1_3->m_pNext = p2_3;
	ListNode* pTest1_3 = CreateNode(2);
	std::cout << Test(p1_3, p1_3, pTest1_3);

	//DestroyList(p2_3);
//	DestroyList(pTest1_3);

	//删除尾节点
	ListNode* p1_4 = CreateNode(1);
	ListNode* p2_4 = CreateNode(2);
	p1_4->m_pNext = p2_4;
	ListNode* pTest1_4 = CreateNode(1);
	std::cout << Test(p1_4, p2_4, pTest1_4);

	//DestroyList(p1_4);
	//DestroyList(pTest1_4);

}