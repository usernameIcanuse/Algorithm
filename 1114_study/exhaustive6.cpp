#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*�ð� ����*/
// ��ư �ѹ��� 3ĭ�� �̵� -> 4�� ������ ������� ���ƿ��� Ư���� �̿��� ����� ���� ���δ�

const int INF = 9999, SWITCHES = 10, CLOCK = 16;

const char linked[SWITCHES][CLOCK + 1] = {// linked[i][j] -> i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�.
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks) {//��� �ð谡 12�ø� ����Ű���� Ȯ��
	bool flag = true;
	for (int i = 0; i < clocks.size(); i++)
		if (clocks[i] != 0) flag = false;

	return flag;
}

void push(vector<int>& clocks, int swtch) {//swtch���� ����ġ�� �������� ��
	for (int clock = 0; clock < CLOCK; clock++) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));//�ݺ��� ó���� 0�� ������ ��, ������ 4��° ������ for�� ���� Ȯ�� �ϸ鼭
		push(clocks, swtch);                          // for�� ���� ���ͼ� �������·� ���ƿ� -> 0��,1��,2��,3�� ������ �� ��� ����
	}

	return ret;
}