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
	gotoxy(20, 10, "������������Ϣ����'��'Ϊ������Ϣ�ָ�������'��'Ϊ������Ϣ�ڶ���ķָ�����");
	gotoxy(20, 12, "����'����,522031145141,54749110,��Ժ,��Ժ2201,X83-110,ȫ�̽���;����,52203xxxxx,xxxx,��̩,xxxx,Dxx-xxx,xxxx'");
	gotoxy(20, 15);
	showcursor();
	getline(cin, temp);
	hidecursor();
	streamprocess(temp);
	gotoxy(20, 30, "����ɹ�");
	gotoxy(50, 30, "[1]��������");
	gotoxy(80, 30, "[ESC]�����ϼ��˵�");
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
