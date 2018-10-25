//
// Created by swchen on 18-10-23.
//

#include<iostream>

#include "tools/Const_Values.h"

using namespace std;
using namespace SwChen::tools;

int main()
{
    string str = _STRING;
    int in = _INT;
    string _str = move(str);
    string __str = _STRING;
    cout<<__str<<endl;

    int _in = move(in);
    int __in = _INT;
    cout<<__in<<endl;
    return 0;
}