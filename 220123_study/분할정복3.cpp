#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//���� for���� �̿�
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
}//���� ������ ���� ���ʿ������� ���ʷ� ���������� �Ⱦ�鼭 ���� ū ��Ÿ���� ã�´�.

//���������� �̿�
vector<int> h;

int solve(int left, int right) {
	//���ڰ� �ϳ�
	if (left == right) return h[left];
	//left ~mid/ mid+1 ~right���� ������ ������
	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));
	//��,������ �� �κ��� ���� �� ���ʰ� ������ �� ū ���� ����.

	
	//�� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);

	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		//���� ���̰� ���� �� �߿��� ���� ���� ��� ���̷� ����
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		ret = max(ret, height *(hi - lo + 1));//���� Ȯ���� �� ����
	}

	return ret;

}