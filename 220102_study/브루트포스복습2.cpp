#include<iostream>
#include<algorithm>
using namespace std;
//Ã¼½ºÆÇ
char black[8][8] = { {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'} };
char white[8][8] = {
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'} };
char board[50][50];


int Wchess(int x, int y) {
	int sum = 0;

	for (int i = x; i < x + 8; i++)
		for (int j = y; j < y + 8; j++)
			if (board[i][j] != white[i - x][j - y]) sum++;


	return sum;
}

int Bchess(int x, int y) {
	int sum = 0;

	for (int i = x; i < x + 8; i++)
		for (int j = y; j < y + 8; j++)
			if (board[i][j] != black[i - x][j - y]) sum++;


	return sum;
}

int main() {
	int x, y;
	int sum = 999999;
	cin >> x >> y;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> board[i][j];

	for (int i = 0; i <= x - 8; i++)
		for (int j = 0; j <= y - 8; j++) {
			sum = min(sum, min(Wchess(i, j), Bchess(i, j)));
		}

	cout << sum << '\n';
}