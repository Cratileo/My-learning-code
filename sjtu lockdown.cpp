//来玩这个贵交封闭化管理小游戏吧...
#include<iostream>
#include<string>
#include<random>
#include<Windows.h>

std::default_random_engine e;
std::uniform_int_distribution<unsigned> u(0, 3);
std::uniform_int_distribution<unsigned> c(0, 1);
std::uniform_int_distribution<unsigned> a(1, 7);

void student_free();         //半自由学生
void student_lock();        //2+5或七天学生
void student_outside();    //还在来的路上
void student_quarantined();//喜提转运
void cainiao();          //菜鸟驿站事件
void domitory();        //宿舍事件
void supermaket();     //西区教超事件
void henu();          //华师大事件
auto check();   //选择校验函数
void shuiyuan();      //水源事件

using std::cout;
using std::cin;

int main()
{
	using namespace std;
	cout << "welcome to join our game named lockdown school.\n";
	cout << "in this game,you will play one of various role in lockdown life.\n";
	cout << "now you can start to enjoy your remote class or quarantined life,";
	cout << "and it is absolutely random for your character.\n";
	if (u(e) == 0)
		student_free();
	else if (u(e) == 1)
		student_lock();
	else if (u(e) == 2)
		student_outside();
	else if (u(e) == 3)
		student_quarantined();
	else
		cout << "Something goes wrong,please restart the progress!\a";
	cout << "Game over.Thanks for your play.\n"
		<< "Do you want to look something interesting?\n";
	char* n = new char;
	cin >> n;
	strlwr(n);
	while (!(strcmp(n, "y") || strcmp(n, "n")))
	{
		cout << "\nTell me your choice OK?:";
		cin >> n;
		cin.clear();
	}
	if (strcmp(n, "y"))
	{
		cout << "少女折寿中……\n";
	}
	_sleep(5 * 1000);
	return 0;
}

auto check()
{
	char* n = new char;
	cin >> n;
	strlwr(n);
	while (!(strcmp(n, "a") || strcmp(n, "b")))
	{
		cout << "\nTell me your choice OK?:";
		cin >> n;
		cin.clear();
	}
	return n;
}

void student_free()
{

	cout << "You are a lucky guy.Must't be lock in the domitory.\n";
	cout << "Now you will go to (";
	system("pause");
	if (u(e) == 0)
	{
		cout << "CaiNiao station.\n";
		cainiao();
	}
	else if (u(e) == 1)
	{
		cout << "nowhere and stay at domitory.\n";
		domitory();
	}
	else if (u(e) == 2)
	{
		cout << "educational supermarket in west area.\n";
		supermaket();
	}
	else if (u(e) == 3)
	{
		cout << "outside of school to liberate the HENU.\n";
		henu();
	}
	else
		cout << "Something goes wrong,please restart the progress!\a";
}

void student_lock()
{
	cout << "So bad,your domitory building have a pacient contacter,and you";
	cout << "should be stay at your donitory 7 days.\n";
	cout << "enjoy your lunch!and don't forget to attend your class meeting ";
	cout << "in virus meeting room.\n";
	system("pause");
	cout << "-------------------7days after-------------------\n";
	if (c(e) == 0)
	{
		cout << "Peace and nothing,you are finally released.\n";
		cout << "now you wanna to:\nA)sign in Shuiyuan and battle with other\n";
		cout << "B)do yourself and don't speak a word.\nYour choice is: ";
		auto input = check();     //使用check函数进行检测
		if (strcmp(input, "a"))
		{
			cout << "\nSir,this way";
			_sleep(3 * 1000);
			//ShellExecute(NULL, "open", "https://shuiyuan.sjtu.edu.cn/", NULL, NULL, SW_SHOWNORMAL);//先不管这个了
		}
		else
		{
			cout << "\nOK,hope you have a nice day";
		}
		delete input;
	}
}

void student_outside()
{
	cout << "Now you are in the Shanghai Hongqiao Int' Airport,and will go back to SJTU\n";
	cout << "It seems you are so boring,At this time you want:\n";
	cout << "A)Play 'Yuanshen'       B)Look through Shuiyuan\n";
	char* choice = check();
	if (strcmp(choice, "a"))
	{
		cout << "miHoYo's games always are full of attractive.Unconsciously,you arrive SJTU.\n";
		cout << "However,you feel something strange on the gate,This time,you: \n";
		cout << "A)just go ahead,it is normal in SJTU   B)Look Shuiyuan\n";
		cout << "You choice is: ";
		char *input = check();
		if (strcmp(input, "a"))
		{
			if (c(e) == 0)
			{
				cout << "\nluckily,you are safe....temporarily\n";
				student_free();
			}
			else if (c(e) == 1)
			{
				cout << "Shit!Your domitory building have a suspector,you need to be quarantined two days.\n";
				student_lock();
			}
		}
		else
		{
			shuiyuan();
		}
		delete input;
	}
	else
	{
		shuiyuan();
	}
	delete choice;
}

void student_quarantined()
{
	cout << "You have been quarantined at hotal outschool for 10 days.\n";
	cout << "You don't have any choice,good luck for you.\n";
	cout << "oh!I forget it.You can choose which days you want to be transpotated.(\n";
}

void cainiao()
{
	cout << "Get the express parcel is always a delighting thing.\n";
	cout << "-------------------1days after-------------------\n";
	cout << "Messages posted on shuiyuan makes you scared.\n";
	for (int i = 0; i < 7; ++i)
	{
		cout << "one day pass...\n";
		if (c(e) == 0)
		{
			cout << "Strangely,today nobody find you or call you.\n";
		}
		else
		{
			cout << "the big thing is coming";
			student_quarantined();
		}
	}
}

void domitory()
{
	cout << "You decide to stay at your domitory to sleep.\n";
	cout << "-------------------1days after-------------------\n";
	cout << "You are hungery now.";
	if (c(e) == 0)
	{
		cout << "but luckily you have enough food storage in your room.\n";
		cout << "you don't need to go to buy anything.\n";
		cout << "-------------------7days after-------------------\n"
			 << "One week pass,life return peace,Now you can move freely";
	}
	else
	{
		cout << "What's worse,you decide to buy something.\n";
		cout << "you decide go to:\n";
		cout << "A)Edu-supermarket in East area.\n";
		cout << "B)store around the canteen.\n";
		char *choice = check();
		if (strcmp(choice, "a"))
		{
			supermaket();
		}
		else
		{
			cout << "You come to store to buy lots goods.\n";
			cout << "-------------------1days after-------------------\n";
			cout << "Luckily,you are still safe.\n";
		}
		delete choice;
	}
}

void supermaket()
{
	cout << "You come to Edu-supermarket in East area and buy lots goods.\n";
	cout << "-------------------1days after-------------------\n";
	cout << "Shit you have become a suspect.Now you need to be quarantined.\n";
	student_quarantined();
}

void henu()
{
	cout << "You decide to apply a mutiple-code to run to HENU\n"
		<< "At the temple gate,security let you rush out fast.\n"
		<< "You feel puzzled.After leave SJTU,you sign in shuiiyuan want to understand what's happen.\n";
	shuiyuan();
	cout << "---------------You are a lucky dog---------------\n"
		<< ">>>>>Hidden Achievement:Run!<<<<<";
}

void shuiyuan()
{
	cout << "You open the shuiyuan community,hoping to find some post.\n"
		<< "You find the top one saying the outbreak in campus.\n"
		<< "Run now!\n"
		<< "You feel delight for your escape.\n";
}