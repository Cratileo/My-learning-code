#include<iomanip>
#include <format>
#include"Win_define.h"
#include"database.h"

using namespace std;

void initialize();//��ʼ������
void Mainmenu();  //���˵�
void teacher();//��ʦ����ҳ
void studentpage();//ѧ������ҳ
bool login();// ��¼����

int main()
{
	initialize();
	while (1)
		Mainmenu();
}

void initialize()
{
	cls();
	titleset("��������ۺ�ϵͳ");
	setconsoleborder(150, 40, 150, 40);
	fixconsolesize();
	hidecursor();
}

void Mainmenu() {
	gotoxy(60, 10, "��ͨ��ѧ�������һվʽϵͳ");
	gotoxy(40, 30, "[1]����ͨ��");
	gotoxy(100, 30, "[2]ѧ��ͨ��");
	gotoxy(5, 38, "[ESC]�˳�");
	gotoxy(130, 38, "Alpha 1.0.0");
	int keyin;
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) exit(0);
		if (keyin == 1 || keyin == 2) break;
	}

	cls();
	if (keyin == 1) {
		teacher();
		Mainmenu();
	}
	else if (keyin == 2) {
		studentpage();
		Mainmenu();
	}
}

bool login()
{
	int keyin;
	cls();
	while (1) {
		string accountT, passwordT;
		gotoxy(50, 2, R"(      _   _                             _   )");
		gotoxy(50, 3, R"(     | | / \   ___ ___ ___  _   _ _ __ | |_ )");
		gotoxy(50, 4, R"(  _  | |/ _ \ / __/ __/ _ \| | | | '_ \| __|)");
		gotoxy(50, 5, R"( | |_| / ___ \ (_| (_| (_) | |_| | | | | |_ )");
		gotoxy(50, 6, R"(  \___/_/   \_\___\___\___/ \__,_|_| |_|\__|)");

		gotoxy(65, 25, "�˺�:_______________");
		gotoxy(65, 30, "����:______________");
		gotoxy(10, 35, "[ESC]����");
		gotoxy(70, 25);
		int keyin;
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return false;
		}
		showcursor();
		getline(cin, accountT);
		gotoxy(70, 30);
		getline(cin, passwordT);
		hidecursor();
		if (checkaccount(accountT, passwordT))
			return true;
		else {
			gotoxy(95, 28, "* �˺Ų����ڻ��������");
			continue;
		}
	}
}

void teacher() {
	bool flag=login();
	if (!flag)
	{
		cls();
		return;
	}
	cls();
	gotoxy(70, 10, "��ӭ");
	gotoxy(25, 15, "[1]ѧ��������Ϣ¼��");
	gotoxy(25, 20, "[2]ѧ��������Ϣ¼��");
	gotoxy(25, 25, "[3]����¥��Ϣ¼��");
	gotoxy(95, 15, "[4]������Ϣ��ѯ");
	gotoxy(95, 20, "[5]ѧ������У����");
	gotoxy(95, 25, "[6]ѧ������¥����");
	gotoxy(10, 35, "[ESC]�˳���¼");
	int keyin;
	int tempnum[7] = { 1,2,3,4,5,6,-21 };
	keyin = checknum(tempnum, 7);
	switch (keyin) {
		case 1: BasicDataStream(); break;
		case 2: PCRDataStream(); break;
		case 4: SearchPCR(); break;
		case -21: cls();  return;
	}
}

void studentpage() {
	int keyin;
	gotoxy(25, 10, "[1]�������ѯ");
	gotoxy(25, 13, "[2]ѧ������У����");
	gotoxy(25, 30, "[ESC]�����ϼ��˵�");
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return;
		}
		if (keyin == 1 || keyin == 2) break;
	}
	cls();
	if (keyin == 1) {
		SearchPCR();
		studentpage();
	}
	else if (keyin == 2) {
		StudentApply();
		studentpage();
	}
}
