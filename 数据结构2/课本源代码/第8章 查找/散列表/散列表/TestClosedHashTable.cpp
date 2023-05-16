#include "ClosedHashTable.h"				// ɢ�б���

int main(void)
{
	ClosedHashTable<Triple,int> ht(20000);
	Triple t1(256, 344, 987);
	Triple t2(137, 899, 654);
	Triple t3(233, 455, 677);
	Triple elem[] = { t1,t2,t3 };
	int k, n = 12;
	Status state;
	
	for (int i = 0; i < n; i++)
		ht.Insert(elem[i]);				// ������

	for (int i = 1; i <= 3; i++) {
		cout << "�鿴t" << i << "(" << elem[i].row << "," << elem[i].col << "," << elem[i].value << ")" << "�ڲ��ڱ���" << endl;
		int pos = ht.Search(t1);
		if (pos != -1)
			cout << "�ҵ��ˣ���t1�ڱ��λ��Ϊ��" << endl;
		else
			cout << "û�ҵ���" << endl;
	}
	
	system("PAUSE");			
	return 0;					
}

