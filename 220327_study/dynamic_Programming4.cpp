#include<iostream>
using namespace std;

//와일드카드

int cache[101][101];//int를 사용하는 이유는 계산을 안 했다는 -1을 사용하기 위해

string W, S;

bool matchMemoized(int w, int s)
{
	//먼저 ret인 경우를 처리한다.
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
	{
		++w; ++s;
	}
	//*이면 문자열 중간에 반복문 탈출
	if (w == W.size()) return ret = (s == S.size());
	//만약 패턴 끝까지 갔을 때 s도 끝까지 갔다면 true 그렇지 않으면 false

	//*만났을 때
	if (W[w] == '*')
	{
		for (int skip = 0; s + skip <= S.size(); ++skip)
		{
			if (matchMemoized(w + 1, s + skip))
				//패턴 *바로 다음부터 s는 skip 다음까지
				//skip하는 정도가 *에 대응하는 0이상 길이의 문자열
				return ret = 1;
		}
	}
	//패턴이 남았는데 s는 끝까지 간 경우라면 남은 패턴이 *이 아니면 false이므로 자동으로 마지막 부분 도달
	return ret = 0;
}