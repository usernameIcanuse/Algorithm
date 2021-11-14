#include<iostream>
#include<vector>
using namespace std;

/*게임판 덮기*/

const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},{{0,0},{0,1},{1,1}},{{0,0},{1,0},{1,1}},{{0,0},{1.0},{1,-1}}
};//각 칸을 채우는 유형을 배열로 저장

bool set(vector<vector<int>>& board, int y, int x,int type, int delta) {//delta는 채우고(+1), 지우고(-1) 대입
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size()) ok = false;
		else if ((board[ny][nx] += delta) > 1) ok = false;//이미 채운 곳을 또 채움
	}
	return ok;
}//칸 채우는 행동

int cover(vector<vector<int>>& board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;// 채워지지 않은 칸
	}

	if (y == -1) return 1;//칸이 모두 채워짐

	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1))//채울 때
			ret += cover(board);

		set(board, y, x, type, -1);//다시 원해대로
	}

	return ret;
}

