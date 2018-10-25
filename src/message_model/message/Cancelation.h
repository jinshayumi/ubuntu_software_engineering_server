//
// Created by swchen on 18-10-25.
//

#ifndef SOFTWARE_ENGINEERING_CANCELATION_H
#define SOFTWARE_ENGINEERING_CANCELATION_H

#include <iostream>
#include <string>

#include "MD5_coding/md5.h"

#include "Const_Values.h"
#include "Define_Member.h"

#include "ArduinoJson/ArduinoJson.h"

using namespace std;
using namespace SwChen::tools;

#define Cancelation_json_len 1000

namespace SwChen{

    namespace message{

        class Cancelation{

        public:
            Cancelation(string acount = _STRING, string device = _STRING):
                    acount(move(acount)),
                    device(move(device)){
                cout<<"Cancelation constructor"<<endl;
            }

            DEFINE_SIMPLE_MEMBER(acount, string);
            DEFINE_SIMPLE_MEMBER(device, string);

            static void serialize(JsonObject &root, const void *cancelation);
            static void deserialize(const string &json, void *&cancelation);

        };
    }
}


#endif //SOFTWARE_ENGINEERING_CANCELATION_H
