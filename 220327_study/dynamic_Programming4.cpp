#include<iostream>
using namespace std;

//���ϵ�ī��

int cache[101][101];//int�� ����ϴ� ������ ����� �� �ߴٴ� -1�� ����ϱ� ����

string W, S;

bool matchMemoized(int w, int s)
{
	//���� ret�� ��츦 ó���Ѵ�.
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
	{
		++w; ++s;
	}
	//*�̸� ���ڿ� �߰��� �ݺ��� Ż��
	if (w == W.size()) return ret = (s == S.size());
	//���� ���� ������ ���� �� s�� ������ ���ٸ� true �׷��� ������ false

	//*������ ��
	if (W[w] == '*')
	{
		for (int skip = 0; s + skip <= S.size(); ++skip)
		{
			if (matchMemoized(w + 1, s + skip))
				//���� *�ٷ� �������� s�� skip ��������
				//skip�ϴ� ������ *�� �����ϴ� 0�̻� ������ ���ڿ�
				return ret = 1;
		}
	}
	//������ ���Ҵµ� s�� ������ �� ����� ���� ������ *�� �ƴϸ� false�̹Ƿ� �ڵ����� ������ �κ� ����
	return ret = 0;
}