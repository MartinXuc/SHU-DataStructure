#include "ClosedHashTable.h"				// 散列表类

int main(void)
{
	ClosedHashTable<Triple, int> ht(20000);
	Triple t1(256, 344, 987);
	Triple t2(137, 899, 654);
	Triple t3(233, 455, 677);
	Triple elem[] = { t1,t2,t3 };

	for (int i = 0; i < 3; i++)
		ht.Insert(elem[i]);				// 插入结点

	for (int i = 0; i < 3; i++) {
		cout << "查看t" << i-1 << "(" << elem[i].row << "," << elem[i].col << "," << elem[i].value << ")" << "在不在表中" << endl;
		int pos = ht.Search(elem[i]);
		if (pos != -1)
			cout << "找到了！，t1在表的位置为：" << pos << endl;
		else
			cout << "没找到！" << endl;
	}

	system("PAUSE");
	return 0;
}

