#include "BinaryAvlTree.h"

template<class ElemType>
BinAVLTreeNode<ElemType>* kth_Smallest(BinaryAVLTree<ElemType> &bt, int k)
{
	if (k > bt.NodeCount() || k <= 0) return NULL;//超范围，则返回NULL
	return kth_Smallest(bt.GetRoot(), k);
}

template <class ElemType>
BinAVLTreeNode<ElemType>* kth_Smallest(BinAVLTreeNode<ElemType>* p,int k)
{
	if (p == NULL)return NULL;
	if (k == p->lsize) return p;//p的lsize意味着，p的左边有lsize-1个结点，p是以p为根的子树上第k小的结点
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