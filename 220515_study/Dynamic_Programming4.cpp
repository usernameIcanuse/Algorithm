#include <iostream>
using namespace std;

int n, d, p, q;
double cache[51][101];

int connected[51][51], deg[51];
//days일째 here에 있을 확률

//시작부터 ~ 끝 : 0일 ++...d일
//끝 ~ 시작: d일 -- ... 0일
//끝 부분을 아예 도착했다고 가정 후 1일씩 뒤로 가서 처음 시작으로 감
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
			ret += search2(there, days - 1) / deg[here];//끝에서부터 확인을 할 때는 -1씩 해줌
		}
	}

	return ret;
}