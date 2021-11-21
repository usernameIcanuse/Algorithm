/*암호 만들기*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int l, c;
char Alphabet[15];

bool condition(string &ans) {
	int len = ans.length();
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < len; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i'
			|| ans[i] == 'o' || ans[i] == 'u') {
			cnt1++;
		}
		else cnt2++;
	}
	if (cnt1 >= 1 && cnt2 >= 2) return true;
	else return false;

}

void solution(string &ans, int picked, int idx) {
	if (picked == l && condition(ans)) {
		cout << ans << "\n";
		return;
	}

	for (int i = idx; i < c; i++) {
		ans.push_back(Alphabet[i]);
		solution(ans, picked + 1, i + 1);
		ans.pop_back();
	}
}

int main() {
	string password;
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> Alphabet[i];
	sort(Alphabet, Alphabet + c);

	solution(password, 0, 0);

	return 0;
}