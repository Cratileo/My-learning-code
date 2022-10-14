#include<iomanip>
#include"Win_define.h"
#include <format>
#include"UNO.h"
using namespace std;

void initialize();//初始化窗口
void Mainmenu();  //主菜单
void TestEngeneer();
void option();  //UNO相关参数调试

extern Rule def;

int main()
{
	initialize();
	while (1)
		Mainmenu();
}

void initialize()
{
	cls();
	titleset("酒吧炒饭测试");
	setconsoleborder(150, 40, 150, 40);
	fixconsolesize();
	hidecursor();

}

void Mainmenu()
{
	int keyin;
	gotoxy(60, 2, "Play UNO!");
	gotoxy(40, 25,"[1]PLAY");
	gotoxy(60, 25,"[2]OPTION");
	gotoxy(80, 25, "[3]测试工程师通道");
	gotoxy(5, 38,"[ESC]Exit");
	gotoxy(125, 36, "Copyrite by CC_BY 3.0");
	gotoxy(125, 38, "Verison 1.0.0 (Beta)");
	while (1) {
		keyin = _getch()-48;
		if (keyin == -21) exit(0);
		if (keyin == 1 || keyin == 2||keyin==3) break;
	}
	cls();
	if (keyin == 1) {
		gotoxy(10, 10);
		cout << format("({},{},{},{},{})", "hello", "Do you know it?", "Yes", "you must know", "SJTU");
	}
	else if (keyin == 2) {
		option();
		Mainmenu();
	}
	else if (keyin == 3) {
		TestEngeneer();
		Mainmenu();
	}
	exit(0);  //暂时提供退出区
}

void TestEngeneer() //控制台窗口内容性实验
{
	showcursor();
	string pin;
	while (1) {
		gotoxy(60, 15, "请输入邀请码:_________\b\b\b\b\b\b\b\b");
		getline(cin, pin);
		if (pin == "114514") break;    //十分甚至九分明显
		cls();
		gotoxy(70, 20, "邀请码错误，输错三次会有惩罚（恼）");  //要什么惩罚呢
		gotoxy(122, 38, "先辈系统Ver114.514已加载");
	}
	cls();
	hidecursor();
	gotoxy(60, 3, "欢迎来到测试工程师酒吧");
	gotoxy(5, 7, "你想要点什么:");
	gotoxy(5, 10, "[1]鸡尾酒");
	gotoxy(5, 13, "[2]锟斤拷");
	gotoxy(5, 16, "[3]烫烫烫");
	gotoxy(5, 19, "[4]酒吧老板");
	gotoxy(5, 22, "[5]炒饭");
	gotoxy(5, 25, "[6]洗脚水");
	gotoxy(5, 30, "[B]返回上级菜单");
	gotoxy(5, 35, "[ESC]Exit");
	int keyin;
	int tempnum[8] = { 1,2,3,4,5,6,-21,18 };
	keyin = checknum(tempnum, 8);
	cls();
	gotoxy(5, 5);
	if (keyin == -21) exit(0);
	else if (keyin == 18) return;
	else if (keyin == 1) {
		cout << "酒很好喝，还想来点什么吗";
		gotoxy(5, 10, "[1]还要");
		gotoxy(5, 15, "[2]不了");
		keyin = checknum(tempnum, 2);
		if (keyin == 1)
		{
			cls();
			TestEngeneer();
		}
		else if (keyin == 2) exit(0);
	}
	else if (keyin == 2) {
		cout << "测试工程师在酒吧点了一杯锟斤拷……\n\n"
			"测试工程师C的DNA动了，他站起来，手执不知道从哪突然冒出来的锟斤拷...";
		exit(0);
	}
	else if (keyin == 5) {
		cout << "你居然点了炒饭，酒吧炸了";
		Sleep(1000);
		exit(0);
	}
}

void option()
{
	while (1) {
		cls();
		gotoxy(5, 3, "基础参数调整");
		gotoxy(5, 10, "[1]允许最后一张牌为功能牌");
		gotoxy(5, 15, "[2]出牌顺序");
		gotoxy(5, 20, "[3]每次从赢家开始");
		gotoxy(5, 25, "[4]最终牌不叫UNO罚牌数");
		gotoxy(5, 30, "按下相应键以修改参数");
		gotoxy(5, 35, "[ESC]退回主菜单");
		def.show_rule();
		int keyin;
		int tempnum[5] = { 1,2,3,4,-21};
		keyin = checknum(tempnum, 5);
		if (keyin == -21) {
			cls();
			return;
		}
		else if (keyin == 1)
			def.change_rule(keyin - 1);
		else if (keyin == 2)
			def.change_rule(keyin - 1);
		else if (keyin == 3)
			def.change_rule(keyin - 1);
		else if (keyin == 4) def.change_num();
	}
}