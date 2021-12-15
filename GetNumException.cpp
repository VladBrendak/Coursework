#include "GetNumException.h"
#include<iostream>
using namespace std;

int Get_Num_Without_Ex(int& value, std::string Question)
{
    int Ex;
    while (true)
    {
        cout << Question;
        cin >> Ex;
        cout << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "ERROR:   !!!Incorrect input!!! Enter numbers!!! Try Again!!!\n" << endl;
        }
        else
        {
            value = Ex;
            return Ex;
        }
    }
}
