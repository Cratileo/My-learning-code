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

	string PCRtest();//����������ѯAPI
	void Infoprocess(string&);//���ηָ��������
	string SearchAndCheck(const string&);//�������������
	void readtest();//test
};



bool checkaccount(string,string);  //У�������˺��Ƿ����

void SearchPCR();//����������ѯҳ��

void StudentApply();//����У����ѧ����

void BasicDataStream();//¼�������Ϣ

void PCRDataStream();//¼�������Ϣ

void streamprocess(string&);	//�����ַ����ָ�


