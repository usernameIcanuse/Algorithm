#include <iostream>
#include <algorithm>
using namespace std;
//������ �帶 ���� ��� Ȯ�� 75%
//Ȯ���� �޶����ٰ� �ص� �ش� ��ǿ��ٰ� Ȯ���� �����ֱ⸸ �ϸ� ��ü Ȯ���� ��(?)



int n, m;
int cache[100000][200001];

int climb(int days, int climbed)
{
	if (m == days) return climbed >= n ? 1 : 0;

	int& ret = cache[days][climbed];
	if (-1 != ret) return ret;

	return  ret = 0.75*climb(days + 1, climbed + 1) + 0.25*climb(days + 1, climbed + 2);
}


int main()
{
	return 0;
}