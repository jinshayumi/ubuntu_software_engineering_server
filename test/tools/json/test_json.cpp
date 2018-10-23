//
// Created by swchen on 10/23/18.
//

#include<iostream>
#include<list>
#include<string>

#include "json/json_serialize_deserialize.h"

using namespace std;
using namespace SwChen::tools;

void test_list_int_string(){

    list<string> str_list;
    str_list.push_back("str1");
    str_list.push_back("str2");
    str_list.push_back("str3");
    cout<<serialize(str_list)<<endl;

    list<int> int_list;
    int_list.push_back(1);
    int_list.push_back(2);
    int_list.push_back(3);
    cout<<serialize(int_list)<<endl;

}

void test_map_string_string(){

    map<string, string> str_str_map;
    str_str_map["first"] = "1";
    str_str_map["second"] = "2";
    str_str_map["third"] = "3";

    cout<<serialize(str_str_map)<<endl;

}
int main()
{

    test_list_int_string();
    test_map_string_string();

    return 0;
}