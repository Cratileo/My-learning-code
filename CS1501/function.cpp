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
			{
				gotoxy(30, 10, "����У��ʽ��");
				cout << applyinfo[5];
				gotoxy(30, 13, "��Уʱ��: ");
				cout << applyinfo[2];
				gotoxy(30, 16, "��Уʱ��: ");
				cout << applyinfo[1];
				gotoxy(30, 19, "����У��: ");
				cout << applyinfo[4];
			}
			gotoxy(130, 35, "[ESC}�˳�");

			if (applyinfo[0] != "�����")
				gotoxy(130, 32, "[1]��������");

			else if (applyinfo[0] == "�����")
				gotoxy(130, 32, "[1]ɾ������");

			int keyin;
			while (1) {
				keyin = _getch() - 48;
				if (keyin == -21) {
					cls();
					return;
				}
				if (applyinfo[0] != "�����" && keyin == 1) {
					proc.toapply();
					gotoxy(30, 35, "����ɹ�");
					Sleep(500);
					cls();
					return;
				}
				if (applyinfo[0] == "�����" && keyin == 1) {
					proc.deleteapply();
					gotoxy(30, 35, "ɾ���ɹ�");
					Sleep(500);
					cls();
					return;
				}

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
 //������ݲ�����
void PCRDataStream() {
	string temp;
	gotoxy(20, 10, "������������Ϣ����'��'Ϊ������Ϣ�ָ�������'��'Ϊ������Ϣ�ڶ���ķָ�����");
	gotoxy(20, 12, "����'����,20220210,54749110,��Ժ,��Ժ2201,X83,ȫ�̽���;����,52203xxxxx,xxxx,��̩,xxxx,Dxx,xxxx'");
	gotoxy(20, 15);
	showcursor();
	getline(cin, temp);
	hidecursor();
	//streamprocess(temp);
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
		PCRDataStream();
}

void Application() {
	cls();
	gotoxy(30, 2, "��ǰ���ڵĴ�������Ŀ��");
	proc.teacherapply();
	gotoxy(120, 35, "[ESC]�˳�");
	int keyin;
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return;
		}
	}
}

void DormitoryManage() {
	cls();
	gotoxy(30, 5, "[1]����¥�����ѯ");
	gotoxy(30, 10, "[2]����¥��ع���");
	gotoxy(30, 15, "[ESC]����");
	int keyin;
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
		cls();
		proc.getPCR();
	}
	else if (keyin == 2) {
		string temp;
		cls();
		gotoxy(20, 3, "��������¥����");
		showcursor();
		getline(cin, temp);
		hidecursor();
		proc.setstate(temp);
		cin.clear();
	}

	gotoxy(120, 35, "[ESC]�˳�");
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return;
		}
	}
}