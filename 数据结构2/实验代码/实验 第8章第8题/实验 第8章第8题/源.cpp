#include"BinarySortTree.h"

template<class ElemType>
void myprint(BinarySortTree<ElemType>&bt, ElemType x)
{
	BinTreeNode<ElemType>* root = bt.GetRoot();
	myprint(root, x);
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
	myprint(bt, 8);
	return 0;
}