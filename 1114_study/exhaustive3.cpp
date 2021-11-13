#include<iostream>
using namespace std;

/*소풍 문제*/
//서로 친구인 경우에만 짝을 지어줄 수 있다.
int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	//모든 학생이 짝을 찾았으면 종료
	bool finished = true;
	for (int i = 0; i < n; i++) if (!taken[i]) finished = false;
	if (finished) return 1;//한가지 경우 찾음

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!taken[i] && !taken[j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}//이 경우는 중복으로 세는 경우 발생 ex) (0,4) / (4,0)

int countPairing(bool taken[10]) {
	//남은 학생들 중 가장 번호가 빠른 학생
	int firstfree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) firstfree = i; break;
	}

	if (firstfree == -1) return 1;//모든 학생이 짝을 찾았을 때
	int ret = 0;

	for (int pairWith = firstfree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstfree][pairWith]) {
			taken[pairWith] = taken[firstfree] = true;
			ret+=countPairing(taken);
			taken[firstfree] = taken[pairWith] = false;
		}
	}
	return ret;
}//가장 번호 빠른 학생부터 짝을 고름