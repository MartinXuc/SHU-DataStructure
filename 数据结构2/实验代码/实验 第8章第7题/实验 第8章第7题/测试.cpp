#include "BinaryTree.h"

template <class ElemType>
bool IsBinSortTree(const BinaryTree<ElemType>& bt)
{
	BinTreeNode<ElemType>* p = bt.GetRoot();
	return IsBinSortTree(p);
}

template <class ElemType>
bool IsBinSortTree(BinTreeNode<ElemType>* p)
//参数为一个链式二叉树的根，函数使用递归方法
//递归思想：一个二叉排序树的子树也必然是二叉排序树；若两子树是二叉排序树，则
{
	if (p == NULL) return true;//空树是二叉排序树
	if (!(IsBinSortTree(p->leftChild) && IsBinSortTree(p->rightChild)))//若子树中有不是二叉排序树的
		return false;
	else//若子树都是二叉排序树
	{
		BinTreeNode<ElemType>
			* former = GetMidPrecursor(p),
			* latter = GetMidSuccessor(p);//前驱结点和后继结点

		if (former == NULL && latter == NULL)
			return true;//叶子结点是二叉排序树
		else if (former == NULL)//只有右子树
		{
			if (p->data < latter->data)
				return true;
			else
				return false;
		}
		else if (latter == NULL)//只有左子树
		{
			if (former->data < p->data)
				return true;
			else
				return false;
		}
		else//左右子树都有
		{
			if (former->data < p->data && p->data < latter->data)
				return true;
			else return false;
		}
	}
}

template<class ElemType>
BinTreeNode<ElemType>* GetMidPrecursor(BinTreeNode<ElemType>* p)//求中序前驱
{
	BinTreeNode<ElemType>* t = p;
	t = t->leftChild;
	if (t == NULL)return NULL;//若p无左子树，返回NULL
	else
	{
		while (t->rightChild != NULL)
			t = t->rightChild;
		return t;
	}
}

template<class ElemType>
BinTreeNode<ElemType>* GetMidSuccessor(BinTreeNode<ElemType>* p)//求中序后继
{
	BinTreeNode<ElemType>* t = p;
	t = t->rightChild;
	if (t == NULL)return NULL;//若P无右子树，返回NULL
	else
	{
		while (t->leftChild != NULL)
			t = t->leftChild;
		return t;
	}
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