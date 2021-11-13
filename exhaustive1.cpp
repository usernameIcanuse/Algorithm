#include<iostream>
#include<vector>
using namespace std;
/*1부터 n까지의 합을 계산하는 반복 함수와 재귀 함수*/

int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += i;

	return ret;
}//1->n의 합

int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n - 1);
}//n->1의 합


/*중첩 반복문 대체하기*/
//0~n-1 까지 원소중 네 개를 고르는 모든 경우를 출력

void usingforPick(int n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				cout << i << " " << j << " " << k << '\n';
}//중첩 이용한 원소 고르는 경우 -> 중복되는 경우 생김

void pick(int n, vector<int>& picked, int toPick) {
	//더 고를 원소가 없을 때 고른 원소들을 출력
	if (toPick == 0) { 
		printPicked(picked);//picked를 출력하는 함수
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;//뽑은 원소들은 오름차순으로 벡터에 push, 그 다음 뽑을 원소는 가장 뒤의 원소의 +1증가한 것 부터

	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}

}//중복되는 경우를 없앴을 때