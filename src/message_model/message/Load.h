//
// Created by swchen on 18-10-24.
//

#ifndef SOFTWARE_ENGINEERING_LOAD_MSG_H
#define SOFTWARE_ENGINEERING_LOAD_MSG_H

#include <iostream>
#include <string>
#include <utility>
#include "ArduinoJson/ArduinoJson.h"
#include "MD5_coding/md5.h"

#include "Define_Member.h"
#include "Const_Values.h"

using namespace std;
using namespace SwChen::tools;

#define Load_json_len 1000

namespace SwChen {

    namespace message {

        class Load {
        public:
            explicit Load(string acount = _STRING, string password = _STRING,
                     string ip = _STRING, string port = _STRING, string device = _STRING) :
                    acount(std::move(acount)),
                    password(std::move(password)),
                    ip(std::move(ip)),
                    port(std::move(port)),
                    device(std::move(device)) {
                cout << "Load_msg constructor" << endl;
            }

        DEFINE_SIMPLE_MEMBER(acount, string);
        DEFINE_SIMPLE_MEMBER(password, string);
        DEFINE_SIMPLE_MEMBER(ip, string);
        DEFINE_SIMPLE_MEMBER(port, string);
        DEFINE_SIMPLE_MEMBER(device, string);

        public:
            static void serialize(JsonObject &root, const void *load);

            static void deserialize(const string &json, void *&load);
        };
    }
}

#endif //SOFTWARE_ENGINEERING_LOAD_MSG_H
