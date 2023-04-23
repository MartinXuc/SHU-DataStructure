#include "BinaryTree.h"

template <class ElemType>
bool IsBinSortTree(const BinaryTree<ElemType>& bt)
{
	BinTreeNode<ElemType>* p = bt.GetRoot();
	return IsBinSortTree(p, INT_MIN, INT_MAX);
}

template <class ElemType>
bool IsBinSortTree(BinTreeNode<ElemType>* p, int min_val, int max_val)
//使用递归思想，参数为结点，最小值，最大值
{
	if (p == NULL)return true;
	if (p->data < min_val || p->data > max_val)return false;//不在范围内
	return IsBinSortTree(p->leftChild, min_val, p->data - 1)
		&& IsBinSortTree(p->rightChild, p->data + 1, max_val);
}

int main()
{
	BinTreeNode<char>* p;
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