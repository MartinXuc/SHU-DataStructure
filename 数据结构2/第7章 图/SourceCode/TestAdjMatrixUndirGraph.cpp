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
			cout << endl << "1��ͼ���";
			cout << endl << "2����ʾͼ";
			cout << endl << "3��ȡָ�������ֵ";
			cout << endl << "4������ָ�������ֵ";
			cout << endl << "5��ɾ������";
			cout << endl << "6�����붥��";
			cout << endl << "7��ɾ����";
			cout << endl << "8�������";
			cout << endl << "9���˳�";
			cout << endl << "ѡ����(1~9)��";

			cin >> c;
			switch (c) {
			case '1':
				g.Clear();
				break;
			case '2':
				if (g.IsEmpty())
					cout << "��ͼΪ��" << endl;
				else
					g.Display();
				break;
			case '3':
				cout << "���붥�����(��0��ʼ)��";
				cin >> v;
				g.GetElem(v, e);
				cout << "���Ϊ" << v << "�Ķ���Ϊ��" << e;
				break;
			case '4':
				cout << "���붥�����(��0��ʼ)��";
				cin >> v;
				cout << "������Ҫ���õ�ֵ��";
				cin >> e;
				g.SetElem(v, e);
				cout << "���Ϊ" << v << "�Ķ����ֵ�Ѿ�����Ϊ" << e << "��" << endl;
				break;
			case '5':
				cout << "���뱻ɾ�������ֵ��";
				cin >> e;
				g.DeleteVex(e);
				cout << "ֵΪ" << e << "�Ķ����Ѿ���ɾ����"<<endl;
				break;
			case '6':
				cout << "������붥���ֵ��";
				cin >> e;
				g.InsertVex(e);
				cout << "ֵΪ" << e << "�Ķ�������ȥ�ˡ�" << endl;
				break;
			case '7':
				cout << "�����뱻ɾ���߹�������������ֵ��";
				cin >> e1 >> e2;
				v1 = g.GetOrder(e1);
				v2 = g.GetOrder(e2);
				g.DeleteArc(v1, v2);
				cout << "ֵΪ" << e1 << "��" << e2 << "�Ķ�������ı��Ѿ���ɾ����"<<endl;
				break;
			case '8':
				cout << "���������߹�������������ֵ��";
				cin >> e1 >> e2;
				v1 = g.GetOrder(e1);
				v2 = g.GetOrder(e2);
				g.InsertArc(v1, v2);
				cout << "ֵΪ" << e1 << "��" << e2 << "�Ķ�������ı��Ѿ�������"<<endl;
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