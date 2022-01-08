#include<iostream>
using namespace std;
//1~n���� ���� ���ϴ� ���� ���� �˰���

int fastSum(int n) {
	if (n == 1) return 1;
	if (n % 2 == 1) return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
}

/*
  1+2+3+...+n/2 + (n/2+1) + (n/2+2) + (n/2+3) +....+(n/2 + n/2)
 fastSum(n/2)<-| |->n/2*n/2 + (1+2+3+...+n/2) == n/2*n/2 + fastSum(n/2)

 -> fastSum(n/2)*2 + n^2/4
 -> ex) 1,2,3,4,5 //n�� Ȧ���� ��
   fastSum(n-1) + n -> [1,2,3,4] + 5�� ������ ���
*/


int main() {
	int n;
	cin >> n;

	cout << fastSum(n);

	return 0;
}