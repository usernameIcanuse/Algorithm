//�߱�����
#include<iostream>
#include<time.h>
using namespace std;


int main() {
	srand(unsigned(time(NULL)));

	int iAnswer[3] = { 0 };
	int i = 0;

	while (iAnswer[0] == iAnswer[1] || iAnswer[1] == iAnswer[2] || iAnswer[0] == iAnswer[2]) {
		iAnswer[0] = rand() % 9 + 1;
		iAnswer[1] = rand() % 9 + 1;
		iAnswer[2] = rand() % 9 + 1;
	}

	cout << "����: ";
	for (int i = 0; i < 3; i++)
		cout << iAnswer[i] << ' ';
	cout << "\n";

	for (i = 0; i < 9; ++i) {
		cout << "============" << i + 1 << "ȸ��============\n";
		int strike = 0, ball = 0;
		int iInput[3];

		cout << "���ڸ� �Է��ϼ���: ";
		for (int i = 0; i < 3; ++i)
			cin >> iInput[i];


		if (iInput[0] == iAnswer[0]) ++strike;
		
		else {
			if (iInput[0] == iAnswer[1]) ++ball;
			else if (iInput[0] == iAnswer[2]) ++ball;
		}

		if (iInput[1] == iAnswer[1]) ++strike;
		else {
			if (iInput[1] == iAnswer[0]) ++ball;
			else if (iInput[1] == iAnswer[2]) ++ball;
		}

		if (iInput[2] == iAnswer[2]) ++strike;
		else {
			if (iInput[2] == iAnswer[1]) ++ball;
			else if (iInput[2] == iAnswer[0]) ++ball;
		}

		cout << strike << " strike  " << ball << " ball  \n";

		if (strike == 3) {
			cout << "�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n";
			cout << "�ڡ١ڡ١ڡ� �����մϴ� �ڡ١ڡ١ڡ�\n";
			cout << "�١ڡ١� ����� �¸��ߴ�. �١ڡ١ڡ�\n";
			cout << "�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n";
			break;
		}
	}

	if (i == 9) cout << "�й�" << '\n';

	return 0;

}
