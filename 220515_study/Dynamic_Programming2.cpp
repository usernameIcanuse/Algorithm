#include <iostream>
using namespace std;

const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int poly(int n, int first)
{
	//첫 째줄에 n개로 가득 채웠을 때
	if (n == first) return 1;

	int& ret = cache[n][first];

	if (-1 != ret) return ret;

	ret = 0;

	for (int second = 1; second <= n - first; ++second)
	{
		int add = first + second - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}

	return ret;


}