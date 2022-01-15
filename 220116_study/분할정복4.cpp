#include<iostream>
using namespace std;

int tree[64][64];

void quadtree(int y, int x, int size) {
	if (size == 1) {
		cout << tree[y][x];
		return;
	}

	bool onlyzero = true, onlyone = true;
	

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tree[i][j] == 0) onlyone = false;
			if (tree[i][j] == 1) onlyzero = false;
		}
	}

	if (onlyone) {
		cout << 1; 
	}
	else if(onlyzero){
		cout << 0; 
	}

	else {
		int s = size / 2;
		cout << '(';
		quadtree(y, x, s);
		quadtree(y, x + s, s);
		quadtree(y + s, x, s);
		quadtree(y + s, x + s, s);
		cout << ')';
	}
	return;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			tree[i][j] = ch - '0';
			
		}

	quadtree(0, 0, n);

	return 0;

}