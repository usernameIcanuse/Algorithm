#include <iostream>
#include <algorithm>
using namespace std;
//���Ī Ÿ�ϸ�

#define MOD		1000000007

int n;// <- �ʺ�
int cache[100];

int tiling(int width)
{
	if (1 > width) return 1;

	int& ret = cache[width];
	if (-1 != ret) return ret;

	return ret = tiling(width - 1) + tiling(width - 2);
}
//�׳� ��Ī�Ǵ� �͸� ���� ��
int asymmetric(int width)
{
	if (1 == width % 2)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	//�ʺ� ¦���� ��
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD; //�߰��� �� ���� �� �ݶ�
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;//�߰��� 2��¥�� ���� ��

	return ret;

}