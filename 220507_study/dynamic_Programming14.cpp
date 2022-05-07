#include <iostream>
#include <algorithm>
using namespace std;
//비대칭 타일링

#define MOD		1000000007

int n;// <- 너비
int cache[100];

int tiling(int width)
{
	if (1 > width) return 1;

	int& ret = cache[width];
	if (-1 != ret) return ret;

	return ret = tiling(width - 1) + tiling(width - 2);
}
//그냥 대칭되는 것만 빼줄 때
int asymmetric(int width)
{
	if (1 == width % 2)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	//너비가 짝수일 때
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD; //중간에 뭐 없이 딱 반띵
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;//중간에 2개짜리 있을 때

	return ret;

}