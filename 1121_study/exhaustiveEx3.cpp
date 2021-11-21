/*치킨집*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int chicken[51][51];
int ans = 1000000;
int m, n;
bool closed[13];
vector<pair<int, int>> h;
vector<pair<int, int>> c;


int total() {
	int hcnt = h.size();
	int ccnt = c.size();

	int sum = 0;
	for (int i = 0; i < hcnt; i++) {
		int tmp = 1000000;
		for (int j = 0; j < ccnt; j++) {
			if (closed[j]) {
				int dist = abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second);
				tmp = min(tmp, dist);
			}
		}
		sum += tmp;
	}
	return sum;
}

void solution(int picked, int pick, int idx) {
	if (pick == picked) {
		ans = min(ans, total());
	}

	for (int i = idx; i < c.size(); i++) {
		if (!closed[i]) {
			closed[i] = true;
			solution(picked + 1, pick, i + 1);
			closed[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> chicken[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (chicken[i][j] == 1) {
				h.push_back(make_pair(i, j));
			}
			else if (chicken[i][j] == 2) {
				c.push_back(make_pair(i, j));
			}
		}


	for (int i = 0; i <= m; i++)
		solution(0, i, 0);//폐점 시키지 않을 치킨집을 고름

	cout << ans << "\n";
	return 0;
}