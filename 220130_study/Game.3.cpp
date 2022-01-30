#include<iostream>
using namespace std;

int main() {
	int iArray[5][5] = { 0 };
	int dy = 0, dx = 0;

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j) {
			iArray[i][j] = i * 5 + j;
		}

	while (true) {
		int iNumber;
		
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) 
				cout << iArray[i][j] << '\t';
			
			cout << '\n';
		}

		cout << "숫자를 입력하세요(2번 : 아래 / 4번: 왼쪽 / 6번: 오른쪽 / 8번: 위 / 0번 종료):";
		cin >> iNumber;
		if (iNumber == 0) break;
		else {
			if (iNumber == 2 && dy+1<5) {
				int iTmp = iArray[dy][dx];
				iArray[dy][dx] = iArray[dy + 1][dx];
				iArray[dy + 1][dx] = iTmp;
				dy += 1;
			}
			else if (iNumber == 4 && dx-1>=0) {
				int iTmp = iArray[dy][dx];
				iArray[dy][dx] = iArray[dy][dx-1];
				iArray[dy][dx-1] = iTmp;
				dx -= 1;
			}
			else if (iNumber == 6 && dx + 1 < 5) {
				int iTmp = iArray[dy][dx];
				iArray[dy][dx] = iArray[dy][dx+1];
				iArray[dy][dx+1] = iTmp;
				dx += 1;
			}
			else if (iNumber == 8 && dy - 1 >= 0) {
				int iTmp = iArray[dy][dx];
				iArray[dy][dx] = iArray[dy - 1][dx];
				iArray[dy - 1][dx] = iTmp;
				dy -= 1;
			}
			else {
				cout << "이동할 수 없습니다.\n";
				system("pause");
			}
		}
		system("cls");
	}

	return 0;

}