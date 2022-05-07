#include <iostream>
#include <algorithm>
using namespace std;
//달팽이 장마 버전 비올 확률 75%
//확률이 달라진다고 해도 해당 사건에다가 확률을 곱해주기만 하면 전체 확률이 됨(?)



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