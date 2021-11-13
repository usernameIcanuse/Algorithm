#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*���� ����*/
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
                 //����,��,����,����,��,����,��,��

char board[5][5];//���ĺ����� �����Ǿ� �ִ� �迭

bool hasWord(int y, int x, const string& word) {
	//���� ��ġ�� ���� ���̸� ����
	if (!inRange(x, y)) return false;
	//ù���ڰ� ��ġ���� ������ ����
	if (board[y][x] != word[0]) return false;
    //�ܾ��� ���̰� 1
	if (word.size() == 1) return true;

	for (int direction = 0; direction < 8; direction++) {
		int ny = y + dy[direction];
		int nx = x + dx[direction];

		if (hasWord(ny, nx, word.substr(1)))//substr(1)���ڿ��� �ε��� 1 ���� ������ �κ� ���ڿ�
		    return true;
	}

	return false//�� ���Ҵµ��� ������ false
}