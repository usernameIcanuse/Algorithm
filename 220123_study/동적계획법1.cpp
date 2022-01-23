#include<iostream>
using namespace std;

//재귀호출을 이용한 이항 계수

int bino(int n, int r) {
	if (r == 0 || n == r) return 1;
	return bino(n - 1, r - 1) + bino(n - 1, r);
}