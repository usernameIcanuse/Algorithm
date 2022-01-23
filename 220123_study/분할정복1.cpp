#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a); // (��/ª)
	if (an == 0 || bn == 0) return vector<int>(); // ���� �� ���� 0�� ���
	if (an <= 50) return multiply(a, b);//a�� ���� ª�� ��� ���� �Ϲ� multiply(�� �ڸ��� ���� ��� ���� ���� �ش� �ڸ��� ��� ���� �ڸ����� �ø��ϴ� ���� ����)

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