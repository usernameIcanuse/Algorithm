#include<iostream>
//텍스처 복사
using namespace std;

char cCopy[7000000];
//char은 1바이트
int main() {
	/*
	FILE* fp1 = nullptr;
	FILE* fp2 = nullptr;

	errno_t err1 = fopen_s(&fp1, "../220208/Image.jpg", "rb");
	errno_t err2 = fopen_s(&fp2, "../220208/Copy.jpg", "wb");
	//파일의 이름을 쓸 때는 파일의 형식도 정확히 써줘야함
    //복사본을 저장할 파일의 확장자 명도 복사되는 파일의 확장자 명과 동일해야 함


	//색상 R,G,B 24bit 기반 0~255사이 값으로 표현
	if (0 == err1&& 0 == err2 ) {
		char a;// 0~255사이 값으로 표현 -> 1바이트가 표현할 수 있는 양수 범위 => 1바이트 단위로 불러들여
		while (!feof(fp1)) {//feof(FILE* stream) 함수는 fp가 파일 끝까지 갔는지 알려주는 함수
			                //끝까지 가면 true 반환
			fread(&a, sizeof(char), 1, fp1);
			fwrite(&a, sizeof(char), 1, fp2);
		}
		fclose(fp1);
		fclose(fp2);

		puts("파일이 복사되었습니다.");
	}
	else {
		cout << "파일 오픈 실패\n";
	}*/

	FILE* fp1 = nullptr;
	FILE* fp2 = nullptr;

	errno_t err1 = fopen_s(&fp1, "../220208/Image.jpg", "rb");
	errno_t err2 = fopen_s(&fp2, "../220208/Copy.jpg", "wb");
	if (0 == err1 && 0 == err2) {

		fread(cCopy, sizeof(cCopy), 1, fp1);
		fwrite(cCopy, sizeof(cCopy), 1, fp2);//사진의 바이트 크기만큼 캐릭터 형의 배열을 선언하여 거기에 전부 다 복사 후 그대로 쓰기

		puts("파일이 복사되었습니다.");

		fclose(fp1);
		fclose(fp2);
	}

	else {
		cout << "파일 오픈 실패'\n";
	}

	

	return 0;
}