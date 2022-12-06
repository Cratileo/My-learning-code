#pragma once
#include<string>
#include<vector>
#include<ATLComTime.h>	//获取系统时间
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

	string PCRstate = "NA";//核酸状态：24小时/48小时/72小时

	string Applystate = "000";
	string ApplyIndate = "000";
	string ApplyOutdate = "000";
	string Applyreason = "NA";
	string Applycampus = "NA";
	string Applyway = "1";

	PCR pcrinfo[7]; //支持查询最近七次核酸记录
};

class Dormitory {
public:
	string buildingname = "NA";
	string state = "NA";
	COleDateTime starttime{};
	COleDateTime endtime{};
	long people = 0;
	long PCRpeople = 0;
};

class Processtodo {
public:
	Studentinfo st[100];
	Dormitory dom[40];

	string PCRtest();//核酸检测结果查询API
	void Infoprocess(string&);//二次分割数据入库
	string SearchAndCheck(const string&);//数据搜索与查重
	void readtest();//test
	bool checkapply(vector<string>& info);//查询是否存在申请以及返回申请记录
	void toapply();//进行申请
	void deleteapply();//学生删除申请
	void teacherapply();//教师审批出入校
	void getPCR(); //获取宿舍楼核酸人数
	void setstate(string&); //设置楼栋状态
	void showdormitory();	//显示按解封时间排序的被封控楼栋
};



char checkaccount(string,string);  //校验输入账号是否存在

void SearchPCR();//核酸检测结果查询页面

void StudentApply();//进出校申请学生端

void BasicDataStream();//录入基本信息

void PCRDataStream();//录入核酸信息

void streamprocess(string&);	//处理字符串分割

void Application();	//进出校申请教师端

void DormitoryManage();//宿舍楼管理界面
