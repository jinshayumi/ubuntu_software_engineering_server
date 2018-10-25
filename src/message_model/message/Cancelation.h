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

namespace SwChen {

    namespace message {

        class Cancelation {

        public:

            explicit Cancelation(string acount = _STRING, string device = _STRING) :
                    acount(std::move(acount)),
                    device(std::move(device)) {
                cout << "Cancelation constructor" << endl;
            }

        DEFINE_SIMPLE_MEMBER(acount, string);
        DEFINE_SIMPLE_MEMBER(device, string);


            static void serialize(JsonObject &root, const void *cancelation) {
                root["acount"] = ((Cancelation *) cancelation)->get_acount();
                root["device"] = ((Cancelation *) cancelation)->get_device();
            }

            static void deserialize(const string &json, void *&cancelation) {
                if (!cancelation) {
                    cancelation = new Cancelation();
                }

                StaticJsonBuffer<Cancelation_json_len> jsonBuffer;
                JsonObject &root = jsonBuffer.parseObject(json);

                ((Cancelation *) cancelation)->set_acount(root["acount"]);
                ((Cancelation *) cancelation)->set_device(root["device"]);

            }

        };
    }
}


#endif //SOFTWARE_ENGINEERING_CANCELATION_H
