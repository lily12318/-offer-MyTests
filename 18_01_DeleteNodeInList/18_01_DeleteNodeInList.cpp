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
	//ֻ��һ���ڵ�
	if (*vHead == pToBeDeleted && pToBeDeleted->m_pNext == nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*vHead = nullptr;
	}
	//ɾ��β�ڵ�
	else if (pToBeDeleted->m_pNext == nullptr)
	{
		ListNode* TempNode = *vHead;
		while (TempNode->m_pNext != pToBeDeleted)
			TempNode = TempNode->m_pNext;
		TempNode->m_pNext = nullptr;
		delete pToBeDeleted;
	}
	//ɾ��ͷ�ڵ����ɾ���м�ڵ�
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
	//���ܳ����ڴ�й©,��Ҫѧϰ��ָoffer�Ĳο����롣�����ڴ氲ȫ

	//ɾ���м�Ľڵ�
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

	//������
	std::cout << Test(nullptr, nullptr, nullptr);

	//һ���ڵ������
	ListNode* p1_2 = CreateNode(1);
	std::cout << Test(p1_2, p1_2, nullptr);


	//ɾ��ͷ�ڵ�
	ListNode* p1_3 = CreateNode(1);
	ListNode* p2_3 = CreateNode(2);
	p1_3->m_pNext = p2_3;
	ListNode* pTest1_3 = CreateNode(2);
	std::cout << Test(p1_3, p1_3, pTest1_3);

	//DestroyList(p2_3);
//	DestroyList(pTest1_3);

	//ɾ��β�ڵ�
	ListNode* p1_4 = CreateNode(1);
	ListNode* p2_4 = CreateNode(2);
	p1_4->m_pNext = p2_4;
	ListNode* pTest1_4 = CreateNode(1);
	std::cout << Test(p1_4, p2_4, pTest1_4);

	//DestroyList(p1_4);
	//DestroyList(pTest1_4);

}