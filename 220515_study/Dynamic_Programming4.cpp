#include <iostream>
using namespace std;

int n, d, p, q;
double cache[51][101];

int connected[51][51], deg[51];
//days��° here�� ���� Ȯ��

//���ۺ��� ~ �� : 0�� ++...d��
//�� ~ ����: d�� -- ... 0��
//�� �κ��� �ƿ� �����ߴٰ� ���� �� 1�Ͼ� �ڷ� ���� ó�� �������� ��
double	search2(int here, int days)
{
	if (0 == days) return here == p ? 1.0 : 0.0;

	double& ret = cache[here][days];
	if (-0.5 < ret) return ret;

	ret = 0.0;

	for (int there = 0; there < n; ++there)
	{
		if (connected[here][there])
		{
			ret += search2(there, days - 1) / deg[here];//���������� Ȯ���� �� ���� -1�� ����
		}
	}

	return ret;
}