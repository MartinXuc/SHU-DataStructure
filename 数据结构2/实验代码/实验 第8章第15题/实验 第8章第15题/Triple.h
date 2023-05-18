#ifndef TRIPLE_H
#define TRIPLE_H

struct Triple {
	int row, col;//非零元素的行下标和列下标
	int value;//非零元素的值
	Triple() {
		row = 0;
		col = 0;
		value = 0;
	}
	Triple(int r, int c, int v) {
		row = r;
		col = c;
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