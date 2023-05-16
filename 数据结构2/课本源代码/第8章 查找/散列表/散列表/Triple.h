#ifndef TRIPLE_H
#define TRIPLE_H

class Triple {
	int row, col;//����Ԫ�ص����±�����±�
	int value;//����Ԫ�ص�ֵ

	Triple();
	Triple(int r, int c, int v) {
		row = r;
		c = col;
		value = v;
	}
	bool operator == (const Triple& e) {
		return this->value == e.value;
	}
	bool operator != (const Triple& e) {
		return this->value != e.value;
	}
};

#endif