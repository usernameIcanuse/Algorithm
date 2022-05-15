#include <iostream>
using namespace std;

int n, d, p, q;

double		cache[51][101];
//마을수 n은 50개 이하/ 날짜 수 100일 이하

int			connected[51][51] , deg[51];
//       연결된 마을이 있는지 확인, 마을 i와 연결된 마을의 개수 수
double search(int here, int days)
{
	//만약 일수가 다 되었을 때 도착을 했다면 1.0 반환 아니면 0.0 반환
	if (d == days) return (here == q) ? 1.0 : 0.0;

	double& ret = cache[here][days];
	if (-0.5 < ret) return ret;

	ret = 0.0;

	for (int there = 0; there < n; ++there)
	{
		if (connected[here][there])
		{
			ret += search(there, days + 1) / deg[here];
		}
	}

	return ret;
}