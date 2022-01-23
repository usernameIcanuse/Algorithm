#include<iostream>
using namespace std;

int cache[2500][2500];

int someObscureFunction(int a, int b) {
	if (~~) return ~~

		int& ret = cache[a][b];//cache값을 직접 참조해서 그값에 대해서 조건확인
	if (ret != -1) return ret;

	~~~~~
		return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));//memset(초기화할 변수, 초기화할 값, 초기화할 크기//배열이면 배열의 크기를 써넣자)
}