#include<iostream>
using namespace std;

bool match(const string& w, const string& s)
{	//w[pos] 와 s[pos]를 비교
	int pos = 0;

	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	//while문을 벗어나면
	//1.패턴 끝에 도달 했을 때 s문자열도 끝까지 도달했으면 true
	if (pos == w.size())
		return pos == s.size(); // s끝까지 돌았으면 true 반환 아니면 false 반환

	if (w[pos] == '*')
	{
		for (int skip = 0; pos + skip < s.size(); ++skip)
		{
			if (match(w.substr(pos + 1), s.substr(pos + skip))) return true;
		}
	}

	return false; // s끝까지 갔을 때 처리를 안한 이유는
	//만약 남은 패턴 문자가 *인 경우는 위 반복문을 통해 처리되고 아닌 경우는 그냥 오답이기 떄문에
	//결론적으로 맨 밑의 false로 넘어온다.
}

int main()
{

	return 0;
}