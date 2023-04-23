#ifndef ADJ_MATRIX_UNDIR_GRAPH_H
#define ADJ_MATRIX_UNDIR_GRAPH_H

#include "Assistance.h"

//无向图的邻接矩阵类
template <class ElemType>
class AdjMatrixUndirGraph
{
protected:
//邻接矩阵的数据成员
	//顶点数目，允许的顶点最大数目和边数
	int vexNum, vexMaxNum, arcNum;
	//存放边信息邻接矩阵
	int** arcs;
	//存放顶点信息的数组
	ElemType* vertexes;
	//标志数组
	mutable Status* tag;
public:
//邻接矩阵类型的方法声明：
	AdjMatrixUndirGraph(ElemType es[], int vertexNum,
		int vertexMaxNum = DEFAULT_SIZE);
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
	~AdjMatrixUndirGraph();

	void Clear();
	bool IsEmpty();
	int GetOrder(ElemType& d)const;//求顶点的序号
	Status GetElem(int v, ElemType& d)const;//求顶点的元素值
	Status SetElem(int v, const ElemType& d);//设置顶点的元素值
	int GetVexNum()const;
	int GetArcNum()const;
	int FirstAdjVex(int v)const;//返回顶点v的第1个邻接点
	int NextAdjVex(int v1, int v2)const;//返回顶点v1相对于顶点v2的下一个邻接点
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

//无向图的邻接矩阵实现部分
template<class ElemType>
AdjMatrixUndirGraph<ElemType>::
AdjMatrixUndirGraph(ElemType es[], 
	int vertexNum, int vertexMaxNum)
//构造函数，参数为顶点数组，顶点个数，最大顶点个数
{
	if (vertexNum < 0)
		throw Error("允许的顶点最大数目不能为负！");
	if (vertexNum > vertexMaxNum)
		throw Error("顶点数目不能大于允许的顶点最大数目！");
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
//构造函数，参数为最大顶点个数
{
	if (VertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负");
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
//求定点d的序号
{
	for (int v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			return v;
	return -1;
}

template<class ElemType>
Status AdjMatrixUndirGraph<ElemType>::
GetElem(int v, ElemType& d) const
//求序号为v的顶点值，用d带出该值
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
//设置序号为v的元素值为d
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
//返回顶点个数
{
	return vexNum;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
GetArcNum()const
//返回边数
{
	return arcNum;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
FirstAdjVex(int v) const
//返回顶点v的第1个邻接点的序号
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法！");
	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
			return u;
	return -1;
}

template<class ElemType>
int AdjMatrixUndirGraph<ElemType>::
NextAdjVex(int v1, int v2)const
//返回顶点v1相对于v2的下一个邻接点
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法！");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法！");
	if (v1 == v2)
		throw Error("v1不能等于v2！");

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
//插入顶点d
{
	if (vexNum = vexMaxNum)
		throw Error("图的顶点数不能超过允许的最大数！");
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
//插入依附于顶点v1和v2的边
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法！");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法！");
	if (v1 == v2)
		throw Error("v1不能等于v2！");

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
//删除元素为d的顶点
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			break;
	if (v == vexNum)
		throw Error("图中不存在要删除的顶点！");

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
	if (v < vexNum)//删的不是最后一个点
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
		throw Error("v1不合法！");
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法！");
	if (v1 == v2)
		throw Error("v1不能等于v2！");

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
		throw Error("不合法！");
	return tag[v];
}

template<class ElemType>
void AdjMatrixUndirGraph<ElemType>::
SetTag(int v, Status val)const
{
	if (v < 0 || v >= vexNum)
		throw Error("不合法！");
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