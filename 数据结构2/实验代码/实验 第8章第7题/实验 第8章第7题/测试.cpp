#include "BinaryTree.h"

template <class ElemType>
bool IsBinSortTree(const BinaryTree<ElemType>& bt)
{
	BinTreeNode<ElemType>* p = bt.GetRoot();
	return IsBinSortTree(p);
}

template <class ElemType>
bool IsBinSortTree(BinTreeNode<ElemType>* p)
//����Ϊһ����ʽ�������ĸ�������ʹ�õݹ鷽��
//�ݹ�˼�룺һ������������������Ҳ��Ȼ�Ƕ��������������������Ƕ�������������
{
	if (p == NULL) return true;//�����Ƕ���������
	if (!(IsBinSortTree(p->leftChild) && IsBinSortTree(p->rightChild)))//���������в��Ƕ�����������
		return false;
	else//���������Ƕ���������
	{
		BinTreeNode<ElemType>
			* former = GetMidPrecursor(p),
			* latter = GetMidSuccessor(p);//ǰ�����ͺ�̽��

		if (former == NULL && latter == NULL)
			return true;//Ҷ�ӽ���Ƕ���������
		else if (former == NULL)//ֻ��������
		{
			if (p->data < latter->data)
				return true;
			else
				return false;
		}
		else if (latter == NULL)//ֻ��������
		{
			if (former->data < p->data)
				return true;
			else
				return false;
		}
		else//������������
		{
			if (former->data < p->data && p->data < latter->data)
				return true;
			else return false;
		}
	}
}

template<class ElemType>
BinTreeNode<ElemType>* GetMidPrecursor(BinTreeNode<ElemType>* p)//������ǰ��
{
	BinTreeNode<ElemType>* t = p;
	t = t->leftChild;
	if (t == NULL)return NULL;//��p��������������NULL
	else
	{
		while (t->rightChild != NULL)
			t = t->rightChild;
		return t;
	}
}

template<class ElemType>
BinTreeNode<ElemType>* GetMidSuccessor(BinTreeNode<ElemType>* p)//��������
{
	BinTreeNode<ElemType>* t = p;
	t = t->rightChild;
	if (t == NULL)return NULL;//��P��������������NULL
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