#include<iostream>
#include<algorithm>
using namespace std;
//최대 증가 수열

int cache[100];
int S[100];
int n;

int lis(int start)
{
	int& ret = cache[start];
	if (-1 != ret) return ret;

	ret = 1;

	for (int next = start + 1; next < n; ++next)
	{
		if (S[start] < S[next])
			ret = max(ret, 1 + lis(next));
	}

	return ret;
}

int lis2(int start)
{
	int& ret = cache[start + 1];
	if (-1 != ret) return ret;

	ret = 1;

	for (int next = start + 1; next < n; ++next)
	{
		if (start == -1)
			ret = max(ret, lis2(next));

		else if (S[start] < S[next])
			ret = max(ret, lis2(next) + 1);

	}

	return ret;

}

//두 수열이 주어졌을 때

int cache2[101][101];
int A[100], B[100];
//int n;

int jlis(int indexA, int indexB)
{
	int& ret = cache2[indexA + 1][indexB + 1];
	if (-1 != ret) return ret;

	ret = 2;
	long long a = indexA == -1 ? -9999999 : A[indexA];
	long long b = indexB == -1 ? -9999999 : B[indexB];
	long long maxelement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; ++nextA)
	{
		if (maxelement < A[nextA])
		{
			if (indexB == -1)
				ret = max(ret, jlis(nextA, indexB));
			else
				ret = max(ret, jlis(nextA, indexB) + 1);

		}
	}

	for (int nextB = indexB + 1; nextB < n; ++nextB)
	{
		if (maxelement < B[nextB])
		{
			if (indexA == -1)
				ret = max(ret, jlis(indexA, nextB));
			else
				ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}

	return ret;
	//만약
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> S[i];
	cout << lis2(-1) << endl;


	/*for (int i = 0; i < n; ++i)
		cin >> A[i];

	for (int i = 0; i < n; ++i)
		cin >> B[i];*/

		//memset(cache2, -1, sizeof(cache2));

		//cout << jlis(-1, -1) << endl;


	return 0;
}