#ifndef ADJ_LIST_DIR_NETWORK_H
#define ADJ_LIST_DIR_NETWORK_H

#include "Assistance.h"
#include "AdjListDirNetworkArc.h"
#include "AdjListDirNetworkVex.h"

template<class ElemType,class WeightType>
class AdjListDirNetwork
{
protected:
	int vexNum;
	int vexMaxNum;
	int arcNum;
	AdjListNetworkVex<ElemType, WeightType>* vexTable;
	mutable Status* tag;
	WeightType infinity;
public:
	AdjListDirNetwork(int vexMaxNum = DEFAULT_SIZE, WeightType infinit = (WeightType)DEFAULT_INFINITY);
	AdjListDirNetwork(ElemType es[], int vexNum, int vexMaxNum = DEFAULT_SIZE, WeightType infinit = (WeightType)DEFAULT_INFINITY);
	~AdjListDirNetwork();

	void Clear();
	bool IsEmpty();
	int GetOrder(ElemType& d)const;
	Status GetElem(int v, ElemType& d)const;
	Status SetElem(int v, const ElemType& d);
	WeightType GetInfinity()const;
	int GetVexNum()const;
	int GetArcNum()const;
	int FirstAdjVex(int v)const;
	int NextAdjVex(int v1, int v2)const;
	void InsertVex(const ElemType& d);
	void InsertArc(int v1, int v2, WeightType w);
	void DeleteVex(const ElemType& d);
	void DeleteArc(int v1, int v2);
	WeightType GetWeight(int v1, int v2)const;
	void SetWeight(int v1, int v2, WeightType w);
	Status GetTag(int v)const;
	void SetTag(int v, Status tag)const;
	AdjListDirNetwork(const AdjListDirNetwork<ElemType, WeightType>& copy);
	AdjListDirNetwork<ElemType, WeightType>& operator=(const AdjListDirNetwork<ElemType, WeightType>& copy);
	void Display();
};

template<class ElemType,class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(ElemType es[], int vexNum, int vexMaxNum, WeightType infinity)
{
	if (vexNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ����");
	if (vexMaxNum < vexNum)
		throw Error("������Ŀ���ܴ�������Ķ��������Ŀ��");

	this->vexNum = vexNum;
	this->vexMaxNum = vexMaxNum;
	arcNum = 0;
	this->infinity = infinity;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetworkVex<ElemType, WeightType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++)
	{
		tag[v] = UNVISITED;
		vexTable[v].data = es[v];
		vexTable[v].firstarc = NULL;
	}
}

template<class ElemType,class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(int vexNum, WeightType infinity)
{
	if (vexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ����");

	this->vexNum = 0;
	this->vexMaxNum = vexMaxNum;
	arcNum = 0;
	this->infinity = infinity;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetworkVex<ElemType, WeightType>[vexMaxNum];
}

template<class ElemType, class WeightType>
AdjListDirNetwork<ElemType,WeightType>::~AdjListDirNetwork()
{
	Clear();
	delete[]tag;
	delete[]vexTable;
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::Clear()
{
	AdjListNetworkArc<WeightType>* p;
	for (int v = 0; v < vexNum; v++)
	{
		p = vexTable[v].firstarc;
		while (p != NULL)
		{
			vexTable[v].firstarc = p->nextarc;
			delete p;
			p = vexTable[v].firstarc;
		}
	}
	vexNum = 0;
	arcNum = 0;
}

template<class ElemType,class WeightType>
bool AdjListDirNetwork<ElemType, WeightType>::IsEmpty()
{
	return vexNum == 0;
}

template<class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetOrder(ElemType& d)const
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (d == vexTable[v].data)
			break;
	if (v < 0 || v >= vexNum) return -1;
	else return v;
}

template<class ElemType, class WeightType>
Status AdjListDirNetwork<ElemType, WeightType>::GetElem(int v, ElemType& d)const
{
	for (v = 0; v < vexNum; v++)
		if (v < 0 || v >= vexNum)
			return NOT_PRESENT;
		else
		{
			d = vexTable[v].data;
			return ENTRY_FOUND;
		}
}

template<class ElemType,class WeightType>
Status AdjListDirNetwork<ElemType, WeightType>::SetElem(int v, const ElemType& d)
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;
	else
	{
		vexTable[v].data = d;
		return SUCCESS;
	}
}

template<class ElemType,class WeightType>
WeightType AdjListDirNetwork<ElemType, WeightType>::GetInfinity()const
{
	return infinity;
}

template<class ElemType,class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetVexNum()const
{
	return vexNum;
}

template<class ElemType,class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetArcNum()const
{
	return arcNum;
}

template<class ElemType,class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::FirstAdjVex(int v)const
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ���");
	
	if (vexTable[v].firstarc = NULL)
		return -1;
	else
		return vexTable[v].firstarc->adjVex;
}

template<class ElemType,class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::NextAdjVex(int v1, int v2)const
{
	AdjListNetworkArc<WeightType>* p;
	if (v1 < 0 || v1 > vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 > vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");

	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p == NULL && p->nextarc = NULL)
		return -1;
	else
		return p->nextarc->adjVex;
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::InsertVex(const ElemType& d)
{
	if (vexNum == vexMaxNum)
		throw Error("ͼ�Ķ��������ܳ���������������");

	vexTable[vexNum].data = d;
	vexTable[vexNum].firstarc = NULL;
	tag[vexNum] = UNVISITED;
	vexNum++;
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType w)
{
	if (v1 < 0 || v1 > vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 > vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");
	if (w == infinity)
		throw Error("w����Ϊ�����");
	
	AdjListNetworkArc<WeightType>* p, * q;
	p = vexTable[v1].firstarc;
	vexTable[v1].firstarc = new AdjListNetworkArc<WeightType>(v2, w, p);
	arcNum++;
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::DeleteVex(const ElemType& d)
{
	int v;
	AdjListNetworkArc<WeightType>* p, * q;
	for (v = 0; v < vexNum; v++)
		if (vexTable[v].data == d)
			break;
	if (v == vexNum)
		throw Error("ͼ�в�����Ҫɾ���Ķ���");
	for (int u = 0; u < vexNum; u++)
		if (u != v)
			DeleteArc(u, v);
	p = vexTable[v].firstarc;
	while (p != NULL)
	{
		vexTable[v].firstarc = p->nextarc;
		delete p;
		p = vexTable[v].firstarc;
		arcNum--;
	}
	vexNum--;
	vexTable[v].data = vexTable[vexNum].data;
	vexTable[v].firstarc = vexTable[vexNum].firstarc;
	vexTable[vexNum].firstarc = NULL;
	tag[v] = tag[vexNum];

	for (int u = 0; u < vexNum; u++)
		if (u != v)
		{
			p = vexTable[u].firstarc;
			while (p != NULL)
			{
				if (p->adjVex == vexNum)
					p->adjVex = v;
				p = p->nextarc;
			}
		}
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::DeleteArc(int v1, int v2)
{
	if (v1 < 0 || v1 > vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 > vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");

	AdjListNetworkArc<WeightType>* p, * q=NULL;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
	{
		q = p;
		p = p->nextarc;
	}
	if (p != NULL)
	{
		if (vexTable[v1].firstarc == p)
			vexTable[v1].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		delete p;
		arcNum--;
	}
}

template<class ElemType,class WeightType>
WeightType AdjListDirNetwork<ElemType, WeightType>::GetWeight(int v1, int v2)const
{
	if (v1 < 0 || v1 > vexNum)
		throw Error("v1���Ϸ���");
	if (v2 < 0 || v2 > vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");
	AdjListNetworkArc<WeightType>* p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p != NULL)
		return p->weight;
	else
		return infinity;
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType w)
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");
	if (w == infinity)
		throw Error("w����Ϊ�޿մ�!");
	AdjListNetworkArc<WeightType>* p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p != NULL)
		p->weight = w;
	else
		throw Error("û�������ߣ�");
}

template<class ElemType,class WeightType>
Status AdjListDirNetwork<ElemType, WeightType>::GetTag(int v)const
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ���");
	return tag[v];
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::SetTag(int v, Status val)const
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ���");
	tag[v] = val;
}

template<class ElemType,class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(const AdjListDirNetwork<ElemType, WeightType>& copy)
{
	AdjListNetworkArc<WeightType>* p, * q;
	infinity = copy.infinity;
	vexNum = copy.vexNum;
	vexMaxNum = copy.vexMaxNum;
	arcNum = copy.arcNum;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetworkVex<ElemType, WeightType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++)
	{
		tag[v] = copy.tag[v];
		vexTable[v].data = copy.vexTable[v].data;
		vexTable[v].firstarc = NULL;
		p = copy.vexTable[v].firstarc;
		while(p!=NULL)
		{
			if (vexTable[v].firstarc = NULL)
			{
				vexTable[v].firstarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weight);
				q = vexTable[v].firstarc;
				p = p->nextarc;
			}
			else
			{
				q->nextarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weight);
				q = q->nextarc;
				p = p->nextarc;
			}
		}
	}
}

template<class ElemType,class WeightType>
AdjListDirNetwork<ElemType, WeightType>& AdjListDirNetwork<ElemType, WeightType>::operator=(const AdjListDirNetwork<ElemType, WeightType>& other)
{
	if (&copy == this)return *this;
	Clear();
	delete[]tag;
	delete[]vexTable;
	AdjListNetworkArc<WeightType>* p, * q;
	infinity = copy.infinity;
	vexNum = copy.vexNum;
	vexMaxNum = copy.vexMaxNum;
	arcNum = copy.arcNum;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetworkVex<ElemType, WeightType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++)
	{
		tag[v] = copy.tag[v];
		vexTable[v].data = copy.vexTable[v].data;
		vexTable[v].firstarc = NULL;
		p = copy.vexTable[v].firstarc;
		while (p != NULL)
		{
			if (vexTable[v].firstarc == NULL)
			{
				vexTable[v].firstarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weight);
				q = vexTable[v].firstarc;
				p = p->nextarc;
			}
			else
			{
				q->nextarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weight);
				q = q->nextarc;
				p = p->nextarc;
			}
		}
	}
	return *this;
}

template<class ElemType,class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::Display()
{
	AdjListNetworkArc<WeightType>* p;
	cout << "����������" << vexNum << "�����㣬" << arcNum << "���ߡ�" << endl;
	for (int v = 0; v < vexNum; v++)
	{
		for (int v = 0; v < vexNum; v++)
		{
			cout << v << ":\t" << vexTable[v].data;
			p = vexTable[v].firstarc;
			while (p != NULL)
			{
				cout << "-->(" << p->adjVex << "," << p->weight << ")";
				p = p->nextarc;
			}
			cout << endl;
		}
	}
}

#endif