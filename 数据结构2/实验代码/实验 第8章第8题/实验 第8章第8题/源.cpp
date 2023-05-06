#include"BinarySortTree.h"
/*
题目：编写递归算法，从大到小输出二叉排序树中所有关键字
不小于x的数据元素。要求算法的时间复杂度为O(logn+m)，
其中n为二叉排序树中所含的节点数，m为输出的数据元素个数
*/
template<class ElemType>
void myprint(BinarySortTree<ElemType>&bt, ElemType x)
{
	cout << "不小于x的元素为：";
	BinTreeNode<ElemType>* root = bt.GetRoot();
	myprint(root, x);
	cout << endl;
}

template<class ElemType>
void myprint(BinTreeNode<ElemType>* p, ElemType x)
{
	if (p == NULL)return;
	if (p->data < x)
		myprint(p->rightChild, x);
	else
	{
		myprint(p->rightChild, x);
		cout << p->data<<'\t';
		myprint(p->leftChild, x);
	}
}

int main()
{
	BinarySortTree<int> bt;
	int elem[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
	int n = 10;	
	for (int i = 0; i < n; i++)
		bt.Insert(elem[i]);			// 根据elem数组中的元素构造二叉排序树
	cout << "原二叉排序树:" << endl;
	DisplayBTWithTreeShape(bt);
	cout << endl;
	while (1)
	{
		int x;
		cout << "请输入x的值：";
		cin >> x;
		myprint(bt, x);
	}
	return 0;
}