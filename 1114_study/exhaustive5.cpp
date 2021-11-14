#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*여행하는 외판원*/
int n;
double dist[10][10];//두 도시간의 거리 저장하는 배열

double shortestPath(vector<int>& path, vector<bool>& visited, double currentlength) {
	if (path.size() == n)
		return currentlength + dist[path[0]][path.back()];//마지막 도시에서 다시 처음 도시로 돌아올 거리 더해쥐기

	double ret = 999999999;

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;//방문한 곳인지 아닌지 확인
		int here = path.back();
		path.push_back(next);//다음 방문할 도시 넣어주기
		visited[next] = true;//다음 방문할 도시 방문했다고 표시

		double cand = shortestPath(path, visited, currentlength + dist[here][next]);

		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back()//원래대로

	}
	return ret;
}