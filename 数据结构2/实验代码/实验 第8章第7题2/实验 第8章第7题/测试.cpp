#include "BinaryTree.h"

/*
判别给定二叉树是否为二叉排序树
*/


template <class ElemType>
bool IsBinSortTree(const BinaryTree<ElemType>& bt)
{
	vector<ElemType> inorder;
	inorderTraversal(bt.GetRoot(), inorder);
	for (int i = 1; i < inorder.size(); i++) {
		if (inorder[i] <= inorder[i - 1]) {
			return false;
		}
	}
	return true;
}

template<class ElemType>
void inorderTraversal(BinTreeNode<ElemType>* p, vector<ElemType>& inorder)
{
	if (p == NULL) return;
	inorderTraversal(p->leftChild, inorder);
	inorder.push_back(p->data);
	inorderTraversal(p->rightChild, inorder);
}


int main()
{
	//BinTreeNode<char>* p;
	BinaryTree<char> bt;
	{
		char pre[] = { '5','3','2','1','4','6','8','7','9' }; // 先序序列
		char in[] = { '1','2','3','4','5','6','7','8','9' };  // 中序序列
		int n = 9;
		bt = CreateBinaryTree(pre, in, n);
		cout << "显示第1个二叉树" << endl;
		DisplayBTWithTreeShape<char>(bt);
		cout << endl;
		if (IsBinSortTree(bt))cout << endl << "这是一个正确的二叉排序树" << endl;
		else cout << endl << "这不是一个二叉排序树" << endl;
	}
	{
		char pre[] = { '5','3','2','1','4','6','8','7','9' }; // 先序序列
		char in[] = { '1','2','3','4','6','5','7','8','9' };  // 中序序列
		int n = 9;
		bt = CreateBinaryTree(pre, in, n);
		cout << "显示第2个二叉树" << endl;
		DisplayBTWithTreeShape<char>(bt);
		cout << endl;
		if (IsBinSortTree(bt))cout << endl << "这是一个正确的二叉排序树" << endl;
		else cout << endl << "这不是一个二叉排序树" << endl;
	}
	return 0;
}