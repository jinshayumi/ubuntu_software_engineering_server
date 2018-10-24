//
// Created by swchen on 10/23/18.
//

#include<iostream>
#include<list>
#include<string>

#include "json/json_serialize_deserialize.h"

using namespace std;
using namespace SwChen::tools;

void test_serialize_list_int_string_bool(){

    cout<<"test_list_serialize"<<endl<<endl;

    list<string> str_list;
    str_list.emplace_back("str1");
    str_list.emplace_back("str2");
    str_list.emplace_back("str3");
    cout<<serialize(str_list)<<endl;

    list<int> int_list;
    int_list.emplace_back(1);
    int_list.emplace_back(2);
    int_list.emplace_back(3);
    cout<<serialize(int_list)<<endl;

    list<int> bool_list;
    bool_list.emplace_back(true);
    bool_list.emplace_back(false);
    bool_list.emplace_back(true);
    cout<<serialize(bool_list)<<endl;

    cout<<"##########################"<<endl<<endl;

}
void test_deserialize_list_int_string(){

    cout<<"test_list_deserialize"<<endl<<endl;

    const char *list_int("[1,2,3]");
    list<int> int_list;
    deserialize(int_list, list_int);

    auto it_end = int_list.end();
    for(auto it = int_list.begin(); it !=it_end; ++it){
        cout<<*it<<endl;
    }

    const char *list_str(R"(["str1","str2","str3"])");
    list<string> str_list;
    deserialize(str_list, list_str);

    auto it_end_ = str_list.end();
    for(auto it = str_list.begin(); it !=it_end_; ++it){
        cout<<*it<<endl;
    }

    cout<<"##########################"<<endl<<endl;

}
void test_serialize_map_stringString_stringInt(){

    cout<<"test_map_serialize"<<endl<<endl;

    map<string, string> str_str_map;
    str_str_map["first"] = "1";
    str_str_map["second"] = "2";
    str_str_map["third"] = "3";

    cout<<serialize(str_str_map)<<endl;

    cout<<"##########################"<<endl<<endl;

}
void test_deserialize_map_stringString_stringInt(){

    cout<<"test_map_deserialize"<<endl<<endl;

    const char *map_str_str(R"({"first":"1","second":"2"})");
    map<string,string> _map;
    deserialize(_map, map_str_str);

    auto it_end = _map.end();
    for(auto it = _map.begin(); it !=it_end; ++it){
        cout<<it->first<<":"<<it->second<<endl;
    }

    const char *map_str_int(R"({"first":1,"second":2})");
    map<string, int> __map;
    deserialize(__map, map_str_int);

    auto it_end_ = __map.end();
    for(auto it = __map.begin(); it !=it_end_; ++it){
        cout<<it->first<<":"<<it->second<<endl;
    }

    cout<<"##########################"<<endl<<endl;

}
int main()
{

    test_serialize_list_int_string_bool();
    test_deserialize_list_int_string();

    test_serialize_map_stringString_stringInt();
    test_deserialize_map_stringString_stringInt();

    return 0;
}