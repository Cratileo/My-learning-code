#include<iomanip>
#include"Win_define.h"
#include <format>
#include"UNO.h"
using namespace std;

void initialize();//��ʼ������
void Mainmenu();  //���˵�
void TestEngeneer();
void option();  //UNO��ز�������

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
	titleset("�ưɳ�������");
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
	gotoxy(80, 25, "[3]���Թ���ʦͨ��");
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
	exit(0);  //��ʱ�ṩ�˳���
}

void TestEngeneer() //����̨����������ʵ��
{
	showcursor();
	string pin;
	while (1) {
		gotoxy(60, 15, "������������:_________\b\b\b\b\b\b\b\b");
		getline(cin, pin);
		if (pin == "114514") break;    //ʮ�������ŷ�����
		cls();
		gotoxy(70, 20, "���������������λ��гͷ����գ�");  //Ҫʲô�ͷ���
		gotoxy(122, 38, "�ȱ�ϵͳVer114.514�Ѽ���");
	}
	cls();
	hidecursor();
	gotoxy(60, 3, "��ӭ�������Թ���ʦ�ư�");
	gotoxy(5, 7, "����Ҫ��ʲô:");
	gotoxy(5, 10, "[1]��β��");
	gotoxy(5, 13, "[2]��");
	gotoxy(5, 16, "[3]������");
	gotoxy(5, 19, "[4]�ư��ϰ�");
	gotoxy(5, 22, "[5]����");
	gotoxy(5, 25, "[6]ϴ��ˮ");
	gotoxy(5, 30, "[B]�����ϼ��˵�");
	gotoxy(5, 35, "[ESC]Exit");
	int keyin;
	int tempnum[8] = { 1,2,3,4,5,6,-21,18 };
	keyin = checknum(tempnum, 8);
	cls();
	gotoxy(5, 5);
	if (keyin == -21) exit(0);
	else if (keyin == 18) return;
	else if (keyin == 1) {
		cout << "�ƺܺúȣ���������ʲô��";
		gotoxy(5, 10, "[1]��Ҫ");
		gotoxy(5, 15, "[2]����");
		keyin = checknum(tempnum, 2);
		if (keyin == 1)
		{
			cls();
			TestEngeneer();
		}
		else if (keyin == 2) exit(0);
	}
	else if (keyin == 2) {
		cout << "���Թ���ʦ�ھưɵ���һ��������\n\n"
			"���Թ���ʦC��DNA���ˣ���վ��������ִ��֪������ͻȻð��������...";
		exit(0);
	}
	else if (keyin == 5) {
		cout << "���Ȼ���˳������ư�ը��";
		Sleep(1000);
		exit(0);
	}
}

void option()
{
	while (1) {
		cls();
		gotoxy(5, 3, "������������");
		gotoxy(5, 10, "[1]�������һ����Ϊ������");
		gotoxy(5, 15, "[2]����˳��");
		gotoxy(5, 20, "[3]ÿ�δ�Ӯ�ҿ�ʼ");
		gotoxy(5, 25, "[4]�����Ʋ���UNO������");
		gotoxy(5, 30, "������Ӧ�����޸Ĳ���");
		gotoxy(5, 35, "[ESC]�˻����˵�");
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