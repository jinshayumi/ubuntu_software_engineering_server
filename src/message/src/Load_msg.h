//
// Created by swchen on 18-10-24.
//

#ifndef SOFTWARE_ENGINEERING_LOAD_MSG_H
#define SOFTWARE_ENGINEERING_LOAD_MSG_H

#include <iostream>
#include <string>

#include "ArduinoJson/ArduinoJson.h"
#include "MD5_coding/md5.h"

#include "Define_Member.h"

using namespace std;

namespace SwChen{

    namespace message{

        class Load_msg{
        public:
            DEFINE_SIMPLE_MEMBER(acount, string);
            DEFINE_SIMPLE_MEMBER(password, string);

        public:
            static void serialize(JsonObject &root, void *load_msg);
            static void deserialize(JsonObject &root, void *&load_msg);
        };
    }
}

#endif //SOFTWARE_ENGINEERING_LOAD_MSG_H
