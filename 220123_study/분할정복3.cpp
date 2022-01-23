#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//이중 for문을 이용
int bruteforce(const vector<int>& h) {
	int ret = 0;
	int N = h.size();

	for (int left = 0; left < N; ++left) {
		int minheight = h[left];
		for (int right = left; right < N; ++right) {
			minheight = min(minheight, h[right]);
			ret = max(ret, (right - left + 1)*minheight);

		}
	}

	return ret;
}//시작 지점을 가장 왼쪽에서부터 차례로 오른쪽으로 훑어보면서 가장 큰 울타리를 찾는다.

//분할정복을 이용
vector<int> h;

int solve(int left, int right) {
	//판자가 하나
	if (left == right) return h[left];
	//left ~mid/ mid+1 ~right으로 구간을 나눈다
	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));
	//왼,오른쪽 두 부분을 각각 눠 왼쪽과 오른쪽 중 큰 것을 고른다.

	
	//두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);

	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		//양쪽 높이가 높은 것 중에서 작은 것을 골라 높이로 결정
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		ret = max(ret, height *(hi - lo + 1));//새로 확장한 후 넓이
	}

	return ret;

}