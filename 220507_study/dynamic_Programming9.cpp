#include<iostream>
#include<algorithm>
using namespace std;

#define	INF		987654321

int n;
int cache[101][11];
        //���� ����, ������ ����(����� ����)
int pSum[101], psqSum[101], A[101];


void precale()
{
	sort(A, A + n);
	pSum[0] = A[0];
	psqSum[0] = A[0] * A[0];

	for (int i = 1; i < n; ++i)
	{
		pSum[i] = pSum[i - 1] + A[i];
		psqSum[i] = psqSum[i - 1] + A[i] * A[i];
	}
}

int minError(int lo, int hi)
{
	int Sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = psqSum[hi] - (lo == 0 ? 0 : psqSum[lo - 1]);

	int m = (int)(0.5 + (double)Sum) / (hi - lo + 1);
	 //0.5�ϴ� ������ �ݿø� �ϱ� ����

	int  ret = sqSum + 2 * m*Sum + m * m*(hi - lo + 1);
	return ret;

}

int Quantize(int from, int parts)
{
	//��� ���ڸ� ����ȭ ���� ��
	if (n == from) return 0;
	//�κ����� ������ �ߴµ� �������� ���ڰ� ���� ���� ��
	if (0 == parts) return INF;

	int& ret = cache[from][parts];
	if (-1 != ret) return ret;

	for (int partSize = 1; partSize + from <= n; ++partSize)
	{
		ret = min(ret, minError(from, from + partSize - 1) + Quantize(from + partSize, parts - 1));
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	precale();
	Quantize(0, 0);
	return 0;
}