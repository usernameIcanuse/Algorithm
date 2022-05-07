#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//������ �ܿ��
int cache[10002];//2�ΰ��<-3�ڸ� ���ڿ� ���� ������
const int		INF = 987654321;
string N;

int	classify(int a, int b)//���̵��� ��ȯ�� �Լ�
{
	string M = N.substr(a, b -a + 1);

	if (M == string(M.size(), M[0])) return 1; // ��� ���� ���ڷ� �̷���� ���

	bool progressive = true;
	//���� �������� Ȯ���� progressive
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i] - M[i + 1] != M[0] - M[1])
			progressive = false;

	if (progressive && abs(M[0] - M[1]) == 1)
		return 2;//���� ���������̰� ������ 1 �Ǵ� -1 �϶�

	bool alternating = true;//�� ���� �����Ƽ� �������� Ȯ���� alternating

	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;

	if (alternating) return 4;
	if (progressive) return 5;//������ 1/-1���� ū ���������� ��

	return 10;//�׿� �������� ���

}

int memoized(int begin)
{
	if (begin == N.size()) return 0;

	int& ret = cache[begin];
	if (-1 != ret) return ret;

	ret = INF;

	for (int L = 3; L <= 5; ++L)
	{
		ret = min(ret, classify(begin,begin+L-1)+memoized(begin + L));
	}

	return ret;

}

