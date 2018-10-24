//
// Created by swchen on 18-10-23.
//

#include<iostream>

using namespace std;

typedef int(*F)();

int f1(){}
int f2(){}
int f3(){}
int f4(){}
int f5(){}

F funcs[] = {
        f1,
        f2,
        f3
};

int main()
{
    return 0;
}