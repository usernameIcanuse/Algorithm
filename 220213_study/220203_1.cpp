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
	cout << "���ڿ��� �Է��ϼ���(20���̳�): ";
	cin.getline(szArr, 21, '\n');
	//getline(cin,s)�� ��쿡�� s�� string���� ���ǵǾ��� �� ��� ����
}

void Output(char* szArr) {
	cout << "���ڿ��� ���̴� " << Str_Length(szArr) << "�Դϴ�.\n";
}

int Str_Length(char* szarr) {
	int iLen=0;

	for (iLen = 0; *(szarr + iLen) != '\0'; ++iLen) {}

	return iLen;
}
