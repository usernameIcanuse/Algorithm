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
����� ���� Ʈ���� ���Ϸ� ������ ���¿��� ������ ���

�̸� 4����� �ѵ� ���� ���ҵ� ������ ������ �� upper�� ����,������ lower�� ����,�������� �ٲ��ָ� ������ ���·� ������ �ȴ�.


*/