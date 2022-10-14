#include"UNO.h"
#include"Win_define.h"
#include<iostream>
using namespace std;

Rule def{};
Rule::Rule()
{
	setting[0] = 0;
	uno_add = 2;
	setting[1] = 1;
	setting[2] = 0;
}

void Rule::show_rule()
{
	gotoxy(50, 10);
	cout << boolalpha<<setting[0];
	gotoxy(50, 15);
	cout << setting[1];
	gotoxy(50, 20);
	cout << setting[2];
	gotoxy(50, 25);
	cout << uno_add;
}

void Rule::change_rule(int n)
{
	show_someting();
	gotoxy(37, 10, "->");
	int keyin;
	int tempnum[3] = { 71,67,-35 };
	const HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	while (1) {
		keyin = checknum(tempnum, 3);
		if (keyin == -35) {
			GetConsoleScreenBufferInfo(out, &binfo);
			coord.Y = binfo.dwCursorPosition.Y;
			if (coord.Y == 10) setting[n] = 1;
			else if (coord.Y == 20) setting[n] = 0;
			return;
		}
		else if (keyin == 71) {
			GetConsoleScreenBufferInfo(out, &binfo);
			coord.Y = binfo.dwCursorPosition.Y;
			show_someting();
			if (coord.Y == 10) gotoxy(37, 20, "->");
			else gotoxy(37, 10, "->");
		}
		else if (keyin == 67) {
			GetConsoleScreenBufferInfo(out, &binfo);
			coord.Y = binfo.dwCursorPosition.Y;
			show_someting();
			if (coord.Y == 20) gotoxy(37, 10, "->");
			else gotoxy(37, 20, "->");
		}
	}
	
}

void show_someting()  //����һ�����������
{
	cls();
	gotoxy(40, 5, "��ѡ��Ҫ�������޸�(��W-S�������µ���)");
	gotoxy(40, 10, "����");
	gotoxy(40, 20, "����");
}

void Rule::change_num()
{
	int temp;
	do {
		cls();
		showcursor();
		gotoxy(40, 15, "����(0-4)֮�������ֵ:______");
		cout << "\b\b\b\b\b\b";
		cin >> temp;
		cin.clear();
		cin.ignore();
	} while (temp >= 5 || temp <= -1);
	hidecursor();
	uno_add = temp;
	cls();
}

