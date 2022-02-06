#include<iostream>
using namespace std;

struct Student {
	char cName[10];
	int iKor;
	int iMth;
	int iEng;
	int iTotal;
	double dAvg;
};

void Input(Student* tagArr);
void Output(Student* tagArr);


int main() {

	Student tagArr[3];
	Input(tagArr);
	Output(tagArr);
	return 0;
}

void Input(Student* tagArr) {
	for (int i = 0; i < 3; i++) {
		int iSum = 0;
		cout << "이름을 입력하세요: ";
		cin >> (tagArr + i)->cName;
		cout << "성적을 입력하세요.\n";
		cout << "국어: ";
		cin >> (tagArr + i)->iKor;
		iSum += (tagArr + i)->iKor;
		cout << "수학: ";
		cin >> (tagArr + i)->iMth;
		iSum += (tagArr + i)->iMth;
		cout << "영어: ";
		cin >> (tagArr + i)->iEng;
		iSum += (tagArr + i)->iEng;

		(tagArr + i)->iTotal = iSum;
		(tagArr + i)->dAvg = (double)iSum / 3;		
	}

}

void Output(Student* tagArr) {
	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < 3; i++) {
		cout << "이름: " << (tagArr + i)->cName<<'\n';
		cout << "국어: " << (tagArr + i)->iKor << "점\t수학: " << (tagArr + i)->iMth << "점\t영어: " << (tagArr + i)->iEng << "점\n";
		cout << "총점: " << (tagArr + i)->iTotal << "점\t평균: " << (tagArr + i)->dAvg << "점\n";
		cout << '\n';
	}
}