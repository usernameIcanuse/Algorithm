#include<iostream>
using namespace std;

/*��ǳ ����*/
//���� ģ���� ��쿡�� ¦�� ������ �� �ִ�.
int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	//��� �л��� ¦�� ã������ ����
	bool finished = true;
	for (int i = 0; i < n; i++) if (!taken[i]) finished = false;
	if (finished) return 1;//�Ѱ��� ��� ã��

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
}//�� ���� �ߺ����� ���� ��� �߻� ex) (0,4) / (4,0)

int countPairing(bool taken[10]) {
	//���� �л��� �� ���� ��ȣ�� ���� �л�
	int firstfree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) firstfree = i; break;
	}

	if (firstfree == -1) return 1;//��� �л��� ¦�� ã���� ��
	int ret = 0;

	for (int pairWith = firstfree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstfree][pairWith]) {
			taken[pairWith] = taken[firstfree] = true;
			ret+=countPairing(taken);
			taken[firstfree] = taken[pairWith] = false;
		}
	}
	return ret;
}//���� ��ȣ ���� �л����� ¦�� ��