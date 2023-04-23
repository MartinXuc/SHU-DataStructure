#include "BinaryTree.h"

template <class ElemType>
bool IsBinSortTree(const BinaryTree<ElemType>& bt)
{
	BinTreeNode<ElemType>* p = bt.GetRoot();
	return IsBinSortTree(p, INT_MIN, INT_MAX);
}

template <class ElemType>
bool IsBinSortTree(BinTreeNode<ElemType>* p, int min_val, int max_val)
//ʹ�õݹ�˼�룬����Ϊ��㣬��Сֵ�����ֵ
{
	if (p == NULL)return true;
	if (p->data < min_val || p->data > max_val)return false;//���ڷ�Χ��
	return IsBinSortTree(p->leftChild, min_val, p->data - 1)
		&& IsBinSortTree(p->rightChild, p->data + 1, max_val);
}

int main()
{
	BinTreeNode<char>* p;
	BinaryTree<char> bt;
	{
		char pre[] = { '5','3','2','1','4','6','8','7','9' }; // ��������
		char in[] = { '1','2','3','4','5','6','7','8','9' };  // ��������
		int n = 9;
		bt = CreateBinaryTree(pre, in, n);
		cout << "��ʾ��1��������" << endl;
		DisplayBTWithTreeShape<char>(bt);
		cout << endl;
		if (IsBinSortTree(bt))cout << endl << "����һ����ȷ�Ķ���������" << endl;
		else cout << endl << "�ⲻ��һ������������" << endl;
	}
	{
		char pre[] = { '5','3','2','1','4','6','8','7','9' }; // ��������
		char in[] = { '1','2','3','4','6','5','7','8','9' };  // ��������
		int n = 9;
		bt = CreateBinaryTree(pre, in, n);
		cout << "��ʾ��2��������" << endl;
		DisplayBTWithTreeShape<char>(bt);
		cout << endl;
		if (IsBinSortTree(bt))cout << endl << "����һ����ȷ�Ķ���������" << endl;
		else cout << endl << "�ⲻ��һ������������" << endl;
	}
	return 0;
}