#include<iostream>
#include<vector>
using namespace std;
//빠른 곱셈 알고리즘
//정수를 배열 형태로 입력받음

//자릿수 올림을 처리하는 normalize
void normalize(vector<int> &num) {
	num.push_back(0);
	for (int i = 0; i + 1 < num.size(); ++i) {
		if (num[i] < 0) {
			int borrow=(abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}

/*
  ex)1234 * 5678
         
	                	 -> 1234
                          x 5678
	                    ----------
                          8 16 24 32
                       7 14 21 28
                    6 12 18 24
                 5 10 15 20
			-----------------------------
normalize ->     5 16 34 60 61 52 32
각 자리의 정수에서 십의 자리를 그다음 자리에 더해주고 10으로 나눈 나머지를 원래 자리에 저장한다.
*/