#include<iostream>
using namespace std;

int blue, white;
int arr[128][128];

void paper(int y, int x, int size) {
	if (size == 1) {
		if (arr[y][x] == 1) blue++;
		else if (arr[y][x] == 0) white++;
		return;
	}

	bool onlyblue = true, onlywhite = true;
	for(int i=y;i<y+size;i++)
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] == 1) onlywhite = false;
			if (arr[i][j] == 0)onlyblue = false;
		}

	if (onlywhite) white++;
	else if (onlyblue) blue++;
	else {
		int s = size / 2;
		paper(y, x, s);
		paper(y, x + s, s);
		paper(y + s, x, s);
		paper(y + s, x + s, s);
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

	cout << white << '\n';
	cout << blue << '\n';

	return 0;
}