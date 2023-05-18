#include "BinaryAvlTree.h"

/*
在平衡二叉排序树的每个结点中增设一个lsize域，
其值为该结点左子树中的节点数加1。
试写一个时间复杂度为O(logn)的算法，
确定树中第k小结点的位置
*/  

template<class ElemType>
BinAVLTreeNode<ElemType>* kth_Smallest(BinaryAVLTree<ElemType> &bt, int k)
{
	if (k > bt.NodeCount() || k <= 0) return NULL;//超范围，则返回NULL
	return kth_Smallest(bt.GetRoot(), k);
}

template <class ElemType>
BinAVLTreeNode<ElemType>* kth_Smallest(BinAVLTreeNode<ElemType>* p,int k)
{
	//p的lsize意味着，p的左边有lsize-1个结点，p是以p为根的子树上第lsize小的结点
	if (p == NULL)return NULL;
	if (k == p->lsize) return p;//lsize的值就是k，说明找到了答案
	else if (k <= p->lsize) kth_Smallest(p->leftChild, k);//p的lsize大于k，那么答案肯定在p的左子树上
	else kth_Smallest(p->rightChild, k - p->lsize);//p的lsize小于k，答案肯定在右子树上，并且要求右子树上第k-lsize小的结点
}

int main()
{
	BinaryAVLTree<int> bt;
	int elem[] = { 11, 39, 23, 68, 85, 8, 3, 46, 27, 50 };
	int n = 10;

	cout << "从空树开始依次插入元素{11, 39, 23, 68, 85, 8, 3, 46, 27, 50}，构造二叉平衡树。" << endl;
	for (int i = 0; i < n; i++) {
		cout << "插入第" << i + 1 << "元素" << elem[i] << endl;
		bt.Insert(elem[i]);			// 插入结点
		DisplayBTWithTreeShape(bt);
		cout << endl;
		//system("PAUSE");				// 调用库函数system()
	}
	while (1) {
		cout << "输入一个整数k，将会输出二叉树第k小的结点：";
		int k;
		cin >> k;
		cout << kth_Smallest(bt, k)->data << endl;
	}
	return 0;
}