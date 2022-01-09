#include<iostream>
using namespace std;
//백준 쿼드트리
char image[64][64];

void quadTree(int y, int x, int size) {
	if (size / 2 == 0) {
		cout<<image[y][x];
		return;
	}

	bool zero = true, one = true;
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			if (image[i][j] == '0') one = false;
			else if(image[i][j]=='1') zero = false;
    
	if (zero) cout << 0;
	else if (one) cout << 1;


	else {
		cout << '(';
		int half = size / 2;
		quadTree(y, x, half);
		quadTree(y, x + half, half);
		quadTree(y + half, x, half);
		quadTree(y + half, x + half, half);
		cout << ')';
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> image[i];

	quadTree(0, 0, n);

	return 0;
}