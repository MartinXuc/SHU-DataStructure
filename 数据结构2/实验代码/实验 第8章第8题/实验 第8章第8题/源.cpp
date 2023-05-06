#include"BinarySortTree.h"
/*
��Ŀ����д�ݹ��㷨���Ӵ�С������������������йؼ���
��С��x������Ԫ�ء�Ҫ���㷨��ʱ�临�Ӷ�ΪO(logn+m)��
����nΪ�����������������Ľڵ�����mΪ���������Ԫ�ظ���
*/
template<class ElemType>
void myprint(BinarySortTree<ElemType>&bt, ElemType x)
{
	cout << "��С��x��Ԫ��Ϊ��";
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
		bt.Insert(elem[i]);			// ����elem�����е�Ԫ�ع������������
	cout << "ԭ����������:" << endl;
	DisplayBTWithTreeShape(bt);
	cout << endl;
	while (1)
	{
		int x;
		cout << "������x��ֵ��";
		cin >> x;
		myprint(bt, x);
	}
	return 0;
}