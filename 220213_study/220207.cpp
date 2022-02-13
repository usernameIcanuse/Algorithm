#include<iostream>
#include<time.h>
using namespace std;

enum MENU {
	Worrior = 1,
	Magician,
	Thief,
	Esc
};

typedef struct Player {
	char szRole[10];
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
	int menu;
	while (flag) {
		cout << "1.전사 2.마법사 3.도둑 4.종료 :";
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

void Print_Player(Player* p) {
	cout << "직업 : " << p->szRole << '\n';
	cout<<"공격력 : "<<p->iPower << '\n';
	cout << "체력 : " << p->iHP << "\t" << p->iHPFull << '\n';
	cout << "레벨 : " << p->iLevel << " ( " << p->iExp << " / " << p->iExpFull << " )\n";
}

void Player_Worrior(Player* p) {
	strcpy(p->szRole, "전사");
	p->iPower = 10;
	p->iHP = 200;
	p->iHPFull = 200;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;


}
void Player_Magician(Player* p) {
	strcpy(p->szRole, "마법사");
	p->iPower = 100;
	p->iHP = 100;
	p->iHPFull = 100;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;
}
void Player_Thief(Player* p) {
	strcpy(p->szRole, "도둑");
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
	

	while (1) {
		system("cls");
		Print_Player(p);
		cout << "=================================\n";
		cout << "1. 사냥터 2. 종료 : ";
		cin >> menu;

		switch (menu) {
		case 1:
			Enemy_Select(p, enemy);
			break;
		case 2:
			delete enemy;
			enemy = nullptr;
			return false;
			break;
		}
	}


}

void Enemy_Easy(Enemy* e) {
	strcpy(e->szRole, "초급");
	e->iHP = e->iHPFull = 30;
	e->iPower = 5;
}

void Enemy_Normal(Enemy* e) {
	strcpy(e->szRole, "중급");
	e->iHP = e->iHPFull = 50;
	e->iPower = 25;
}

void Enemy_Hard(Enemy* e) {
	strcpy(e->szRole, "고급");
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
}