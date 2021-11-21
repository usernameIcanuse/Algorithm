/*¿œ∞ˆ ≥≠¿Ô¿Ã*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int h[9];
int flag = false;

int Sum(const vector<int> &a) {
	int sum = 0;
	for (int i = 0; i < 7; i++)
		sum += a[i];
	return sum;
}

void dwarf(vector<int> &a, int topick, int idx) {
	if (topick == 7) {
		if (Sum(a) == 100 && (!flag)) {
			sort(a.begin(), a.end());
			for (int i = 0; i < 7; i++)
				cout << a[i] << " ";
			flag = true;
		}
		return;
	}
	for (int i = idx; i < 9; i++) {
		a.push_back(h[i]);
		dwarf(a, topick + 1, i + 1);
		a.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> total;

	for (int i = 0; i < 9; i++)
		cin >> h[i];

	dwarf(total, 0, 0);

	return 0;
}