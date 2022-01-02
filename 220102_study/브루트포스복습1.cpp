#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//백준 연산자끼우기
int oprtr[4];
char operate[4] = { '+','-','*','/' };
int Min = 999999999, Max = -999999999;
int num[11];
int n;


int Answer(vector<char> &a) {
	int length = a.size();
	int tmp = num[0];
	int idx = 0;
	for (int i = 1; i < n; i++) {
		switch (a[idx]) {
		case '+':
			tmp += num[i]; break;
		case '-':
			tmp -= num[i]; break;
		case '*':
			tmp *= num[i]; break;
		case '/':
			tmp /= num[i]; break;
		}
		idx++;
	}
	//cout << "Sum = " << tmp << "\n";
	return tmp;
}

void Calculate(vector<char> &a, int cnt) {
	if (cnt == n - 1) {

		int ans = Answer(a);
		Min = min(Min, ans);
		Max = max(Max, ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oprtr[i] > 0) {
			oprtr[i]--;
			a.push_back(operate[i]);
			Calculate(a, cnt + 1);
			a.pop_back();
			oprtr[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> oprtr[i];

	vector<char> o;
	Calculate(o, 0);

	cout << Max << "\n" << Min << "\n";

	return 0;
}