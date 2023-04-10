#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include"Node.h"

template<class ElemType>
class LinkQueue
{
protected:
	Node<ElemType>* front, * rear;
public:
	LinkQueue();
	virtual ~LinkQueue();
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	Status DelQueue(ElemType& e);
	Status GetHead(ElemType& e)const;
	Status EnQueue(const ElemType e);
	LinkQueue(const LinkQueue<ElemType>& q);
	LinkQueue<ElemType>& operator=(const LinkQueue<ElemType>& q);
};

template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
{
	rear = front = new Node<ElemType>;
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
	Clear();
	delete front;
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength()const
{
	int count = 0;
	for (Node<ElemType>* p = front->next; p != NULL; p = p->next)
		count++;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty()const
{
	return rear == front;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear()
{
	Node<ElemType>* p = front->next;
	while (p != NULL)
	{
		front->next = p->next;
		delete p;
		p = front->next;
	}
	rear = front;
}

template<class ElemType>
void LinkQueue<ElemType>::Traverse(void (*Visit)(const ElemType&))const
{
	for (Node<ElemType>* p = front->next; p != NULL; p = p->next)
	{
		(*Visit)(p->data);
	}
}

template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType& e)
{
	if (!IsEmpty())
	{
		Node<ElemType>* p = front->next;
		e = p->data;
		front->next = p->next;
		if (rear == p)
			rear = front;
		delete p;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(ElemType& e)const
{
	if (!IsEmpty())
	{
		e = front->next->data;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e)
{
	Node<ElemType>* p;
	p = new Node<ElemType>(e);
	if (p)
	{
		rear->next = p;
		rear = rear->next;
		return SUCCESS;
	}
	else
		return OVER_FLOW;
}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType>& q)
{
	rear = front = new Node<ElemType>;
	for (Node<ElemType>* p = q.front->next; p != NULL; p = p->next)
	{
		EnQueue(p->data);
	}
}

template<class ElemType>
LinkQueue<ElemType>& LinkQueue<ElemType>::operator=(const LinkQueue<ElemType>& q)
{
	if (&q != this)
	{
		Clear();
		for (Node<ElemType>* p = q.front->next; p != NULL; p = p->next)
		{
			EnQueue(p->data);
		}
		return *this;
	}
}

#endif