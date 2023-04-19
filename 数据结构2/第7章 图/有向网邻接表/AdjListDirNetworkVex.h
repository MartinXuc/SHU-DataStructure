#ifndef ADJ_LIST_DIR_NETWORK_VEX_H
#define ADJ_LIST_DIR_NETWORK_VEX_H

template<class ElemType,class WeightType>
class AdjListNetworkVex
{
public:
	ElemType data;
	AdjListNetworkArc<WeightType>* firstarc;
	AdjListNetworkVex();
	AdjListNetworkVex(ElemType val, AdjListNetworkArc<WeightType>* adj = NULL);
};

template<class ElemType,class WeightType>
AdjListNetworkVex<ElemType, WeightType>::AdjListNetworkVex()
{
	firstarc = NULL;
}

template<class ElemType,class WeightType>
AdjListNetworkVex<ElemType, WeightType>::AdjListNetworkVex(ElemType val, AdjListNetworkArc<WeightType>* adj)
{
	data = val;
	firstarc = adj;
}

#endif