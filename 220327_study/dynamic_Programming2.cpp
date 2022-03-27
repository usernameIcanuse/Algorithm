#include<iostream>
using namespace std;

int n, int board[100][100];
int cache[100][100];
//�޸������̼����� ��ã��
/*
	Ư�� �������� ���������� ������ �� ������ �ٸ� ������ �� Ư���������� �� �� �ֱ⸸ �ص� ���������� �� �� �ִ�.
	���� �� ���� �ߺ����� �� �� �ִ��� ��츦 �ٽ� ����� �ʿ� ���� Ư�� �������� ������ �� �ִ����� cache�迭�� ������ ����
	��� ���� ���� �� �ִ�.
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