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
			gotoxy(30, 5, "��������״̬��");
			cout << applyinfo[0];
			int temp = stoi(applyinfo[5]);
			switch (temp) {
			case 0: gotoxy(30, 10, "����У��ʽ������У");
				gotoxy(30, 15, "��Уʱ��");
				cout << applyinfo[2];
				break;
			case 1: gotoxy(30, 10, "����У��ʽ������У");
				gotoxy(30, 15, "��Уʱ��:");
				cout << applyinfo[1];
				break;
			case 2: gotoxy(30, 10, "����У��ʽ�������Ƚ����");
				gotoxy(30, 15, "����Уʱ�䣺");
				cout << applyinfo[1];
				break;
			case 3: gotoxy(30, 10, "����У��ʽ�������ȳ����");
				gotoxy(30, 15, "����Уʱ��");
				cout << applyinfo[1];
				break;
			}
			gotoxy(130, 35, "[ESC}�˳�");
			int keyin;
			while (1) {
				keyin = _getch() - 48;
				if (keyin == -21) return;
			}
		}
		gotoxy(30, 10, "δ��ѯ�������¼");
		gotoxy(30, 20, "[1]�ύ������");
		gotoxy(30, 25, "[ESC]�˳�");
		while (1) {
			keyin = _getch() - 48;
			if (keyin == -21) {
				cls();
				return;
			}
			else if (keyin == 1) {
				proc.toapply();
				gotoxy(30, 35, "����ɹ�");
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
