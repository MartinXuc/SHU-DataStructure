#ifndef ADJ_LIST_DIR_NETWORK_AEC_H
#define ADJ_LIST_DIR_NETWORK_AEC_H

//邻接表网边数据类
template<class WeightType>
class AdjListNetworkArc
{
public:
	int adjVex;
	WeightType weight;
	AdjListNetworkArc<WeightType>* nextarc;

	AdjListNetworkArc();
	AdjListNetworkArc(int v, WeightType w, AdjListNetworkArc<WeightType>* next = NULL);
};

template<class WeightType>
AdjListNetworkArc<WeightType>::AdjListNetworkArc()
{
	adjVex = -1;
}

template<class WeightType>
AdjListNetworkArc<WeightType>::AdjListNetworkArc(int v, WeightType w, AdjListNetworkArc<WeightType>* next)
{
	adjVex = v;
	weight = w;
	nextarc = next;
}

#endif