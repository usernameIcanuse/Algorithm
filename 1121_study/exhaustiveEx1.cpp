/*πÈ¡ÿ ∫Ì∑¢¿Ë*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans = 0;
vector<int> card;

void MinimumSum(int n, int m, int sum, int topick, int idx) {

	if (topick == 0) {
		if (sum > m) return;
		ans = max(ans, sum);
		return;
	}

	for (int i = idx; i < n; i++) {
		MinimumSum(n, m, sum + card[i], topick - 1, i + 1);
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		card.push_back(a);
	}
	MinimumSum(n, m, 0, 3, 0);

	cout << ans << '\n';

	return 0;
}