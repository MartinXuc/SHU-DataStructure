#ifndef ADJ_MATRIX_UNDIR_GRAPH_H
#define ADJ_MATRIX_UNDIR_GRAPH_H

#include "Assistance.h"

//����ͼ���ڽӾ�����
template <class ElemType>
class AdjMatrixUndirGraph
{
protected:
//�ڽӾ�������ݳ�Ա
	//������Ŀ������Ķ��������Ŀ�ͱ���
	int vexNum, vexMaxNum, arcNum;
	//��ű���Ϣ�ڽӾ���
	int** arcs;
	//��Ŷ�����Ϣ������
	ElemType* vertexes;
	//��־����
	mutable Status* tag;
public:
//�ڽӾ������͵ķ���������
	AdjMatrixUndirGraph(ElemType es[], int vertexNum,
		int vertexMaxNum = DEFAULT_SIZE);
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
	~AdjMatrixUndirGraph();

	void Clear();
	bool IsEmpty();
	int GetOrder(ElemType& d)const;//�󶥵�����
	Status GetElem(int v, ElemType& d)const;//�󶥵��Ԫ��ֵ
	Status SetElem(int v, const ElemType& d);//���ö����Ԫ��ֵ
	int GetVexNum()const;
	int GetArcNum()const;
	int FirstAdjVex(int v)const;//���ض���v�ĵ�1���ڽӵ�
	int NextAdjVex(int v1, int v2)const;//���ض���v1����ڶ���v2����һ���ڽӵ�
	void InsertVex(const ElemType& d);
	void InsertArc(const int v1, const int v2);
	void DeleteVex(const ElemType& d);
	void DeleteArc(const int v1, const int v2);
	Status GetTag(int v)const;
	void SetTag(int v, Status val)const;
	AdjMatrixUndirGraph(const AdjMatrixUndirGraph<ElemType>& g);
	AdjMatrixUndirGraph<ElemType>& operator=(const AdjMatrixUndirGraph<ElemType>& g);
	void Display();
};

//����ͼ���ڽӾ���ʵ�ֲ���
template<class ElemType>
AdjMatrixUndirGraph<ElemType>::
AdjMatrixUndirGraph(ElemType es[], 
	int vertexNum, int vertexMaxNum)
//���캯��������Ϊ�������飬�����������󶥵����
{
	if (vertexNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ����");
	if (vertexNum > vertexMaxNum)
		throw Error("������Ŀ���ܴ�������Ķ��������Ŀ��");
	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	vertexes = new ElemType[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = new int* [vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
	for (int v = 0; v < vexNum; v++)
	{
		vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = 0;
	}
}

template<class ElemType>
AdjMatrixUndirGraph<ElemType>::
AdjMatrixUndirGraph(int VertexMaxNum)
//���캯��������Ϊ��󶥵����
{
	if (VertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��");
	vexNum = 0;
	vexMaxNum = VertexMaxNum;
	arcNum = 0;
	vertexes = new ElemType[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = new int* [vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
Clear()
{
	vexNum = 0;
	arcNum = 0;
}

template<class ElemType>
bool AdjMatrixUndirGraph<ElemType>::
IsEmpty()
{
	return vexNum == 0;
}

template<class ElemType>
AdjMatrixUndirGraph<ElemType>::
~AdjMatrixUndirGraph()
{
	delete[] vertexes;
	delete[] tag;
	for (int v = 0; v < vexMaxNum; v++)
		delete[] arcs[v];
	delete[] arcs;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
GetOrder(ElemType& d)const
//�󶨵�d�����
{
	for (int v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			return v;
	return -1;
}

template<class ElemType>
Status AdjMatrixUndirGraph<ElemType>::
GetElem(int v, ElemType& d) const
//�����Ϊv�Ķ���ֵ����d������ֵ
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;
	else
	{
		d = vertexes[v];
		return ENTRY_FOUND;
	}
}

template<class ElemType>
Status AdjMatrixUndirGraph<ElemType>::
SetElem(int v, const ElemType& d)
//�������Ϊv��Ԫ��ֵΪd
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;
	else
	{
		vertexes[v] = d;
		return SUCCESS;
	}
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
GetVexNum()const
//���ض������
{
	return vexNum;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
GetArcNum()const
//���ر���
{
	return arcNum;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
FirstAdjVex(int v) const
//���ض���v�ĵ�1���ڽӵ�����
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ���");
	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
			return u;
	return -1;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
NextAdjVex(int v1, int v2)const
//���ض���v1�����v2����һ���ڽӵ�
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");

	for (int u = v2 + 1; u < vexNum; u++)
	{
		if (arcs[v1][u] != 0)
			return u;
	}
	return -1;
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
InsertVex(const ElemType& d)
//���붥��d
{
	if (vexNum = vexMaxNum)
		throw Error("ͼ�Ķ��������ܳ���������������");
	vertexes[vexNum] = d;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++)
	{
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
	}
	vexNum++;
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
InsertArc(const int v1, const int v2)
//���������ڶ���v1��v2�ı�
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");

	if (arcs[v1][v2] == 0)
	{
		arcNum++;
		arcs[v1][v2] = 1;
		arcs[v2][v1] = 1;
	}
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
DeleteVex(const ElemType& d)
//ɾ��Ԫ��Ϊd�Ķ���
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			break;
	if (v == vexNum)
		throw Error("ͼ�в�����Ҫɾ���Ķ��㣡");

	for (int u = 0; u < vexNum; u++)
	{
		if (arcs[v][u] == 1)
		{
			arcNum--;
			arcs[v][u] = 0;
			arcs[u][v] = 0;
		}
	}
	vexNum--;
	if (v < vexNum)//ɾ�Ĳ������һ����
	{
		vertexes[v] = vertexes[vexNum];
		tag[v] = tag[vexNum];
		for (int u = 0; u < vexNum; u++)
		{
			arcs[v][u] = arcs[vexNum][u];
			arcs[u][v] = arcs[u][vexNum];
		}
	}
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
DeleteArc(const int v1, const int v2)
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");

	if (arcs[v1][v2] != 0)
	{
		arcNum--;
		arcs[v1][v2] = 0;
		arcs[v2][v1] = 0;
	}
}

template<class ElemType>
Status AdjMatrixUndirGraph<ElemType>::
GetTag(int v)const
{
	if (v < 0 || v >= vexNum)
		throw Error("���Ϸ���");
	return tag[v];
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
SetTag(int v, Status val)const
{
	if (v < 0 || v >= vexNum)
		throw Error("���Ϸ���");
	tag[v] = val;
}

template<class ElemType>
AdjMatrixUndirGraph<ElemType>::
AdjMatrixUndirGraph(const AdjMatrixUndirGraph<ElemType>& g)
{
	vexNum = g.vexNum;
	vexMaxNum = g.vexMaxNum;
	arcNum = g.arcNum;
	vertexes = new ElemType[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = new int* [vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
	for (int v = 0; v < vexNum; v++)
	{
		vertexes[v] = g.vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = g.arcs[v][u];
	}
}

template<class ElemType>
AdjMatrixUndirGraph<ElemType>&
AdjMatrixUndirGraph<ElemType>::
operator=(const AdjMatrixUndirGraph<ElemType>& g)
{
	if (&g == this)return *this;
	delete[]vertexes;
	delete[]tag;
	for (int v = 0; v < vexMaxNum; v++)
		delete[]arcs[v];
	delete[]arcs;
	vexNum = g.vexNum;
	vexMaxNum = g.vexMaxNum;
	arcNum = g.arcNum;
	vertexes = new ElemType[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = new int* [vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
	for (int v = 0; v < vexNum; v++)
	{
		vertexes[v] = g.vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = g.arcs[v][u];
	}
	return *this;
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::Display()
{
	for (int v = 0; v < vexNum; v++)
		cout << "\t" << vertexes[v];
	cout << endl;
	for (int v = 0; v < vexNum; v++)
	{
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
			cout << "\t" << arcs[v][u];
		cout << endl;
	}
}

#endif