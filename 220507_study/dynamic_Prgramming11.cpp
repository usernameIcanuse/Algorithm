#include<iostream>
#include <algorithm>
using namespace std;
//삼각형 위의 최대 경로 개수 세기


int board[1000][1000];
int cache[1000][1000];
int n;

int		path2(int y, int x)
{
	if (n - 1 == y) return board[y][x];

	int&	ret = cache[y][x];
	if (-1 != ret) return ret;

	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + board[y][x];
}

int cache[1000][1000];

int		CountPath(int y, int x)
{
	if (n - 1 == y) return 1;//마지막에 도달했을 때는 그 위치에서 무조건 경로가 한 개라고 가정하고 시작

	int& ret = cache[y][x];
	if (-1 != ret) return ret;
	ret = 0;

	if (CountPath(y + 1, x) >= CountPath(y + 1, x + 1)) ret += CountPath(y + 1, x);
	if (CountPath(y + 1, x) <= CountPath(y + 1, x + 1)) ret += CountPath(y + 1, x+1);

	return ret;
}

int main()
{
	memset(&cache, -1, sizeof(cache));
}