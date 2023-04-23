#include "BinaryAvlTree.h"				// 二叉平衡树类

template<class ElemType>
int GetHeight(BinaryAVLTree<ElemType>& bt)
{
	int h = GetHeight(bt.GetRoot());
	cout << endl << "树的高度是：" << h << endl;
	return h;
}

template<class ElemType>
int GetHeight(BinAVLTreeNode<ElemType>* p)
{
	int h;
	//其实平衡因子只会是-1,0,1
	if (p == NULL) return 0;
	if (p->bf <= 0)//左子树高度大于等于右子树高度，则只关注左子树高度就行
		h = GetHeight(p->leftChild) + 1;
	else//只关注右子树高度就行
		h = GetHeight(p->rightChild) + 1;
	cout << endl << "当前结点的高度为" << h << endl;
	return h;
}

int main(void)
{
	BinaryAVLTree<int> bt;
	int elem[] = { 5, 12, 8, 10, 3, 6, 9, 1, 4, 13,2,7,11,14 };
	int n = 14;
	for (int i = 0; i < n; i++) {
		cout << "插入第" << i + 1 << "元素" << elem[i] << endl;
		bt.Insert(elem[i]);			// 插入结点
		DisplayBTWithTreeShape(bt);
		cout << endl;
	}
	GetHeight(bt);
}