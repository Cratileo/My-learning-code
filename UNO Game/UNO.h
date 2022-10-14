#pragma once
class UNO_play
{
	int card_one;            //UNO牌类储存
};

class Rule
{
	bool setting[3];     //0为最后一张牌是否可以为功能牌，1为顺时针还是逆时针开始，2为每次从赢的人开牌还是player1
	int uno_add;
public:
	void show_rule();
	void change_rule(int);
	void change_num();
	Rule();

};

void show_someting();//与change_rule配合用的，用于简化输出
