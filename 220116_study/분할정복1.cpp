#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> h;
/* 기저 사례 1: 큰 직사각형이 왼쪽에
   기저 사례 2: 큰 직사각형이 오른쪽에 
   기저 사례 3: 큰 직사각형이 오른쪽 왼쪽에 걸쳐 있음*/


int solve(int left, int right) {
	// 기저 사례1: 판자가 1개인 경우
	if (left == right) return h[left];
	//두 구간으로 나눔 left ~ mid / mid+1 ~ right
	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));
	
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);

	ret = max(ret, height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		ret = max(ret, height*(hi - lo + 1));
	}

	return ret;
}