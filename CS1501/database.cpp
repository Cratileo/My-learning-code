#include"Win_define.h"
#include"database.h"
#include<sstream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<format>//debug��ʱ���ã�release�мǵ�ɾ
using namespace std;

extern int datanum = 0;//��ʼѧ����������

const char* file = "data.dat";//�����ļ�

bool checkaccount(string acc, string pw) {
	return 1;
}

Studentinfo st;

void streamprocess(string& str) {
	stringstream ss(str);
	string temp;
	vector<string>temparr;

	while (getline(ss, temp, ';'))
		temparr.push_back(temp);
	for (auto& arr : temparr) {
		st.Infoprocess(arr);
	}
}
//��ʱ�ȷ��ţ�������Ҫ�ͺ�˷��룬֮���ع�
void SearchPCR() {
	cls();
	gotoxy(10, 30, "[ESC]");
	gotoxy(0, 5);
	st.readtest();
	int keyin;
	while (1) {
		keyin = _getch() - 48;
		if (keyin == -21) {
			cls();
			return;
		}
	}
}

void Studentinfo::Infoprocess(string& str) {
	stringstream ss(str);
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
	if (SearchAndCheck(temparr[1])!="pass") {
		gotoxy(25, 28, "ERROR:�����ظ�ѧ��:");
		Sleep(2000);
		return;
	}

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open()) {
		cerr << "�޷���" << file << ",���ִ���";
		exit(EXIT_FAILURE);
	}


	name = temparr[0];
	id = temparr[1];
	telephone = temparr[2];
	school = temparr[3];
	address = temparr[4];
	classnum = temparr[5];
	vaccine = temparr[6];

	fout.write((char*)this, sizeof this);	
	fout.close();
}

string Studentinfo::SearchAndCheck(const string &idT) {
	fstream finout;
	string defaul{"pass"};
	finout.open(file, ios::in | ios::out | ios::binary);
	if (finout.is_open()) {
		finout.seekg(0);
		while (finout.read((char*)this, sizeof this)) {
			if (id == idT) {
				cout << name;
				defaul = idT;
				break;
			}
		}
	}
	finout.close();
	return defaul;
}

void Studentinfo::readtest() {
	fstream fread;
	fread.open(file, ios_base::in | ios_base::out | ios_base::binary);
	fread.seekg(0);
	while (fread.read((char*)this, sizeof this)) {
		cout << format("{} {} {} {} {} {} {}", name, id, telephone, school, address, classnum, vaccine) << endl;
	}
	if (fread.eof())
		fread.clear();
	else
	{
		cerr << "ERROR";
		exit(EXIT_FAILURE);
	}
	fread.close();
}