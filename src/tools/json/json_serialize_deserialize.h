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
         * this functin is used to serialize list<_T>, _T should be int, double and some other basic type;
         * this function can also support the serialization of list<string>
         * the result of serializing of list<int> should be like '[1,2,3,4]'
         * the result of serializing of list<string> should be like '["str1","str2","str3"]'
         * do not try to serialize the list whose type is defined by users
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

        /**
         * this functin is used to deserialize a json string to list<_T>,
         * _T can be int, double, and some other basic type;
         * this function can also support the deserialization of list<string>
         * do not try to deserialize the list whose type is defined by users
        */
        template <typename _T>
        void deserialize(list<_T> &_list, const char *json){

            StaticJsonBuffer<list_json_len> jsonBuffer;
            JsonArray &array_json = jsonBuffer.parse(json);

            if (!array_json.success()){
                return;
            }

            auto index_end = array_json.size();
            for(int index = 0;index != index_end; ++index){
                _T item = array_json[index];
                _list.push_back(item);
            }

        }

        /**
         * this functin is used to serialize string<string, _T>,
         * _T should be int, double and some other basic type;
         * this function can also support the serialization of map<string, string>;
         * the result of serializing of map<string, int> should be like '{"first":1, "second":2}';
         * the result of serializing of map<string, string> should be like '{"first":"1", "second":"2"}'
        */
        template <typename _T>
        const string serialize(const map<string, _T> _map){
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

        /**
         * this functin is used to deserialize a json string to map<string, _T>,
         * _T can be int, double, and some other basic type;
         * this function can also support the deserialization of map<string, string>;
         * do not try to deserialize the map whose value's type is defined by users
         * example: map<string, CLASS_USER> is illegal in this function
        */
        template <typename _T>
        void deserialize(map<string, _T> &_map, const char *json){
            StaticJsonBuffer<map_json_len> jsonBuffer;
            JsonObject &object_json = jsonBuffer.parse(json);

            if (!object_json.success()){
                return;
            }

            auto it_end = object_json.end();
            for(auto it = object_json.begin();it != it_end; ++it){
                string key = it->key;
                _T value = it->value;
                _map[key] = value;
            }

        }
    }
}

#endif //SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H
