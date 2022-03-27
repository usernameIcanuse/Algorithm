#include<iostream>

using namespace std;

int bino(int n, int r)
{
	if (n == r || r == 0) return 1;

	return bino(n - 1, r - 1) + bino(n - 1, r);
}//��Ÿ�� ������ �߻�

// ���� cache�迭�� �̿��� �ռ� ����� ���� �����Ͽ� ��Ȱ�� �ϵ��� ����

int cache[30][30];

int bino2(int n, int r)
{
	if (n == r || r == 0) return 1;

	if (cache[n][r] != 0)
		return cache[n][r];

	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);

}


int main()
{
	memset(cache, -1, sizeof(cache));
	return 0;
}