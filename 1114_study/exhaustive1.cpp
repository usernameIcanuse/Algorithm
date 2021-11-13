#include<iostream>
#include<vector>
using namespace std;
/*1���� n������ ���� ����ϴ� �ݺ� �Լ��� ��� �Լ�*/

int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += i;

	return ret;
}//1->n�� ��

int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n - 1);
}//n->1�� ��


/*��ø �ݺ��� ��ü�ϱ�*/
//0~n-1 ���� ������ �� ���� ���� ��� ��츦 ���

void usingforPick(int n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				cout << i << " " << j << " " << k << '\n';
}//��ø �̿��� ���� ���� ��� -> �ߺ��Ǵ� ��� ����

void pick(int n, vector<int>& picked, int toPick) {
	//�� �� ���Ұ� ���� �� �� ���ҵ��� ���
	if (toPick == 0) { 
		printPicked(picked);//picked�� ����ϴ� �Լ�
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;//���� ���ҵ��� ������������ ���Ϳ� push, �� ���� ���� ���Ҵ� ���� ���� ������ +1������ �� ����

	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}

}//�ߺ��Ǵ� ��츦 ������ ��