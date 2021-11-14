#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*�����ϴ� ���ǿ�*/
int n;
double dist[10][10];//�� ���ð��� �Ÿ� �����ϴ� �迭

double shortestPath(vector<int>& path, vector<bool>& visited, double currentlength) {
	if (path.size() == n)
		return currentlength + dist[path[0]][path.back()];//������ ���ÿ��� �ٽ� ó�� ���÷� ���ƿ� �Ÿ� �������

	double ret = 999999999;

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;//�湮�� ������ �ƴ��� Ȯ��
		int here = path.back();
		path.push_back(next);//���� �湮�� ���� �־��ֱ�
		visited[next] = true;//���� �湮�� ���� �湮�ߴٰ� ǥ��

		double cand = shortestPath(path, visited, currentlength + dist[here][next]);

		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back()//�������

	}
	return ret;
}