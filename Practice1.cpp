//Practice 1,一个针对销售商的简易车辆计数器（并且bug丛生）
#include<iostream>
#include<string>
struct car {
	std::string brand;
	int year;
    int own;
};
int main()
{
	using namespace std;
	int num;
	cout << "Please enter the number of car: ";
	cin >> num;
    //对输入数进行检测，
	if (cin.good()&&num>0)//对于小于零的数无法报错也不会通过，而是重新输入但不显示提示词
		cout;
	else
	{
		while (!(cin >> num)&&num<=0)//加了&&以后在第二次出现负数时直接报错‘absorb has been called’
		{
			cout << "Wrong data,try again\a\n";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
	}
	car* user = new car[num];
	for (int i = 0; i < num; ++i)
	{
		cout << "Car #" << i+1 << endl;
		cout << "Please enter the mark:";
		getline(cin,user[i].brand);
		cin.get();
		cout << "\nPlease enter the year made:";
		cin>>user[i].year;
        cout<<"\nPlease enter how many car this kind you have:";
        cin>>user[i].own;
	}
	cout << "\nhere is your collection:\n";
	for (int i = 0; i < num; ++i)
	{
		cout << (*(user+i)).brand << "  " << (*(user+i)).year <<"  "<<user[i].own<< endl;//无法显示brand,但可以显示year和own
	}
	delete[]user;
	return 0;
}