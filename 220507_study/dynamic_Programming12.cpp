#include <iostream>
#include <algorithm>
using namespace std;

//�����̰� �칰�� �ö� �� �ִ� Ȯ��

int n, m;//n���͸� m�� ���� �ö�

int cache[100000][200001];//[Max_N][2*Max_N+1] <- ���� 2* +1 �ϴ� ������

int climb(int days, int climbed)
{
	if (m == days) return climbed >= n ? 1 : 0;

	int& ret = cache[days][climbed];
	if (-1 != ret) return ret;

	return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}


int main()
{
	memset(&cache, -1, sizeof(cache));
}