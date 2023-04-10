#include "Assistance.h"                // 辅助软件包
#include "BinaryTree.h"                // 二叉链表类

int main(void)
{
    BinTreeNode<char>* p, * c, * f, * l, * r;

    char e, cElem, pElem, lElem, rElem;

    e = 'A';
    BinaryTree<char> bt(e);                // 建立二叉树

    e = 'B';
    p = bt.GetRoot();
    bt.InsertLeftChild(p, e);        // 插入左孩子

    e = 'C';
    bt.InsertRightChild(p, e);        // 插入右孩子

    p = bt.LeftChild(p);
    e = 'D';
    bt.InsertLeftChild(p, e);        // 插入右孩子

    p = bt.GetRoot();
    p = bt.RightChild(p);
    e = 'E';
    bt.InsertLeftChild(p, e);        // 插入左孩子
    e = 'F';
    bt.InsertRightChild(p, e);        // 插入右孩子

    c = bt.LeftChild(p);
    bt.GetElem(p, pElem);
    bt.GetElem(c, cElem);
    cout << cElem << "双亲是" << pElem << endl;

    p = bt.GetRoot();
    bt.GetElem(p, pElem);
    r = bt.RightChild(p);              // 取根的右孩子
    p = bt.Parent(r);
    bt.GetElem(r, rElem);
    l = bt.LeftSibling(r);                // 取根的左孩子
    bt.GetElem(l, lElem);

    cout << pElem << "左孩子是" << lElem;
    cout << ", 右孩子是" << rElem << endl;
    cout << "二叉树的高是" << bt.Height() << endl;

    cout << "原树:" << endl;
    DisplayBTWithTreeShape<char>(bt);
    cout << endl;
    system("PAUSE");

    BinaryTree<char> btNew(bt);        // 复制构造新树
    cout << "复制构造新树:" << endl;
    DisplayBTWithTreeShape<char>(btNew);
    cout << endl;
    system("PAUSE");

    btNew = bt;                                        // 赋值生成新树
    cout << "赋值生成新树:" << endl;
    DisplayBTWithTreeShape<char>(btNew);
    cout << endl;
    system("PAUSE");

    cout << "结点数:" << bt.NodeCount();
    cout << endl;
    system("PAUSE");

    cout << "先序遍历:" << endl;
    bt.PreOrder(Write<char>);
    cout << endl;
    system("PAUSE");

    cout << "中序遍历:" << endl;
    bt.InOrder(Write<char>);
    cout << endl;
    system("PAUSE");

    cout << "后序遍历:" << endl;
    bt.PostOrder(Write<char>);
    cout << endl;
    system("PAUSE");

    cout << "层次遍历:" << endl;
    bt.LevelOrder(Write<char>);
    cout << endl;
    system("PAUSE");

    p = bt.GetRoot();
    bt.DeleteLeftChild(p);
    cout << "删除根的左子树后:" << endl;
    DisplayBTWithTreeShape<char>(bt);
    cout << endl;
    system("PAUSE");


    char pre[] = { 'A','B','D','E','G','H','C','F','I' }; // 先序序列
    char in[] = { 'D','B','G','E','H','A','C','F','I' };  // 中序序列
    int n = 9;                                                                  // 结点个数
    BinaryTree<char> preInbt;
    preInbt = CreateBinaryTree(pre, in, n);           // 构造二叉树

    cout << "由pre[]={'A','B','D','E','G','H','C','F','I'},in[]={'D','B','G','E','H','A','C','F','I'}构造二叉树:" << endl;
    DisplayBTWithTreeShape<char>(preInbt);
    cout << endl;

    system("PAUSE");
    return 0;
}

