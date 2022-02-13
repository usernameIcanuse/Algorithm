#include<iostream>
#include<time.h>
using namespace std;

enum MENU {
	Worrior = 1,
	Magician,
	Thief,
	Load,
	Esc
};

typedef struct Player {
	char szRole[10];
	int iSerialNum;
	int iPower;
	int iHP;
	int iHPFull;
	int iLevel;
	int iExp;
	int iExpFull;
}Player;

typedef struct Enemy {
	char szRole[10];
	int iPower;
	int iHP;
	int iHPFull;
}Enemy;

#pragma region player
void Player_Worrior(Player* p);
void Player_Magician(Player* p);
void Player_Thief(Player* p);
void Print_Player(Player* p);
int Load_Player(Player* p);
bool Save(Player* p);
#pragma endregion player

#pragma region menu
bool Select(Player* p);
void Field(Player* p, Enemy* e);
int Fighting(Player* p, Enemy* e);
#pragma endregion menu

#pragma region enemy
void Enemy_Select(Player* p, Enemy* e);
void Enemy_Easy(Enemy* e);
void Enemy_Normal(Enemy* e);
void Enemy_Hard(Enemy* e);
void Print_Enemy(Enemy* e);
#pragma endregion enemy

int main() {
	Player* player1 = new Player;
	bool flag = true;
	int Continue;
	int menu;
	while (flag) {
		system("cls");
		cout << "1.전사 2.마법사 3.도둑 4.불러오기 5. 종료 :";
		cin >> menu;
		switch (menu) {
		case Worrior:
			Player_Worrior(player1);
			break;
		case Magician:
			Player_Magician(player1);
			break;
		case Thief:
			Player_Thief(player1);
			break;
		case Load:
			Continue = Load_Player(player1);
			if (Continue == 0) continue;
			break;
		case Esc:
			delete player1;
			player1 = nullptr;
			return 0;
			break;
		default:
			cout << "잘못 입력하셨습니다.\n";
			system("pause");
			break;
		}
		flag = Select(player1);
	}
	
}
int Load_Player(Player* p) {
	int menu;

	FILE* fp1 = nullptr;
	FILE* fp2 = nullptr;
	FILE* fp3 = nullptr;
	system("cls");
	errno_t err1 = fopen_s(&fp1, "../TextRPG/Worrior.txt", "rb");
	if (0 == err1) {
		cout << "Save 1: 전사\t";
	}
	else {
		cout << "Save 1: empty\t";
	}
	errno_t err2 = fopen_s(&fp2, "../TextRPG/Magician.txt", "rb");
	if (0 == err2) {
		cout << "Save 2: 마법사\t";
	}
	else {
		cout << "Save 2: empty\t";
	}
	errno_t err3 = fopen_s(&fp3, "../TextRPG/Thief.txt", "rb");
	if (0 == err3) {
		cout << "Save 3: 도둑\t";
	}
	else {
		cout << "Save 3: empty (0번: 돌아가기):";
	}
	cin >> menu;

	if (menu == 0) return 0;

	if (menu == 1) {
//☆★☆★☆★☆★☆★☆★구조체 자체 크기만큼 파일 읽기 쓰기 가능 순서는 알아서 맞는걸로 대응된다고 보면 될 것 같다.☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
		fread(p, sizeof(Player), 1, fp1);
		fclose(fp1);
	}
	if (menu == 2) {
		fread(p, sizeof(Player), 1, fp2);
		fclose(fp2);
	}
	if (menu == 3) {
		fread(p, sizeof(Player), 1, fp2);
		fclose(fp3);
	}
	return 1;

	
}

void Print_Player(Player* p) {
	cout << "직업 : " << p->szRole << '\n';
	cout<<"공격력 : "<<p->iPower << '\n';
	cout << "체력 : " << p->iHP << "\t" << p->iHPFull << '\n';
	cout << "레벨 : " << p->iLevel << " ( " << p->iExp << " / " << p->iExpFull << " )\n";
}

void Player_Worrior(Player* p) {
	strcpy_s(p->szRole, "전사");
	p->iSerialNum = Worrior;
	p->iPower = 10;
	p->iHP = 200;
	p->iHPFull = 200;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;


}
void Player_Magician(Player* p) {
	strcpy_s(p->szRole, "마법사");
	p->iSerialNum = Magician;
	p->iPower = 100;
	p->iHP = 100;
	p->iHPFull = 100;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;
}
void Player_Thief(Player* p) {
	strcpy_s(p->szRole, "도둑");
	p->iSerialNum = Thief;
	p->iPower = 20;
	p->iHP = 50;
	p->iHPFull = 50;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;
}

bool Select(Player* p) {
	
	int menu;
	Enemy* enemy = new Enemy;
	bool bFlag = true;

	while (1) {
		system("cls");
		Print_Player(p);
		cout << "=================================\n";
		cout << "1. 사냥터 2. 저장하기 3. 종료 : ";
		cin >> menu;

		switch (menu) {
		case 1:
			Enemy_Select(p, enemy);
			break;
		case 2:
			bFlag = Save(p);
			if (bFlag) {
				cout << "저장하였습니다.\n";
				system("pause");
			}
			break;
		case 3:
			delete enemy;
			enemy = nullptr;
			return false;
			break;
		}
	}


}

bool Save(Player* p) {
	FILE* fp=nullptr;
	if (p->iSerialNum == Worrior) {
		errno_t err = fopen_s(&fp, "../TextRPG/Worrior.txt", "wb");
		if (0 == err) {
			fwrite(p, sizeof(Player), 1, fp);
			fclose(fp);
		}
		else {
			cout << "저장하지 못했습니다.\n";
			system("pause");
			return false;
		}
	}
	else if (p->iSerialNum == Magician) {
		errno_t err = fopen_s(&fp, "../TextRPG/Magician.txt", "wb");
		if (0 == err) {
			fwrite(p, sizeof(Player), 1, fp);
			fclose(fp);
			
		}
		else {
			cout << "저장하지 못했습니다.\n";
			system("pause");
			return false;
		}
	}
	else if (p->iSerialNum == Thief) {
		errno_t err = fopen_s(&fp, "../TextRPG/Thief.txt", "wb");
		if (0 == err) {
			fwrite(p, sizeof(Player), 1, fp);
			fclose(fp);
		}
		else{
			cout << "저장하지 못했습니다.\n";
			system("pause");
			return false;
		}
	}
	return true;
}

void Enemy_Easy(Enemy* e) { 
	strcpy_s(e->szRole, "초급");
	e->iHP = e->iHPFull = 30;
	e->iPower = 5;
}

void Enemy_Normal(Enemy* e) {
	strcpy_s(e->szRole, "중급");
	e->iHP = e->iHPFull = 50;
	e->iPower = 25;
}

void Enemy_Hard(Enemy* e) {
	strcpy_s(e->szRole, "고급");
	e->iHP = e->iHPFull = 150;
	e->iPower = 50;
}

void Print_Enemy(Enemy* e) {
	cout << "직업 : " << e->szRole << '\n';
	cout << "공격력: " << e->iPower << '\n';
	cout << "체력: " << e->iHP << '\t' << e->iHPFull << '\n';
}

void Field(Player* p, Enemy* e) {
	int menu;
	int iFlag = 0;
	srand(unsigned(time(NULL)));
	while (1) {
		system("cls");
		Print_Player(p);
		cout << "=================================\n";
		Print_Enemy(e);
		cout << "=================================\n";
		cout << "1. 전투 2. 도망 \n";
		cout << "=================================\n";
		cout << "입력 : ";
		cin >> menu;

		switch (menu) {
		case 1:
		    iFlag=Fighting(p, e);
			break;
		case 2:
			system("pause");
			return;
			break;
		}

		if (iFlag == 1) {
			cout << "플레이어 사망\n"; system("pause");
			p->iHP = p->iHPFull;
			p->iExp = 0;
			break;
		}
		else if(iFlag==-1){
			cout << "사냥 성공\n"; 
			p->iExp += rand() % e->iHPFull + 10;
			if (p->iExp >= p->iExpFull) {
				p->iExp -= p->iExpFull;
				p->iExpFull += 100;
				p->iHP = p->iHPFull += 100;
				++p->iLevel;
				p->iPower += 50;
			}
			system("pause");
			break;
		}
	}
}

void Enemy_Select(Player* p, Enemy* e) {
	int menu;
	while (1) {
		system("cls");
		Print_Player(p);
		cout << "=================================\n";
		cout << "1. 초급 2. 중급 3. 고급 4. 전단계: ";
		cin >> menu;
		switch (menu) {
		case 1:
			Enemy_Easy(e);
			break;
		case 2:
			Enemy_Normal(e);
			break;
		case 3:
			Enemy_Hard(e);
			break;
		case 4:
			return;
			break;
		}
		Field(p, e);

	}
}

int Fighting(Player* p, Enemy* e) {
	p->iHP -= e->iPower;
	if (p->iHP <= 0) return 1;
	e->iHP -= p->iPower;
	if (e->iHP <= 0) return -1;
	return 0;
}