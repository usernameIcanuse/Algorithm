#include<iostream>
using namespace std;

void Input(char* szArr);
void Output(char* szArr);
void Str_reverse(char* szArr);
void Swap(char* ch1, char* ch2);

int main() {

	char szArr[101];
	Input(szArr);
	Output(szArr);

	return 0;
}

void Input(char* szArr) {
	cout << "문자열을 입력하세요(100자이내): ";
	cin.getline(szArr, 101, '\n');

}

void Output(char* szArr) {

	Str_reverse(szArr);
	cout << szArr << '\n';

}

void Str_reverse(char* szArr) {
	int iLen = strlen(szArr);

	for (int i = 0; i < iLen / 2; i++)
		Swap(szArr+i, szArr+iLen - 1 - i);
}

void Swap(char* ch1, char* ch2) {
	char cTmp = *ch1;
	*ch1 = *ch2;
	*ch2 = cTmp;
}