#pragma once
#include<string>
#include<vector>
using std::string;
using std::vector;

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
		string PCRdate = "000";
		string PCRconsequence = "NA";
	};
	string Applystate = "000";
	string ApplyIndate = "000";
	string ApplyOutdate = "000";
	string Applyreason = "NA";
	string Applycampus = "NA";
	string Applyway = "0";
};

class Processtodo {
public:
	Studentinfo st[100];

	string PCRtest();//核酸检测结果查询API
	void Infoprocess(string&);//二次分割数据入库
	string SearchAndCheck(const string&);//数据搜索与查重
	void readtest();//test
	bool checkapply(vector<string>& info);//查询是否存在申请以及返回申请记录
	void toapply();//进行申请
};



char checkaccount(string,string);  //校验输入账号是否存在

void SearchPCR();//核酸检测结果查询页面

void StudentApply();//进出校申请学生端

void BasicDataStream();//录入基本信息

void PCRDataStream();//录入核酸信息

void streamprocess(string&);	//处理字符串分割


