#pragma once
#include<string>
using std::string;

class Studentinfo {
public:
	string name = "NA";
	string id = "000";
	string telephone = "000";
	string school = "NA";
	string address = "NA";
	string classnum = "NA";
	string vaccine = "NA";
	struct PCR {
		string date = "000";
		string consequence = "NA";
	};
	struct Apply {
		string state = "000";
		string Indate = "000";
		string Outdate = "000";
		string reason = "NA";
		string campus = "NA";
	};
};

class Processtodo {
public:
	Studentinfo st[100];

	string PCRtest();//核酸检测结果查询API
	void Infoprocess(string&);//二次分割数据入库
	string SearchAndCheck(const string&);//数据搜索与查重
	void readtest();//test
};



bool checkaccount(string,string);  //校验输入账号是否存在

void SearchPCR();//核酸检测结果查询页面

void StudentApply();//进出校申请学生端

void BasicDataStream();//录入基本信息

void PCRDataStream();//录入核酸信息

void streamprocess(string&);	//处理字符串分割


