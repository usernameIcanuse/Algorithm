#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*시계 문제*/
// 버튼 한번에 3칸씩 이동 -> 4번 누르면 원래대로 돌아오는 특성을 이용해 경우의 수를 줄인다

const int INF = 9999, SWITCHES = 10, CLOCK = 16;

const char linked[SWITCHES][CLOCK + 1] = {// linked[i][j] -> i번 스위치와 j번 시계가 연결되어 있다.
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

bool areAligned(const vector<int>& clocks) {//모든 시계가 12시를 가리키는지 확인
	bool flag = true;
	for (int i = 0; i < clocks.size(); i++)
		if (clocks[i] != 0) flag = false;

	return flag;
}

void push(vector<int>& clocks, int swtch) {//swtch번의 스위치를 누르려고 함
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
		ret = min(ret, cnt + solve(clocks, swtch + 1));//반복문 처음이 0번 눌렀을 때, 마지막 4번째 누르고 for문 조건 확인 하면서
		push(clocks, swtch);                          // for문 빠져 나와서 원래상태로 돌아옴 -> 0번,1번,2번,3번 눌렀을 때 경우 가능
	}

	return ret;
}