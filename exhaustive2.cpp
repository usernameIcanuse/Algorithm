#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*보글 게임*/
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
                 //왼위,왼,왼위,오아,오,오위,아,위

char board[5][5];//알파벳들이 나열되어 있는 배열

bool hasWord(int y, int x, const string& word) {
	//시작 위치가 범위 밖이면 실패
	if (!inRange(x, y)) return false;
	//첫글자가 일치하지 않으면 실패
	if (board[y][x] != word[0]) return false;
    //단어의 길이가 1
	if (word.size() == 1) return true;

	for (int direction = 0; direction < 8; direction++) {
		int ny = y + dy[direction];
		int nx = x + dx[direction];

		if (hasWord(ny, nx, word.substr(1)))//substr(1)문자열의 인덱스 1 부터 끝까지 부분 문자열
		    return true;
	}

	return false//다 돌았는데도 없으면 false
}