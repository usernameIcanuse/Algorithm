#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//카라츠바의 빠른 정수 곱셈 알고리즘

//a+=b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k);
//a-=b;
void subFrom(vector<int>& a, const vector<int>& b);
//두 긴 정수의 곱을 반환한다.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	//a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn) return karatsuba(b, a);
	//a or b is empty
	if (an == 0 || bn == 0) return vector<int>();//비어있는 벡터 반환
	//a가 비교적 짧은 경우 분할정복3의 곱셈으로
	if (an <= 50) return multiply(a, b);//분할정복3
	int half = an / 2;

	//a와 b를 밑에서 half자리와 나머지로 분리한다.
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2 = a1*b1;
	vector<int> z2 = karatsuba(a1, b1);
	//z0 = a0*b0;
	vector<int> z0 = karatsuba(a0, b0);
	//a0 = a0 +a1; b0=b0+b1;
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	//z1 = (a0*b0)-z0-z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	//ret = z0 + z1*10*half + z2*10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}