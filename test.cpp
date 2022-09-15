#include<iostream>
#include<ctime>
int main()
{
    using namespace std;
    char ch;
    cin >> ch;
    while (ch != '/')
    {
        cout << ch;
        cin >> ch;
    }
    return 0；
}