#include<iomanip>
#include <format>
#include"Win_define.h"
#include"database.h"

using namespace std;

void initialize();//初始化窗口
void Mainmenu();  //主菜单
void teacher();//教师端首页
void studentpage();//学生端首页
bool login();// 登录界面

int main()
{
	initialize();
	while (1)
		Mainmenu();
}

void initialize()
{
	cls();
	titleset("疫情防控综合系统");
	setconsoleborder(150, 40, 150, 40);
	fixconsolesize();
	hidecursor();
}

void Mainmenu() {
	gotoxy(60, 10, "交通大学疫情防控一站式系统");
	gotoxy(40, 30, "[1]行政通道");
	gotoxy(100, 30, "[2]学生通道");
	gotoxy(5, 38, "[ESC]退出");
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

		gotoxy(65, 25, "账号:_______________");
		gotoxy(65, 30, "密码:______________");
		gotoxy(10, 35, "[ESC]返回");
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
			gotoxy(95, 28, "* 账号不存在或密码错误");
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
	gotoxy(70, 10, "欢迎");
	gotoxy(25, 15, "[1]学生基本信息录入");
	gotoxy(25, 20, "[2]学生核酸信息录入");
	gotoxy(25, 25, "[3]宿舍楼信息录入");
	gotoxy(95, 15, "[4]核酸信息查询");
	gotoxy(95, 20, "[5]学生进出校审批");
	gotoxy(95, 25, "[6]学生宿舍楼管理");
	gotoxy(10, 35, "[ESC]退出登录");
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
	gotoxy(25, 10, "[1]核酸检测查询");
	gotoxy(25, 13, "[2]学生进出校申请");
	gotoxy(25, 30, "[ESC]返回上级菜单");
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
