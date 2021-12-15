#include "GetStringWithoutNum.h"
#include<iostream>
using namespace std;

string Get_String_Whithout_Num(string& a,string Question)
{
	while (true)
	{
		int c = 0;
		cout << Question;
		cin >> a;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] >= '0' && a[i] <= '9')
				c++;
		}
		if (c != 0)
		{
			cin.clear();
			cout << endl << "INVALIDE INPUT!!!" << endl << " Please, try again! Enter only symbols!" << endl << endl;
		}
		else
		{
			return a;
		}
	}
}
