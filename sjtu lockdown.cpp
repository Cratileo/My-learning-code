#include<iostream>
#include<string>
#include<random>

struct lockdown
{
	int state;
	int day;
};

std::default_random_engine e;
std::uniform_int_distribution<unsigned> u(0, 3);
std::uniform_int_distribution<unsigned> c(0, 1);
std::uniform_int_distribution<unsigned> a(1, 7);

lockdown sjtu(lockdown n, lockdown m);
int student_free();
int student_lock();
int student_outside();
int student_quarantined();
void cainiao();
void domitory();
void supermaket();
void henu();

int main()
{
	using namespace std;
	cout << "welcome to join our game named lockdown school.\n";
	cout << "in this game,you will play one of various role in lockdown life.\n";
	cout << "now you can start to enjoy your remote class or quarantined life,";
	cout << "and it is absolutely random for your character.\n";
	cout << "";
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
	return 0;
}
lockdown sjtu(lockdown n, lockdown m)
{

}

int student_free()
{
	using namespace std;

	cout << "You are a lucky guy.Must't be lock in the domitory.\n";
	cout << "Now you will go to ";
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
