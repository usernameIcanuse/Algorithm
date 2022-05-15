#include <iostream>
using namespace std;

int n, d, p, q;

double		cache[51][101];
//������ n�� 50�� ����/ ��¥ �� 100�� ����

int			connected[51][51] , deg[51];
//       ����� ������ �ִ��� Ȯ��, ���� i�� ����� ������ ���� ��
double search(int here, int days)
{
	//���� �ϼ��� �� �Ǿ��� �� ������ �ߴٸ� 1.0 ��ȯ �ƴϸ� 0.0 ��ȯ
	if (d == days) return (here == q) ? 1.0 : 0.0;

	double& ret = cache[here][days];
	if (-0.5 < ret) return ret;

	ret = 0.0;

	for (int there = 0; there < n; ++there)
	{
		if (connected[here][there])
		{
			ret += search(there, days + 1) / deg[here];
		}
	}

	return ret;
}