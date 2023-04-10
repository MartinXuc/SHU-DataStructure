#ifndef __PARENT_TREE_H__
#define __PARENT_TREE_H__

#include "Assistance.h"
#include "Node.h"
#include "ParentTreeNode.h"

// 双亲表示法表示的树类
template <class ElemType>
class ParentTree
{
public:
    // 构造函数
    ParentTree();
    ParentTree(const ElemType &elem);
    ParentTree(const ParentTree<ElemType> &tree);

    // 析构函数
    ~ParentTree();

    // 操作函数
    void Clear();
    bool IsEmpty() const;
    int GetRoot() const;
    int GetParent(int pos) const;
    bool SetElem(int pos, const ElemType &elem);
    ElemType GetElem(int pos) const;

private:
    // 数据成员
    ParentTreeNode<ElemType> *nodes; // 结点数组
    int length;                      // 结点个数
    int maxSize;                     // 结点数组的最大长度

    // 辅助函数
    int GetNodePos(const ParentTreeNode<ElemType> *node) const;
    void CopyTree(const ParentTree<ElemType> &tree);
};

template <class ElemType>
ParentTree<ElemType>::ParentTree()
// 操作结果：构造空树
{
    length = 0;
    maxSize = DEFAULT_SIZE;
    nodes = new ParentTreeNode<ElemType>[maxSize];
}

template <class ElemType>
ParentTree<ElemType>::ParentTree(const ElemType &elem)
// 操作结果：构造只有根结点的树
{
    length = 1;
    maxSize = DEFAULT_SIZE;
    nodes = new ParentTreeNode<ElemType>[maxSize];
    nodes[0].data = elem;
    nodes[0].parent = -1;
}

template <class ElemType>
ParentTree<ElemType>::ParentTree(const ParentTree<ElemType> &tree)
// 操作结果：复制构造函数
{
    nodes = NULL;
    CopyTree(tree);
}

template <class ElemType>
ParentTree<ElemType>::~ParentTree()
// 操作结果：析构函数，删除结点数组
{
    delete[] nodes;
}

template <class ElemType>
void ParentTree<ElemType>::Clear()
// 操作结果：清空树，即将结点个数重置为0
{
    length = 0;
}

template <class ElemType>
bool ParentTree<ElemType>::IsEmpty() const
// 操作结果：判断树是否为空
{
    return length == 0;
}
template <class ElemType>
int ParentTree<ElemType>::GetRoot() const
// 操作结果：返回树的根结点在结点向量中的下标，若树为空树，返回-1
{
    if (length == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < maxSize; i++)
        {
            if (nodes[i].parent == -1)
            {
                return i;
            }
        }
        return -1;
    }
}
template <class ElemType>
int ParentTree<ElemType>::GetParent(int pos) const
// 操作结果：返回结点位置为pos的结点的双亲位置，如果该结点没有双亲，则返回-1
{
    if (pos < 0 || pos >= length)
    { // 位置越界
        return -1;
    }
    return nodes[pos].parent; // 返回双亲位置
}
template <class ElemType>
bool ParentTree<ElemType>::SetElem(int pos, const ElemType &elem)
// 操作结果：将树中位置为pos的结点的值设置为elem
{
    if (pos < 0 || pos >= length)
    {
        return false;
    }
    nodes[pos].data = elem;
    return true;
}
template <class ElemType>
ElemType ParentTree<ElemType>::GetElem(int pos) const
// 操作结果：返回结点pos的数据元素值
{
    if (pos < 0 || pos >= length)
    {
        cerr << "pos值超出范围！" << endl;
        exit(1);
    }
    return nodes[pos].data;
}
template <class ElemType>
int ParentTree<ElemType>::GetNodePos(const ParentTreeNode<ElemType> *node) const
{
    for (int i = 0; i < length; i++)
    {
        if (nodes[i] == node)
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType>
void ParentTree<ElemType>::CopyTree(const ParentTree<ElemType> &tree)
// 操作结果：将树tree复制到当前树--已存在的树被销毁
{
    if (&tree != this)
    {
        DestroyTree(); // 销毁当前树
        if (!tree.IsEmpty())
        {
            elemList = new ElemType[tree.treeSize];
            parent = new int[tree.treeSize];
            nodeTable = new ParentTreeNode<ElemType>[tree.treeSize];
            treeSize = tree.treeSize;
            rootNode = tree.rootNode;
            for (int i = 0; i < tree.treeSize; ++i)
            {
                elemList[i] = tree.elemList[i];
                parent[i] = tree.parent[i];
                nodeTable[i].data = &elemList[i];
                nodeTable[i].parent = &parent[i];
            }
        }
    }
}

#endif