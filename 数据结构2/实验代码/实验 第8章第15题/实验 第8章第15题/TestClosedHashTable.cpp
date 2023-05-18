#include "ClosedHashTable.h"				// ɢ�б���

int main(void)
{
	ClosedHashTable<Triple, int> ht(20000);
	Triple t1(256, 344, 987);
	Triple t2(137, 899, 654);
	Triple t3(233, 455, 677);
	Triple elem[] = { t1,t2,t3 };

	for (int i = 0; i < 3; i++)
		ht.Insert(elem[i]);				// ������

	for (int i = 0; i < 3; i++) {
		cout << "�鿴t" << i-1 << "(" << elem[i].row << "," << elem[i].col << "," << elem[i].value << ")" << "�ڲ��ڱ���" << endl;
		int pos = ht.Search(elem[i]);
		if (pos != -1)
			cout << "�ҵ��ˣ���t1�ڱ��λ��Ϊ��" << pos << endl;
		else
			cout << "û�ҵ���" << endl;
	}

	system("PAUSE");
	return 0;
}

