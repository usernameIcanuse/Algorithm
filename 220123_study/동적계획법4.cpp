#include<iostream>
using namespace std;

int n, board[100][100];
bool jump(int y, int x) {
	if (y >= n || x >= n) return false;

	if (y == n - 1 && x == n - 1) return true;//마지막 칸에 도착한 경우

	int jumpSize = board[y][x];

	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}
/*
	아래로 이동하는 경우 or 오른쪽으로 이동하는 경우 재귀를 통해서 연속적으로 타고 내려감
	내려가다 보면 true가 되는 경우가 있음
	true값을 계속 반환해 true가 됨
*/