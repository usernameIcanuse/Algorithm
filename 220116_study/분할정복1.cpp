#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> h;
/* ���� ��� 1: ū ���簢���� ���ʿ�
   ���� ��� 2: ū ���簢���� �����ʿ� 
   ���� ��� 3: ū ���簢���� ������ ���ʿ� ���� ����*/


int solve(int left, int right) {
	// ���� ���1: ���ڰ� 1���� ���
	if (left == right) return h[left];
	//�� �������� ���� left ~ mid / mid+1 ~ right
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