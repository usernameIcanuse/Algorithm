#include<iostream>
using namespace std;

int cache[30][30];//메모이제이션

int bino2(int n, int r) {
	if (r == 0 || r == n) return 1;

	if (cache[n][r] != -1) return cache[n][r];

	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}