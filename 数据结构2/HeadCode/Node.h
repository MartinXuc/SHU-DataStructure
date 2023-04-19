#ifndef NODE_H
#define NODE_H
#include"Assistance.h"

template<class ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next;
	Node();
	Node(ElemType item, Node<ElemType>* link = NULL);
};

template<class ElemType>
Node<ElemType>::Node()
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link)
{
	data = item;
	next = link;
}

#endif