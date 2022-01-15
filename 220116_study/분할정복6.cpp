#include<iostream>
using namespace std;

int n;
int r, c;
int ans;

void Z(int y, int x, int size) {

	if (y==r&&x==c) {
		cout << ans << '\n';
		return;
	}
		if (r >= y && r < y + size && c >= x && c < x + size) {
			int s = size / 2;
			Z(y, x, s);
			Z(y, x + s, s);
			Z(y + s, x, s);
			Z(y + s, x + s, s);
		}
		else {
			ans += size * size; return;
		}
		
	
}

int main() {
	cin >> n >> r >> c;

	Z(0, 0, (1<<n));

	return 0;
}