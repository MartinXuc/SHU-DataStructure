#include "ClosedHashTable.h"				// 散列表类

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
		ht.Insert(elem[i]);				// 插入结点

	for (int i = 1; i <= 3; i++) {
		cout << "查看t" << i << "(" << elem[i].row << "," << elem[i].col << "," << elem[i].value << ")" << "在不在表中" << endl;
		int pos = ht.Search(t1);
		if (pos != -1)
			cout << "找到了！，t1在表的位置为：" << endl;
		else
			cout << "没找到！" << endl;
	}
	
	system("PAUSE");			
	return 0;					
}

