#ifndef BFS_H
#define BFS_H
#include"AdjMatrixUndirGraph.h"
#include"LinkQueue.h"

template<class ElemType>
void BFS(const AdjMatrixUndirGraph<ElemType>& g, int v, void(*visit)(const ElemType&))
{
	LinkQueue<int> q;
	int u, w;
	ElemType e;
	g.SetTag(v, VISITED);
	g.GetElem(v, e);
	visit(e);
	q.EnQueue(v);
	while (!q.IsEmpty())
	{
		q.DelQueue(u);
		for (w = g.FirstAdjVex(u); w != -1; w = g.NextAdjVex(u, w))
		{
			if (g.GetTag(w) == UNVISITED)
			{
				g.SetTag(w, VISITED);
				g.GetElem(w, e);
				visit(e);
				q.EnQueue(w);
			}
		}
	}
}

template<class ElemType>
void BFSTraverse(const AdjMatrixUndirGraph<ElemType>& g, void(*visit)(const ElemType&))
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED);
	for (v = 0; v < g.GetVexNum(); v++)
	{
		if (g.GetTag(v) == UNVISITED)
			BFS(g, v, visit);
	}
}

#endif