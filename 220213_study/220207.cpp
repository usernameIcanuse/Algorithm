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
		cout << "1.���� 2.������ 3.���� 4.���� :";
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
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			system("pause");
			break;
		}
		flag = Select(player1);
	}
	
}

void Print_Player(Player* p) {
	cout << "���� : " << p->szRole << '\n';
	cout<<"���ݷ� : "<<p->iPower << '\n';
	cout << "ü�� : " << p->iHP << "\t" << p->iHPFull << '\n';
	cout << "���� : " << p->iLevel << " ( " << p->iExp << " / " << p->iExpFull << " )\n";
}

void Player_Worrior(Player* p) {
	strcpy(p->szRole, "����");
	p->iPower = 10;
	p->iHP = 200;
	p->iHPFull = 200;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;


}
void Player_Magician(Player* p) {
	strcpy(p->szRole, "������");
	p->iPower = 100;
	p->iHP = 100;
	p->iHPFull = 100;
	p->iLevel = 1;
	p->iExp = 0;
	p->iExpFull = 100;
}
void Player_Thief(Player* p) {
	strcpy(p->szRole, "����");
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
		cout << "1. ����� 2. ���� : ";
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
	strcpy(e->szRole, "�ʱ�");
	e->iHP = e->iHPFull = 30;
	e->iPower = 5;
}

void Enemy_Normal(Enemy* e) {
	strcpy(e->szRole, "�߱�");
	e->iHP = e->iHPFull = 50;
	e->iPower = 25;
}

void Enemy_Hard(Enemy* e) {
	strcpy(e->szRole, "���");
	e->iHP = e->iHPFull = 150;
	e->iPower = 50;
}

void Print_Enemy(Enemy* e) {
	cout << "���� : " << e->szRole << '\n';
	cout << "���ݷ�: " << e->iPower << '\n';
	cout << "ü��: " << e->iHP << '\t' << e->iHPFull << '\n';
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
		cout << "1. ���� 2. ���� \n";
		cout << "=================================\n";
		cout << "�Է� : ";
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
			cout << "�÷��̾� ���\n"; system("pause");
			p->iHP = p->iHPFull;
			p->iExp = 0;
			break;
		}
		else if(iFlag==-1){
			cout << "��� ����\n"; 
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
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. ���ܰ�: ";
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