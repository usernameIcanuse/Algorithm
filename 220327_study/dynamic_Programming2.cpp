#include<iostream>
using namespace std;

int n, int board[100][100];
int cache[100][100];
//메모이제이션으로 길찾기
/*
	특정 지점에서 도착지점을 도달할 수 있으면 다른 곳에서 그 특정지점으로 갈 수 있기만 해도 도착지점을 갈 수 있다.
	따라서 그 후의 중복으로 갈 수 있는지 경우를 다시 계산할 필요 없이 특정 지점에서 도달할 수 있는지만 cache배열에 저장해 놓고
	계산 량을 줄일 수 있다.
*/
int jump(int y, int x)
{
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;


	int& ret = cache[y][x];
	if (-1 != ret) return ret;

	int jumpsize = board[y][x];

	return cache[y][x] = jump(y + jumpsize, x) || jump(y, x + jumpsize);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	return 0;
}