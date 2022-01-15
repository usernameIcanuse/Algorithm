#include<iostream>
using namespace std;

void star(int y, int x, int n) {
	if (((x/ n) % 3) == 1 && ((y / n) % 3) == 1) cout << ' ';
	else {
		if (n / 3 != 0)
			star(y, x, n / 3);
		else
			cout << '*';
	}

}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			star(i, j, n);
		cout << '\n';
	}

	return 0;
}