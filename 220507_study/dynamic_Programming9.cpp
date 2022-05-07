#include<iostream>
#include<algorithm>
using namespace std;

#define	INF		987654321

int n;
int cache[101][11];
        //문자 개수, 나누는 파츠(사용할 숫자)
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
	 //0.5하는 이유는 반올림 하기 위해

	int  ret = sqSum + 2 * m*Sum + m * m*(hi - lo + 1);
	return ret;

}

int Quantize(int from, int parts)
{
	//모든 숫자를 양자화 했을 때
	if (n == from) return 0;
	//부분으로 나누긴 했는데 나눠야할 숫자가 아직 있을 때
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