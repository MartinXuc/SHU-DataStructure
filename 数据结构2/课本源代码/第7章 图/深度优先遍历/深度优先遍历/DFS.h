#ifndef DFS_H
#define DFS_H

#include "AdjMatrixUndirGraph.h"

//����������������ͨ�����Ѳ���
template<class ElemType>
void DFS(const AdjMatrixUndirGraph<ElemType>& g, int v, void(*visit)(const ElemType&))
{
	ElemType e;
	g.SetTag(v, VISITED);
	g.GetElem(v, e);
	visit(e);
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
		if (g.GetTag(w) == UNVISITED)
			DFS(g, w, visit);
}

//���˱���������ͨ��ͼҲҪ�����н�����
template<class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType>& g, void (*visit)(const ElemType&))
{
	int v;
	//��ʼ��������ÿһ�����㱻���Ϊδ����
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED);
	for (v = 0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED)
			DFS(g, v, visit);
}

#endif