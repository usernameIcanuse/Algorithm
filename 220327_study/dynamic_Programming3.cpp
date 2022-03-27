#include<iostream>
using namespace std;

bool match(const string& w, const string& s)
{	//w[pos] �� s[pos]�� ��
	int pos = 0;

	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	//while���� �����
	//1.���� ���� ���� ���� �� s���ڿ��� ������ ���������� true
	if (pos == w.size())
		return pos == s.size(); // s������ �������� true ��ȯ �ƴϸ� false ��ȯ

	if (w[pos] == '*')
	{
		for (int skip = 0; pos + skip < s.size(); ++skip)
		{
			if (match(w.substr(pos + 1), s.substr(pos + skip))) return true;
		}
	}

	return false; // s������ ���� �� ó���� ���� ������
	//���� ���� ���� ���ڰ� *�� ���� �� �ݺ����� ���� ó���ǰ� �ƴ� ���� �׳� �����̱� ������
	//��������� �� ���� false�� �Ѿ�´�.
}

int main()
{

	return 0;
}