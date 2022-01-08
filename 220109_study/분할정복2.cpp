#include<iostream>
using namespace std;
//����� �ŵ������� ���ϴ� �������� �˰���

class SquareMatrix;//�׳� ������ �������

SquareMatrix identity(int n);//n*n ũ���� �׵����(�������)�� ��ȯ�ϴ� �Լ�

SquareMatrix pow(const SquareMatrix& A, int m) {
	//A*0 = I
	if (m == 0) return identity(A.size());
	if (m % 2 > 0) return pow(A, m - 1) *A;
	SquareMatrix half = pow(A, m / 2);
	return half*half;
}
/*
  n*n ũ���� A��� m�ŵ����� A^m = A^(m/2) * A^(m/2)�� ���� �� �ִ�.
  ���� m�� Ȧ���̸� A^(m-1)*A

  �������� 1�� �ſ� ����� ����
*/