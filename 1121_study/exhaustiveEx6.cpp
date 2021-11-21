/*영화 감독*/
#include<iostream>
#include<string>//문자열로 만들어서 안에 666부분문자열이 있는지 확인
using namespace std;


int main() {
	int n;
	int num = 665;
	int cnt = 0;
	cin >> n;
	string s;

	while (++num) {
		s = to_string(num);

		if (s.find("666") != -1) {
			++cnt;
		}
		if (cnt == n) {
			cout << num << "\n";
			break;
		}
	}

	return 0;
}