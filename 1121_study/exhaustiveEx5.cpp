/*날짜 계산*/
#include<iostream>
using namespace std;

int main() {
	int e, s, m;
	int ne = 0, ns = 0, nm = 0;
	int year = 0;
	cin >> e >> s >> m;

	while (++year, ++ne, ++ns, ++nm) {
		if (ne > 15) ne = 1;
		if (ns > 28) ns = 1;
		if (nm > 19) nm = 1;
		if (ne == e && ns == s && nm == m) break;
	}

	cout << year << "\n";

	return 0;
}