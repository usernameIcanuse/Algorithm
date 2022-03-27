#include<iostream>
#include<algorithm>
using namespace std;

int board[100][100];
int cache[100][100][10000];

int n;
//시작은 맨 위에서지만 계산 값은 맨 아래에서 부터 해당 위치까지 sum을 구해 위로 가져가며 최대값을 반환
//만약 위치에서의 값이 모두 다르다면 결국에는 전체 경로를 계산해야하는 완전 탐색 문제가 됨
int path(int y, int x, int sum)
{
	if (y == n) return sum + board[y][x];

	int& ret = cache[y][x][sum];
	if (-1 != ret) return ret;

	sum += board[y][x];

	return ret = max(path(y + 1, x, sum), path(y + 1, x + 1, sum));
}

//시작 맨 위에부터 아래로 내려가면서 그 도달한 부분까지의 최대 합을 구함
int cache2[100][100];

int path2(int y, int x)
{
	if (y == n - 1) return board[y][x];

	int& ret = cache2[y][x];
	if (-1 != ret) return ret;

	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + board[y][x];
}