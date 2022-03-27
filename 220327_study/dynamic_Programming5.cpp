#include<iostream>
using namespace std;

//와일드 카드 다른 방법

int cache[101][101];

string S, W;

bool matchMemoized1(int w, int s)
{
	int& ret = cache[w][s];
	if (-1 != ret) return ret;


	if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized1(w + 1, s + 1);

	if (W[w] == '*')
	{
		if (matchMemoized1(w + 1, s) || (s < S.size() && matchMemoized1(w, s + 1)))
			//*를 0글자대응               //*을 한글자만 대응
			return ret = 1;
	}

	return ret = 0;
}