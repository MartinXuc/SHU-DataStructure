#include "BinaryAvlTree.h"

/*
��ƽ�������������ÿ�����������һ��lsize��
��ֵΪ�ý���������еĽڵ�����1��
��дһ��ʱ�临�Ӷ�ΪO(logn)���㷨��
ȷ�����е�kС����λ��
*/  

template<class ElemType>
BinAVLTreeNode<ElemType>* kth_Smallest(BinaryAVLTree<ElemType> &bt, int k)
{
	if (k > bt.NodeCount() || k <= 0) return NULL;//����Χ���򷵻�NULL
	return kth_Smallest(bt.GetRoot(), k);
}

template <class ElemType>
BinAVLTreeNode<ElemType>* kth_Smallest(BinAVLTreeNode<ElemType>* p,int k)
{
	//p��lsize��ζ�ţ�p�������lsize-1����㣬p����pΪ���������ϵ�lsizeС�Ľ��
	if (p == NULL)return NULL;
	if (k == p->lsize) return p;//lsize��ֵ����k��˵���ҵ��˴�
	else if (k <= p->lsize) kth_Smallest(p->leftChild, k);//p��lsize����k����ô�𰸿϶���p����������
	else kth_Smallest(p->rightChild, k - p->lsize);//p��lsizeС��k���𰸿϶����������ϣ�����Ҫ���������ϵ�k-lsizeС�Ľ��
}

int main()
{
	BinaryAVLTree<int> bt;
	int elem[] = { 11, 39, 23, 68, 85, 8, 3, 46, 27, 50 };
	int n = 10;

	cout << "�ӿ�����ʼ���β���Ԫ��{11, 39, 23, 68, 85, 8, 3, 46, 27, 50}���������ƽ������" << endl;
	for (int i = 0; i < n; i++) {
		cout << "�����" << i + 1 << "Ԫ��" << elem[i] << endl;
		bt.Insert(elem[i]);			// ������
		DisplayBTWithTreeShape(bt);
		cout << endl;
		//system("PAUSE");				// ���ÿ⺯��system()
	}
	while (1) {
		cout << "����һ������k�����������������kС�Ľ�㣺";
		int k;
		cin >> k;
		cout << kth_Smallest(bt, k)->data << endl;
	}
	return 0;
}