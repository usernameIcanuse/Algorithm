#include<iostream>
//�ؽ�ó ����
using namespace std;

char cCopy[7000000];
//char�� 1����Ʈ
int main() {
	/*
	FILE* fp1 = nullptr;
	FILE* fp2 = nullptr;

	errno_t err1 = fopen_s(&fp1, "../220208/Image.jpg", "rb");
	errno_t err2 = fopen_s(&fp2, "../220208/Copy.jpg", "wb");
	//������ �̸��� �� ���� ������ ���ĵ� ��Ȯ�� �������
    //���纻�� ������ ������ Ȯ���� �� ����Ǵ� ������ Ȯ���� ��� �����ؾ� ��


	//���� R,G,B 24bit ��� 0~255���� ������ ǥ��
	if (0 == err1&& 0 == err2 ) {
		char a;// 0~255���� ������ ǥ�� -> 1����Ʈ�� ǥ���� �� �ִ� ��� ���� => 1����Ʈ ������ �ҷ��鿩
		while (!feof(fp1)) {//feof(FILE* stream) �Լ��� fp�� ���� ������ ������ �˷��ִ� �Լ�
			                //������ ���� true ��ȯ
			fread(&a, sizeof(char), 1, fp1);
			fwrite(&a, sizeof(char), 1, fp2);
		}
		fclose(fp1);
		fclose(fp2);

		puts("������ ����Ǿ����ϴ�.");
	}
	else {
		cout << "���� ���� ����\n";
	}*/

	FILE* fp1 = nullptr;
	FILE* fp2 = nullptr;

	errno_t err1 = fopen_s(&fp1, "../220208/Image.jpg", "rb");
	errno_t err2 = fopen_s(&fp2, "../220208/Copy.jpg", "wb");
	if (0 == err1 && 0 == err2) {

		fread(cCopy, sizeof(cCopy), 1, fp1);
		fwrite(cCopy, sizeof(cCopy), 1, fp2);//������ ����Ʈ ũ�⸸ŭ ĳ���� ���� �迭�� �����Ͽ� �ű⿡ ���� �� ���� �� �״�� ����

		puts("������ ����Ǿ����ϴ�.");

		fclose(fp1);
		fclose(fp2);
	}

	else {
		cout << "���� ���� ����'\n";
	}

	

	return 0;
}