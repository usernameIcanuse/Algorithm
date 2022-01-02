#include<iostream>
#include<algorithm>
using namespace std;
//Επ»η
int n;
int ans;
int arr[15][2];

void Counsel(int sum, int day) {
	if (day == n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = day; i < n; i++) {
		int nsum = sum + arr[i][1];
		int nday = arr[i][0] + i;
		if (nday > n) {
			ans = max(ans, sum);
			continue;
		}
		Counsel(nsum, nday);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];

	Counsel(0, 0);

	cout << ans << "\n";

	return 0;

}