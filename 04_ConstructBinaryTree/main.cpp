//#include "..\Utilities\BinaryTree.h"
#include <exception>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
		if (pre.size() == 0 || pre.size() != vin.size()) return nullptr;
		TreeNode *pRoot = new TreeNode(pre[0]);
		int PositionInOrder = 0;
		for (; PositionInOrder < vin.size(); ++PositionInOrder)
		{
			if (vin[PositionInOrder] == pre[0])break;
		}

		if (PositionInOrder >= vin.size())
			throw std::exception("Invalid input.");
		
		vector<int>::iterator RootPosition = find(vin.begin(), vin.end(), pre[0]);
		
		
		vector<int> LeftVin;
		vector<int> LeftPre;
		vector<int> RightVin;
		vector<int> RightPre;

		LeftVin.assign(vin.begin(), RootPosition);
		LeftPre.assign(pre.begin() + 1, pre.begin() + 1 + LeftVin.size());
		RightVin.assign(RootPosition + 1, vin.end());
		RightPre.assign(pre.begin() + 1 + LeftVin.size(), pre.end());

		pRoot->left = reConstructBinaryTree(LeftPre, LeftVin);
		pRoot->right = reConstructBinaryTree(RightPre, RightVin);
		return pRoot;
	}
};


//****************************************************************************************************
//FUNCTION:
void destroyTree(TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		TreeNode* pLeft = pRoot->left;
		TreeNode* pRight = pRoot->right;

		delete pRoot;
		pRoot = nullptr;

		destroyTree(pLeft);
		destroyTree(pRight);
	}
}

//****************************************************************************************************
//FUNCTION:
void printTreeNode(TreeNode* vpRoot)
{
	if (vpRoot != nullptr)
	{
		printf("value of this node is:%d \n", vpRoot->val);
		if (vpRoot->left != nullptr)
			printf("value of left child is:%d \n", vpRoot->left->val);
		else
			printf("left child is nullptr!\n");

		if (vpRoot->right != nullptr)
			printf("value of right child is:%d \n", vpRoot->right->val);
		else
			printf("right child is nullptr!\n");
	}
	else
		printf("this node is nullptr!");
}

//****************************************************************************************************
//FUNCTION:
void printTree(TreeNode* vpRoot)
{
	printTreeNode(vpRoot);
	if (vpRoot != nullptr)
	{
		printTreeNode(vpRoot->left);
		printTreeNode(vpRoot->right);
	}
}

// ====================测试代码====================
void Test(char* testName, vector<int>& preorder, vector<int>& inorder)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < preorder.size(); ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < inorder.size(); ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		Solution solution;
		TreeNode* root = solution.reConstructBinaryTree(preorder, inorder);
		int DebugPause = 0;
		printTree(root);

		destroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	vector<int> preorder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inorder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	vector<int> preorder = { 1, 2, 3, 4, 5 };
	vector<int> inorder = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	vector<int> preorder = { 1, 2, 3, 4, 5 };
	vector<int> inorder = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder);
}

// 树中只有一个结点
void Test4()
{
	vector<int> preorder = { 1 };
	vector<int> inorder = { 1 };

	Test("Test4", preorder, inorder);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> inorder = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder);
}

// 输入空指针
void Test6()
{
	vector<int> preorder;
	vector<int> inorder;
	Test("Test6", preorder, inorder);
}

// 输入的两个序列不匹配
void Test7()
{
	vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> inorder = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder);
}

// 输入的两个序列不匹配2
void Test8()
{
	vector<int> preorder = { 5, 2, 4, 1, 3, 6, 7 };
	vector<int> inorder = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder);
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
	Test8(); //lily's Test

	return 0;
}

