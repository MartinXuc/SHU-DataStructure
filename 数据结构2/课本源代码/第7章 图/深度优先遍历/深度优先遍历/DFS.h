#ifndef DFS_H
#define DFS_H

#include "AdjMatrixUndirGraph.h"

//此乃搜索，若不连通，则搜不到
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

//此乃遍历，不连通的图也要把所有结点访问
template<class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType>& g, void (*visit)(const ElemType&))
{
	int v;
	//初始化，先让每一个顶点被标记为未访问
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED);
	for (v = 0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED)
			DFS(g, v, visit);
}

#endif