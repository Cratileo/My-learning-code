#pragma once
class UNO_play
{
	int card_one;            //UNO���ഢ��
};

class Rule
{
	bool setting[3];     //0Ϊ���һ�����Ƿ����Ϊ�����ƣ�1Ϊ˳ʱ�뻹����ʱ�뿪ʼ��2Ϊÿ�δ�Ӯ���˿��ƻ���player1
	int uno_add;
public:
	void show_rule();
	void change_rule(int);
	void change_num();
	Rule();

};

void show_someting();//��change_rule����õģ����ڼ����
