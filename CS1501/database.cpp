#include"Win_define.h"
#include"database.h"
#include<sstream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<format>//debug��ʱ���ã�release�мǵ�ɾ
#include<memory>
using namespace std;

static Processtodo proc;

extern int datanum = 0;//��ʼѧ����������

const char* file = "data.dat";//�����ļ�

bool checkaccount(string acc, string pw) {
	return 1;
}

void streamprocess(string& str) {
	stringstream ss(str);
	string temp;
	vector<string>temparr;

	while (getline(ss, temp, ';'))
		temparr.push_back(temp);
	for (auto& arr : temparr) {
		proc.Infoprocess(arr);
	}
}
//��ʱ�ȷ��ţ�������Ҫ�ͺ�˷��룬֮���ع�
void SearchPCR() {
	cls();
	gotoxy(10, 30, "[ESC]");
	gotoxy(0, 5);
	
	proc.readtest();

	int keyin;
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return;
		}
	}
}

void Processtodo::Infoprocess(string& str) {
	stringstream ss(str);
	Studentinfo st;
	string temp;
	vector<string>temparr;

	while (getline(ss, temp, ','))
		temparr.push_back(temp);

	if (temparr.size() != 7)//ֻ�ܴ�������ݣ�������������
	{
		gotoxy(25, 25, "ERROR:����ȱʧ������ѧ����Ŀ��Ϣ��ȫ��");
		Sleep(2000);
		return;
	}

	//д��data.dat(�����Ʒ�ʽ��   

	//���ݲ���
	/*if (SearchAndCheck(temparr[1]) != "pass") {
		gotoxy(25, 28, "ERROR:�����ظ�ѧ��:");
		Sleep(2000);
		return;
	}*/

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open()) {
		cerr << "�޷���" << file << ",���ִ���";
		exit(EXIT_FAILURE);
	}


	st.name = temparr[0];
	st.id = temparr[1];
	st.telephone = temparr[2];
	st.school = temparr[3];
	st.address = temparr[5];
	st.classnum = temparr[4];
	st.vaccine = temparr[6];

	fout.write((char*)&st, sizeof Studentinfo);	
	fout.close();
}

string Processtodo::SearchAndCheck(const string &idT) {
	Studentinfo st;
	fstream finout;
	string defaul{"pass"};
	finout.open(file, ios::in | ios::out | ios::binary);
	if (finout.is_open()) {
		finout.seekg(0);
		while (finout.read((char*)&st, sizeof st)) {
			if (st.id == idT) {
				cout << st.name;
				defaul = idT;
				break;
			}
		}
	}
	finout.close();
	return defaul;
}

void Processtodo::readtest() {
	ifstream fread;
	{
		Studentinfo st;
		
		fread.open(file, ios_base::in | ios_base::binary);
		fread.seekg(0);
		while (fread.read((char*)&st, sizeof Studentinfo)) {
			cout <<
				format("{} {} {} {} {} {} {}", st.name, st.id, st.telephone, st.school, st.address, st.classnum, st.vaccine)
				<< endl;
		}
		if (fread.eof())
			fread.clear();
		else
		{
			cerr << "ERROR";
			exit(EXIT_FAILURE);
		}
	}
	fread.close();
}