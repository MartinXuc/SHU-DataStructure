#include "AdjMatrixUndirGraph.h"

int main()
{
	try 
	{
		char vexs[] = { 'A','B','C','D','E' };
		int m[5][5] = {
			{0,1,0,1,1},
			{1,0,1,1,0},
			{0,1,0,1,1},
			{1,1,1,0,0},
			{1,0,1,0,0}
		};
		char c = '0', e, e1, e2;
		int n = 5, v, v1, v2;

		AdjMatrixUndirGraph<char> g(vexs, n, 7);

		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				if (m[u][v] == 1)
					g.InsertArc(u, v);
		while (c != '9')
		{
			cout << endl << "1、图清空";
			cout << endl << "2、显示图";
			cout << endl << "3、取指定顶点的值";
			cout << endl << "4、设置指定顶点的值";
			cout << endl << "5、删除顶点";
			cout << endl << "6、插入顶点";
			cout << endl << "7、删除边";
			cout << endl << "8、插入边";
			cout << endl << "9、退出";
			cout << endl << "选择功能(1~9)：";

			cin >> c;
			switch (c) {
			case '1':
				g.Clear();
				break;
			case '2':
				if (g.IsEmpty())
					cout << "该图为空" << endl;
				else
					g.Display();
				break;
			case '3':
				cout << "输入顶点序号(从0开始)：";
				cin >> v;
				g.GetElem(v, e);
				cout << "序号为" << v << "的顶点为：" << e;
				break;
			case '4':
				cout << "输入顶点序号(从0开始)：";
				cin >> v;
				cout << "输入想要设置的值：";
				cin >> e;
				g.SetElem(v, e);
				cout << "序号为" << v << "的顶点的值已经设置为" << e << "了" << endl;
				break;
			case '5':
				cout << "输入被删除顶点的值：";
				cin >> e;
				g.DeleteVex(e);
				cout << "值为" << e << "的顶点已经被删掉了"<<endl;
				break;
			case '6':
				cout << "输入插入顶点的值：";
				cin >> e;
				g.InsertVex(e);
				cout << "值为" << e << "的顶点插入进去了。" << endl;
				break;
			case '7':
				cout << "输入与被删除边关联的两个顶点值：";
				cin >> e1 >> e2;
				v1 = g.GetOrder(e1);
				v2 = g.GetOrder(e2);
				g.DeleteArc(v1, v2);
				cout << "值为" << e1 << "和" << e2 << "的顶点关联的边已经被删掉了"<<endl;
				break;
			case '8':
				cout << "输入与插入边关联的两个顶点值：";
				cin >> e1 >> e2;
				v1 = g.GetOrder(e1);
				v2 = g.GetOrder(e2);
				g.InsertArc(v1, v2);
				cout << "值为" << e1 << "和" << e2 << "的顶点关联的边已经连上了"<<endl;
				break;
			}
		}
	}
	catch (Error err)
	{
		err.Show();
	}
	system("PAUSE");
	return 0;
}