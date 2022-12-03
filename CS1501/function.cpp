#include"database.h"
#include"Win_define.h"
#include<format>
using std::cin;
using std::vector;
using std::cout;

extern Processtodo proc;

void StudentApply() {
	cls(); 
	int keyin;
	{
		vector<string>applyinfo;
		if (proc.checkapply(applyinfo)) {
			gotoxy(30, 5, "您的申请状态：");
			cout << applyinfo[0];
			int temp = stoi(applyinfo[5]);
			switch (temp) {
			case 0: gotoxy(30, 10, "出入校方式：仅出校");
				gotoxy(30, 15, "出校时间");
				cout << applyinfo[2];
				break;
			case 1: gotoxy(30, 10, "出入校方式：仅进校");
				gotoxy(30, 15, "进校时间:");
				cout << applyinfo[1];
				break;
			case 2: gotoxy(30, 10, "出入校方式：当天先进后出");
				gotoxy(30, 15, "进出校时间：");
				cout << applyinfo[1];
				break;
			case 3: gotoxy(30, 10, "出入校方式：当天先出后进");
				gotoxy(30, 15, "进出校时间");
				cout << applyinfo[1];
				break;
			}
			gotoxy(130, 35, "[ESC}退出");
			int keyin;
			while (1) {
				keyin = _getch() - 48;
				if (keyin == -21) return;
			}
		}
		gotoxy(30, 10, "未查询到申请记录");
		gotoxy(30, 20, "[1]提交新申请");
		gotoxy(30, 25, "[ESC]退出");
		while (1) {
			keyin = _getch() - 48;
			if (keyin == -21) {
				cls();
				return;
			}
			else if (keyin == 1) {
				proc.toapply();
				gotoxy(30, 35, "申请成功");
				Sleep(500);
				cls();
				return;
			}
		}
		
	}
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
