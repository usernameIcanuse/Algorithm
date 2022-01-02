#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//스타트링크
int ans = 999999;
int arr[21][21];
int n;
bool Team[21] = { false };//true가 스타크 false가 링크

int Calculate() {
	int ssum = 0;
	int lsum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Team[i]) {
				if (Team[j]) ssum += arr[i][j];
			}
			else {
				if (!Team[j]) lsum += arr[i][j];
			}
		}
	}
	
	return abs(ssum - lsum);

}

void Seperate(int idx, int cnt) {
	if (cnt == n / 2) {
		ans = min(ans, Calculate());
		return;
	}
	for (int i = idx; i <= n; i++) {
		Team[i] = true;
		Seperate(i + 1, cnt + 1);
		Team[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	Seperate(1, 0);

	cout << ans << "\n";
	return 0;

}
