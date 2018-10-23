//
// Created by swchen on 18-10-23.
//

#ifndef SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H
#define SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H

#include <iostream>
#include <map>
#include <list>

#include "ArduinoJson/ArduinoJson.h"

const int list_json_len = 10000;
const int map_json_len = 10000;


using namespace std;

namespace SwChen {

    namespace tools {


        /**
         * this functin is used to serialize list<int>, list<double> and some other list of basic type;
         * this function can also support the serialization of list<string>
         * the result of serializing of list<int> should be like '[1,2,3,4]'
         * the result of serializing of list<string> should be like '["str1","str2","str3"]'
        */
        template<typename _T>
        const string serialize(const list<_T> &_list) {

            StaticJsonBuffer<list_json_len> jsonBuffer;
            JsonArray &array_json = jsonBuffer.createArray();

            auto it_end = _list.end();
            for (auto it_list = _list.begin(); it_list != it_end; ++it_list) {
                array_json.add(*it_list);
            }

            string output;
            array_json.printTo(output);

            return output;
        }

        template <typename _T>
        list<_T> deserialize(const string &json){

            StaticJsonBuffer<list_json_len> jsonBuffer;
            JsonArray &array_json = jsonBuffer.parse(json);

            list<_T> _list;

            auto index_end = array_json.size();
            for(int index = 0;index != index_end; ++index){
                _T item = array_json[index];
                _list.push_back(item);
            }

            return _list;

        }


        const string serialize(const map<string, string> _map){
            StaticJsonBuffer<map_json_len> jsonBuffer;
            JsonObject &object_json = jsonBuffer.createObject();

            auto it_end = _map.end();
            for(auto it_map = _map.begin(); it_map != it_end;++it_map){
                object_json[it_map->first] = it_map->second;
            }

            string output;
            object_json.printTo(output);

            return output;
        }

    }
}

#endif //SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H
