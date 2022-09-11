//Practice2，一个不知道有什么用的练习代码（同样也有无法理解的bug）
#include<iostream>
#include<string>
using namespace std;
void anc(int n);
double num_input(double x);

int main()
{
	cout << "Please enter a number in N gathers: ______\b\b\b\b\b\b";//试试输入9以上的数字，会有惊喜
	int number;
	cin >> number;
	double temp = num_input(number);
	cout << endl << temp;
	anc(number);
	cout << "please leave your star for this service:";
	int star;
	cin >> star;
	if (star > 1 && star < 5)
		if (star >= 1 && star <= 3)
		{
			cout << "please leave your comment,we will imporve it:\n";
			string comment;
			getline(cin, comment);
			cin.get();
			cout << "\nthanks for your feedback!\a";
		}
		else if (star > 3)
			cout << "thanks for your love.";
		else
			cout << "sorry,i don't understand your means.";
	else
		cout << "are you joking?Your stars are over the edge of our system!\a";
	return 0;
}
void anc(int n)
{
	cout << "\nyou do a good job\n";
	for (int i = 0; i < n; ++i)
	{
		cout << "enjoy you loop ohhhhhhh!\a\a\a\a\n";
	}
}
double num_input(double x)
{
	int j = x;
	for (int i = 0; i < j; ++i)
	{
		x = x * x;
		cout << "loop! ";
	}
	return x;
}
