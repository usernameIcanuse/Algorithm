#include<iostream>
using namespace std;

const int MOD = 1000000007;
int cache[101];


int tiling(int width)
{
	if (1 >= width) return 1;//<-1���ϴ� -1-2 �ؼ� Ȧ���� �Q�� �� ��찡 �־

	int ret = cache[width];
	if (-1 != ret) return ret;

	return ret = tiling(width - 1) + tiling(width - 2);
}


int main()
{
	memset(cache, -1, sizeof(cache));
	return 0;
}