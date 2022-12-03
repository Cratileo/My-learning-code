#include"Win_define.h"
#include"database.h"
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<format>//debug临时引用，release中记得删
#include<memory>
using namespace std;

extern string accountNOW = "000";

extern Processtodo proc{};

extern int datanum = 0;//初始学生数据条数

const char* file = "data.dat";//数据文件

char checkaccount(string acc, string pw) {
	ifstream fread;
	vector<vector<string> >serach;
	vector<string>temparr;
	string tempA;

	//account.txt文件内储存账号，密码，学工号,类型四条信息，目前未加密，期望实现RSA加密
	fread.open("account.txt", ios_base::in);
	if (!fread.is_open()) {
		cerr << "ERROR,CAN NOT OPEN THIS FILE.";
		exit(EXIT_FAILURE);
	}

	serach.resize(100);
	int ct = 0;
	fread.ignore();

	while (getline(fread, tempA)) {
		fread >> tempA;
		string temp;
		stringstream ss(tempA);
		while (getline(ss, temp, ','))
			serach[ct].push_back(temp);
		ct++;
	}

	fread.close();
	serach.resize(ct - 1);

	for (auto tp : serach) {
		if (tp[0] == acc)
			if (tp[1] == pw) {
				accountNOW = tp[2];
				if (tp[3] == "student") return 'S';
				else if (tp[3] == "teacher") return 'T';
			}
	}
	return 'F';
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
//暂时先放着，但界面要和后端分离，之后重构
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

	if (temparr.size() != 7)//只能存基本数据，核酸另行输入
	{
		gotoxy(25, 25, "ERROR:数据缺失（部分学生条目信息不全）");
		Sleep(2000);
		return;
	}

	//写入data.dat(二进制方式）   

	//数据查重
	/*if (SearchAndCheck(temparr[1]) != "pass") {
		gotoxy(25, 28, "ERROR:存在重复学号:");
		Sleep(2000);
		return;
	}*/

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open()) {
		cerr << "无法打开" << file << ",出现错误";
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

bool Processtodo::checkapply(vector<string>& info) {
	ifstream fread;
	{
		Studentinfo st;
		fread.open(file, ios_base::in | ios_base::binary);
		fread.seekg(0);
		while (fread.read((char*)&st, sizeof Studentinfo)) {
			if (st.id == accountNOW) {
				if (st.Applystate != "000") {
					info.push_back(st.Applystate);
					info.push_back(st.ApplyIndate);
					info.push_back(st.ApplyOutdate);
					info.push_back(st.Applyreason);
					info.push_back(st.Applycampus);
					info.push_back(st.Applyway);
					fread.close();
					return true;
				}
				else break;
			}
		}
		fread.close();
		return false;
	}
}