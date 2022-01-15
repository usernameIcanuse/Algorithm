#include<iostream>
using namespace std;

int arr[2187][2187];
int nmone, nzero, none;

void paper(int y, int x, int size) {
	if (size == 1) {
		if (arr[y][x] == -1) nmone++;
		else if (arr[y][x] == 0) nzero++;
		else if (arr[y][x] == 1) none++;

		return;
	}

	bool onlyzero = true, onlymone = true, onlyone = true;

	for(int i=y;i<y+size;i++)
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] == -1) { onlyone = false; onlyzero = false; }
			else if (arr[i][j] ==1) { onlymone = false; onlyzero = false; }
			else if (arr[i][j] == 0) { onlyone = false; onlymone = false; }
		}

	if (onlyzero) { nzero++; }
	else if (onlymone) { nmone++;}
	else if (onlyone) { none++; }
	else {
		int s = size / 3;
		paper(y, x, s);
		paper(y, x + s, s);
		paper(y, x + 2 * s, s);
		paper(y + s, x, s);
		paper(y + s, x + s, s);
		paper(y + s, x + 2 * s, s);
		paper(y + s * 2, x, s);
		paper(y + s * 2, x + s, s);
		paper(y + s * 2, x + s * 2, s);
	}
	return;
}


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	paper(0, 0, n);

	cout << nmone << '\n';
	cout << nzero << '\n';
	cout << none << '\n';
	return 0;
}