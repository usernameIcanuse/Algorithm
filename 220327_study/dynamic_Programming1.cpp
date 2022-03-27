#include<iostream>

using namespace std;

int bino(int n, int r)
{
	if (n == r || r == 0) return 1;

	return bino(n - 1, r - 1) + bino(n - 1, r);
}//런타임 에러가 발생

// 따라서 cache배열을 이용해 앞서 계산한 값을 저장하여 재활용 하도록 하자

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