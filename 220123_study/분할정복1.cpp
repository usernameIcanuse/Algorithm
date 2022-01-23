#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a); // (긴/짧)
	if (an == 0 || bn == 0) return vector<int>(); // 둘중 한 수가 0인 경우
	if (an <= 50) return multiply(a, b);//a가 비교적 짧은 경우 앞의 일반 multiply(각 자리의 수를 모두 곱한 다음 해당 자리에 모두 더해 자릿수를 올림하는 연산 실행)

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
	vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0); addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);

	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, 0);
	addTo(ret, z2, 0);

	return ret;
}