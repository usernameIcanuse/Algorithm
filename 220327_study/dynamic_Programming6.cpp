#include<iostream>
#include<algorithm>
using namespace std;

int board[100][100];
int cache[100][100][10000];

int n;
//������ �� ���������� ��� ���� �� �Ʒ����� ���� �ش� ��ġ���� sum�� ���� ���� �������� �ִ밪�� ��ȯ
//���� ��ġ������ ���� ��� �ٸ��ٸ� �ᱹ���� ��ü ��θ� ����ؾ��ϴ� ���� Ž�� ������ ��
int path(int y, int x, int sum)
{
	if (y == n) return sum + board[y][x];

	int& ret = cache[y][x][sum];
	if (-1 != ret) return ret;

	sum += board[y][x];

	return ret = max(path(y + 1, x, sum), path(y + 1, x + 1, sum));
}

//���� �� �������� �Ʒ��� �������鼭 �� ������ �κб����� �ִ� ���� ����
int cache2[100][100];

int path2(int y, int x)
{
	if (y == n - 1) return board[y][x];

	int& ret = cache2[y][x];
	if (-1 != ret) return ret;

	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + board[y][x];
}