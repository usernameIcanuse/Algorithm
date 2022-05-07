#include<iostream>
#include <algorithm>
using namespace std;
//�ﰢ�� ���� �ִ� ��� ���� ����


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
	if (n - 1 == y) return 1;//�������� �������� ���� �� ��ġ���� ������ ��ΰ� �� ����� �����ϰ� ����

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