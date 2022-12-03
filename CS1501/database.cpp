#include"Win_define.h"
#include"database.h"
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<atltime.h>	//获取系统时间
#include<format>//debug临时引用，release中记得删
#include<memory>
using namespace std;

CTime t1 = CTime::GetCurrentTime();

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
	/*将account.txt中的数据写入serach二维数组中,遍历这个数组匹配账号和密码，
	并返回匹配的账户种类，进入对应的页面，实现账号系统分离*/

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

	/*用stringstream函数处理输入的字符串，以';'为条目分隔符，','为条目中的信息分隔符*/

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
		Sleep(800);
		exit(EXIT_FAILURE);
	}


	st.name = temparr[0];
	st.id = temparr[1];
	st.telephone = temparr[2];
	st.school = temparr[3];
	st.address = temparr[5];
	st.classnum = temparr[4];
	st.vaccine = temparr[6];

	fout.write((char*)&st, sizeof Studentinfo) << flush;
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
				format("{} {} {} {} {} {} {}", st.name, st.id, st.telephone, st.school, st.classnum, st.address, st.vaccine)
				<< endl;
		}
/*		if (fread.eof())
			fread.clear();
		else
		{
			cerr << "ERROR";
			exit(EXIT_FAILURE);
		}*/
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
	}
	fread.close();
	return false;
}

void Processtodo::toapply() {
	fstream finout;
	finout.open(file, ios::in | ios::out | ios::binary);
	{
		Studentinfo st;
		string name;
		long ct = 0;
		if (!finout.is_open()) {
			cerr << file << " could not be opened";
			Sleep(1000);
			exit(EXIT_FAILURE);
		}
		finout.seekg(0);

		while (finout.read((char*)&st, sizeof Studentinfo)) {
			if (st.id == accountNOW) {
				name = st.name;
				break;
			}
			ct++;
		}
		streampos place = ct * sizeof Studentinfo;	//用于记录该条记录的位置，不必重复重头查，优化程序

		while (1) {
			cls();
			gotoxy(60, 5, "上海交通大学学生进出校审批流程");
			gotoxy(30, 10, "姓名：");
			cout << name;
			gotoxy(70, 10, "学号：");
			cout << accountNOW;
			gotoxy(30, 13, "进出校方式（填数字），[1]仅进校；[2]仅出校;[3]先进后出;[4]先出后进:   ");
			showcursor();
			getline(cin, st.Applyway);

			if (st.Applyway == "1") {
				gotoxy(30, 16, "进校时间，格式YYMMDD，如20221202:  ");
				getline(cin, st.ApplyIndate);
			}
			else if (st.Applyway == "2") {
				gotoxy(30, 16, "出校时间，格式YYMMDD，如20221202:  ");
				getline(cin, st.ApplyOutdate);
			}
			else if (st.Applyway == "3" || st.Applyway == "4") {
				gotoxy(30, 16, "进校时间，格式YYMMDD，如20221202:  ");
				gotoxy(30, 19, "出校时间，格式YYMMDD，如20221202:  ");
				gotoxy(80, 16);
				getline(cin, st.ApplyIndate);
				gotoxy(80, 19);
				getline(cin, st.ApplyOutdate);
			}
			else {
				cout << "数据错误，重新开始流程";
				Sleep(1000);
				continue;
			}

			gotoxy(30, 22, "选择校区[1]徐汇校区，[2]闵行校区   ");
			getline(cin, st.Applycampus);
			gotoxy(30, 25, "理由填写：");
			getline(cin, st.Applyreason);

			//applystate为审批状态（“000”为默认无审批，“W”为待审批，“P”为审批通过，“B”为审批驳回）
			st.Applystate = "待审核";
			if (st.Applycampus != "1" && st.Applycampus != "2") {
				cout << "数据错误，重新开始流程";
				Sleep(1000);
				continue;
			}
			break;
		}
		//开始写入文件
		finout.seekg(place);
		finout.write((char*)&st, sizeof Studentinfo) << flush;
		if (finout.fail()) {
			cerr << "ERROR,无法读写文件";
			Sleep(1000);
			exit(EXIT_FAILURE);
		}
	}
	finout.close();
}