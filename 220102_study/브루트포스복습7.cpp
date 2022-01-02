#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
bool flag[9] = { false };
int n;
void Picking(vector<int> arr, int picked) {
	if (picked == n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		if (flag[i]==true) continue;
		flag[i] = true;
		arr.push_back(i);
		Picking(arr, picked + 1);
		arr.pop_back();
		flag[i] = false;
	}

}


int main() {
	cin >> n;
	Picking(arr, 0);
	return 0;
}