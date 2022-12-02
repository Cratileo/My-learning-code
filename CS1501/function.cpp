#include"database.h"
#include"Win_define.h"
#include<iostream>
using std::cin;



void StudentApply() {
	cls();


}

void BasicDataStream() {
	cls();
	string temp;
	gotoxy(20, 10, "在下面输入信息（以'；'为多条信息分隔符，以'，'为单条信息内多项的分隔符）");
	gotoxy(20, 12, "例：'张三,522031145141,54749110,电院,电院2201,X83-110,全程接种;李四,52203xxxxx,xxxx,安泰,xxxx,Dxx-xxx,xxxx'");
	gotoxy(20, 15);
	showcursor();
	getline(cin, temp);
	hidecursor();
	streamprocess(temp);
	gotoxy(20, 30, "输入成功");
	gotoxy(50, 30, "[1]继续输入");
	gotoxy(80, 30, "[ESC]返回上级菜单");
	int keyin;
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return;
		}
		if (keyin == 1) break;
	}

	cls();
	if (keyin == 1)
		BasicDataStream();
	
}

void PCRDataStream() {

}
