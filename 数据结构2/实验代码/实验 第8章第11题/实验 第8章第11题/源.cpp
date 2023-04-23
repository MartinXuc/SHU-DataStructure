#include "BinaryAvlTree.h"				// ����ƽ������

template<class ElemType>
int GetHeight(BinaryAVLTree<ElemType>& bt)
{
	int h = GetHeight(bt.GetRoot());
	cout << endl << "���ĸ߶��ǣ�" << h << endl;
	return h;
}

template<class ElemType>
int GetHeight(BinAVLTreeNode<ElemType>* p)
{
	int h;
	//��ʵƽ������ֻ����-1,0,1
	if (p == NULL) return 0;
	if (p->bf <= 0)//�������߶ȴ��ڵ����������߶ȣ���ֻ��ע�������߶Ⱦ���
		h = GetHeight(p->leftChild) + 1;
	else//ֻ��ע�������߶Ⱦ���
		h = GetHeight(p->rightChild) + 1;
	cout << endl << "��ǰ���ĸ߶�Ϊ" << h << endl;
	return h;
}

int main(void)
{
	BinaryAVLTree<int> bt;
	int elem[] = { 5, 12, 8, 10, 3, 6, 9, 1, 4, 13,2,7,11,14 };
	int n = 14;
	for (int i = 0; i < n; i++) {
		cout << "�����" << i + 1 << "Ԫ��" << elem[i] << endl;
		bt.Insert(elem[i]);			// ������
		DisplayBTWithTreeShape(bt);
		cout << endl;
	}
	GetHeight(bt);
}