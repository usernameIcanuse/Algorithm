#include<iostream>
#include<string>
using namespace std;

void decompress(string::iterator& it, int y, int x, int size) {
	char head = *(it++);

	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy)
			for (int dx = 0; dx < size; ++dx)
				decompressed[y + dy][x + dx] = head;
	}

	else {
		int half /= size;
		decompress(it, y, x, half);
		decompress(it, y, x+half, half);
		decompress(it, y+half, x, half);
		decompress(it, y+half, x+half, half);
	}

}

string reverse(string::iterator *it) {
	char head = it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string LowerLeft = reverse(it);
	string LowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
/*
압축된 쿼드 트리를 상하로 뒤집은 상태에서 압축한 결과

미리 4등분을 한뒤 각각 분할된 공간을 뒤집은 후 upper의 왼쪽,오른쪽 lower의 왼쪽,오른쪽을 바꿔주면 뒤집힌 형태로 압축이 된다.


*/