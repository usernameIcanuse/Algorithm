#include<iostream>
#include <algorithm>

using namespace std;

const int		MOD = 10000000007;

//직접 비대칭 타일링 수 세기
/*
	직접 세려면 타일을 양쪽 끝에서 함께 맞추면 됨
	2*n크기 가로는 n이므로 n/2까지 타일을 깔면 남은 반대쪽 까지 깔아주면 대칭이 되므로 그런 경우만 없애주면 됨

	1. 양쪽 끝이 대칭일 경우
		- 남은 안쪽 부분은 대칭이 되면 안됨

	2. 양쪽 끝이 비대칭일 경우
		- 남은 안쪽 부분 대칭 비대칭 상관 없음
*/

int cache2[101];

int		asymmetric(int width)
{
	//너비가 2 이하이면 0 반환
	if (width <= 2) return 0;//왜?

	int& ret = cache2[width];
	if (-1 != ret) return ret;

	ret = asymmetric(width - 2) %MOD;
	ret = (ret + asymmetric(width - 4))%MOD;
	ret = (ret + Tiling(width - 3)) % MOD;
	ret = (ret + Tiling(width - 3)) % MOD;

	return ret;
	
}

int		Tiling(int width)
{
	if (1 >= width) return 1;

	int&	ret = cache2[width];
	if (-1 != ret) return ret;

	return ret = Tiling(width - 1) + Tiling(width - 2);
}