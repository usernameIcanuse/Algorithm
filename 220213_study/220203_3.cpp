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
		cout << "�̸��� �Է��ϼ���: ";
		cin >> (tagArr + i)->cName;
		cout << "������ �Է��ϼ���.\n";
		cout << "����: ";
		cin >> (tagArr + i)->iKor;
		iSum += (tagArr + i)->iKor;
		cout << "����: ";
		cin >> (tagArr + i)->iMth;
		iSum += (tagArr + i)->iMth;
		cout << "����: ";
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
		cout << "�̸�: " << (tagArr + i)->cName<<'\n';
		cout << "����: " << (tagArr + i)->iKor << "��\t����: " << (tagArr + i)->iMth << "��\t����: " << (tagArr + i)->iEng << "��\n";
		cout << "����: " << (tagArr + i)->iTotal << "��\t���: " << (tagArr + i)->dAvg << "��\n";
		cout << '\n';
	}
}