#include<iostream>
#include<string>
using namespace std;


void Input(char* szArr);
void Output(char* szArr);
int Str_Length(char* szarr);

int main() {
	char szArr[21];
	Input(szArr);
	Output(szArr);
	return 0;

}

void Input(char* szArr) {
	cout << "문자열을 입력하세요(20자이내): ";
	cin.getline(szArr, 21, '\n');
	//getline(cin,s)인 경우에는 s가 string으로 정의되었을 때 사용 가능
}

void Output(char* szArr) {
	cout << "문자열의 길이는 " << Str_Length(szArr) << "입니다.\n";
}

int Str_Length(char* szarr) {
	int iLen=0;

	for (iLen = 0; *(szarr + iLen) != '\0'; ++iLen) {}

	return iLen;
}
