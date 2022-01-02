#include<iostream>
#include<algorithm>
using namespace std;
//부분수열
int n, s;
int arr[20];
int ans = 0;


void solution(int idx, int sum) {
	sum += arr[idx]; if (idx >= n) return;
	if (sum == s) { ++ans; }

	solution(idx + 1, sum);
	solution(idx + 1, sum - arr[idx]);
}

int main() {

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solution(0, 0);
	cout << ans << "\n";
	return 0;

}