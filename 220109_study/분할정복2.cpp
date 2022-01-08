#include<iostream>
using namespace std;
//행렬의 거듭제곱을 구하는 분할정복 알고리즘

class SquareMatrix;//그냥 임의의 정방행렬

SquareMatrix identity(int n);//n*n 크기의 항등행렬(단위행렬)을 반환하는 함수

SquareMatrix pow(const SquareMatrix& A, int m) {
	//A*0 = I
	if (m == 0) return identity(A.size());
	if (m % 2 > 0) return pow(A, m - 1) *A;
	SquareMatrix half = pow(A, m / 2);
	return half*half;
}
/*
  n*n 크기의 A행렬 m거듭제곱 A^m = A^(m/2) * A^(m/2)로 나눌 수 있다.
  만약 m이 홀수이면 A^(m-1)*A

  분할정복 1과 매우 비슷한 개념
*/