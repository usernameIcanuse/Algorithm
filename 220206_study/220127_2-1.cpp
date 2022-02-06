//�������
#include<iostream>
#include<time.h>
using namespace std;

int Count_Bingo(bool (*arr)[5]);

int main() {
	srand(unsigned(time(NULL)));
	int iBingo[5][5];//������

	bool iDest[5][5] = { false };

	bool bFlag[25] = { false };//������ ��

	int iIndex[25][2] = { 0 };//�� ���ڰ� ��ġ�� ��� ����
	///[0]y/[1]x
	int iCount = 0;
	int iTmp = 0;


	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int iTmp = rand() % 25 + 1;

			if (!bFlag[iTmp - 1]) {
				bFlag[iTmp - 1] = true;
				iBingo[i][j] = iTmp;

				iIndex[iTmp - 1][0] = i; iIndex[iTmp - 1][1] = j;
			}
			else --j;
		}
	}


	while (true) {
		
		int iNumber;

		cout << "=========================" << '\n';
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iDest[i][j])
					cout << " *" << '\t';
				else
					cout << iBingo[i][j] << '\t';
			}
			cout << '\n';
		}
		if (iCount == 5) {
			cout << "Five Bingo!!\n";
			break;
		}

		cout << "���ڸ� �Է��ϼ���(1~25): ";
		cin >> iNumber;
		++iTmp;

		iDest[iIndex[iNumber-1][0]][iIndex[iNumber-1][1]] = true;

		
		
		iCount = Count_Bingo(iDest);
		system("cls");

	}


	return 0;

}

int Count_Bingo(bool (*arr)[5]) {
	int iWidth = 0;
	int iHeight = 0;
	int iDiagonal = 0;
    bool flag1, flag2;
	for (int i = 0; i < 5; ++i) {
		flag1 = true; flag2 = true;
		for (int j = 0; j < 5; ++j) {
			if (!arr[i][j]) flag1 = false;
			if (!arr[j][i]) flag2 = false;
		}
		if (flag1) ++iWidth;
		if (flag2) ++iHeight;
	}

	flag1 = true; flag2 = true;

	for (int i = 0; i < 5; ++i) {
		if (!arr[i][i]) flag1 = false;
		if (!arr[i][4 - i]) flag2 = false;
	}
	if (flag1) ++iDiagonal;
	if (flag2) ++iDiagonal;

	return iWidth + iHeight + iDiagonal;
}