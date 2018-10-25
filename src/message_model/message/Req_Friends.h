//
// Created by swchen on 10/25/18.
//

#ifndef SOFTWARE_ENGINEERING_REQ_FRIENDS_H
#define SOFTWARE_ENGINEERING_REQ_FRIENDS_H

#include<iostream>
#include <string>
#include <src/tools/json/json_serialize_deserialize.h>

#include "ArduinoJson/ArduinoJson.h"

#include "Define_Member.h"
#include "Const_Values.h"

using namespace std;
using namespace SwChen::tools;

#define ReqFriends_json_len 200

namespace SwChen {

    namespace message {

        class Req_Friends {

        public:

            explicit Req_Friends(string acount = _STRING, string device = _STRING) :
                    acount(std::move(acount)),
                    device(std::move(device)) {
                cout << "Req_Friend constructor" << endl;
            }

        DEFINE_SIMPLE_MEMBER(acount, string);
        DEFINE_SIMPLE_MEMBER(device, string);

            static void serialize(JsonObject &root, const void *req_friends) {
                root["acount"] = ((Req_Friends *) req_friends)->get_acount();
                root["device"] = ((Req_Friends *) req_friends)->get_device();
            }

            static void deserialize(const string &json, void *&req_friends) {
                if (!req_friends) {
                    req_friends = new Req_Friends();
                }
                StaticJsonBuffer<ReqFriends_json_len> jsonBuffer;
                JsonObject &root = jsonBuffer.parseObject(json);

                ((Req_Friends *) req_friends)->set_acount(root["acount"]);
                ((Req_Friends *) req_friends)->set_device(root["device"]);
            }

        };
    }
}

#endif //SOFTWARE_ENGINEERING_REQ_FRIENDS_H
