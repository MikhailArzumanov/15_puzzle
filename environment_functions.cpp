#include "environment.hpp"

void set_table() {
	table = new int* [TABLE_TILES];
	for (int i = 0; i < TABLE_TILES; i++)
		table[i] = new int[TABLE_TILES];
}

void init_table() {
	for (int i = 0; i < TABLE_TILES; i++)
		for (int j = 0; j < TABLE_TILES; j++)
			table[i][j] = 4 * i + j;
	table[TABLE_TILES - 1][TABLE_TILES - 1] = SPACE_CODE;
}

bool is_it_solved() {
	for (int i = 0; i < TABLE_TILES; i++)
		for (int j = 0; j < TABLE_TILES; j++) {
			if (i == TABLE_TILES - 1 && j == TABLE_TILES - 1)
				return true;
			if (table[i][j] != 4 * i + j)
				return false;
		}
}


void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void swap(point left, point right) {
	swap(table[left.i][left.j], table[right.i][right.j]);
}