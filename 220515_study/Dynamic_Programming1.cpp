#include<iostream>
#include <algorithm>

using namespace std;

const int		MOD = 10000000007;

//���� ���Ī Ÿ�ϸ� �� ����
/*
	���� ������ Ÿ���� ���� ������ �Բ� ���߸� ��
	2*nũ�� ���δ� n�̹Ƿ� n/2���� Ÿ���� ��� ���� �ݴ��� ���� ����ָ� ��Ī�� �ǹǷ� �׷� ��츸 �����ָ� ��

	1. ���� ���� ��Ī�� ���
		- ���� ���� �κ��� ��Ī�� �Ǹ� �ȵ�

	2. ���� ���� ���Ī�� ���
		- ���� ���� �κ� ��Ī ���Ī ��� ����
*/

int cache2[101];

int		asymmetric(int width)
{
	//�ʺ� 2 �����̸� 0 ��ȯ
	if (width <= 2) return 0;//��?

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