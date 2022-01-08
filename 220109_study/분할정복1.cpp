#include<iostream>
using namespace std;
//1~n까지 합을 구하는 분할 정복 알고리즘

int fastSum(int n) {
	if (n == 1) return 1;
	if (n % 2 == 1) return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
}

/*
  1+2+3+...+n/2 + (n/2+1) + (n/2+2) + (n/2+3) +....+(n/2 + n/2)
 fastSum(n/2)<-| |->n/2*n/2 + (1+2+3+...+n/2) == n/2*n/2 + fastSum(n/2)

 -> fastSum(n/2)*2 + n^2/4
 -> ex) 1,2,3,4,5 //n이 홀수일 때
   fastSum(n-1) + n -> [1,2,3,4] + 5로 나눠서 계산
*/


int main() {
	int n;
	cin >> n;

	cout << fastSum(n);

	return 0;
}