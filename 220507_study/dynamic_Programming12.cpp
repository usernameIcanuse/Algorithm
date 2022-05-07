#include <iostream>
#include <algorithm>
using namespace std;

//달팽이가 우물을 올라갈 수 있는 확률

int n, m;//n미터를 m일 동안 올라감

int cache[100000][200001];//[Max_N][2*Max_N+1] <- 열은 2* +1 하는 이유는

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