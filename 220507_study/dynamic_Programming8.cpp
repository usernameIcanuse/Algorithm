#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//원주율 외우기
int cache[10002];//2인경우<-3자리 문자열 길이 때문에
const int		INF = 987654321;
string N;

int	classify(int a, int b)//난이도를 반환할 함수
{
	string M = N.substr(a, b -a + 1);

	if (M == string(M.size(), M[0])) return 1; // 모두 같은 숫자로 이루어진 경우

	bool progressive = true;
	//등차 수열인지 확인할 progressive
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i] - M[i + 1] != M[0] - M[1])
			progressive = false;

	if (progressive && abs(M[0] - M[1]) == 1)
		return 2;//만약 등차수열이고 공차가 1 또는 -1 일때

	bool alternating = true;//두 수가 번갈아서 나오는지 확인할 alternating

	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;

	if (alternating) return 4;
	if (progressive) return 5;//공차가 1/-1보다 큰 등차수열일 때

	return 10;//그외 무작위의 경우

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

