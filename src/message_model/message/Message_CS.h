//
// Created by swchen on 10/25/18.
//

#ifndef SOFTWARE_ENGINEERING_MESSAGE_CS_H
#define SOFTWARE_ENGINEERING_MESSAGE_CS_H


#include <iostream>
#include <string>
#include <utility>
#include "ArduinoJson/ArduinoJson.h"
#include "MD5_coding/md5.h"

#include "Define_Member.h"
#include "Const_Values.h"

using namespace std;
using namespace SwChen::tools;

#define MessageCS_json_len 1000

namespace SwChen {

    namespace message {

        class Message_CS {

        public:

            explicit Message_CS(string fr = _STRING, string to = _STRING,
                          string time = _STRING, string msg = _STRING) :
                    fr(std::move(fr)),
                    to(std::move(to)),
                    time(std::move(time)),
                    msg(std::move(msg)){
                cout << "Message_CS constructor" << endl;
            }

        DEFINE_SIMPLE_MEMBER(fr, string);
        DEFINE_SIMPLE_MEMBER(to, string);
        DEFINE_SIMPLE_MEMBER(time, string);
        DEFINE_SIMPLE_MEMBER(msg, string);


            static void serialize(JsonObject &root, const void *message_cs) {
                root["fr"] = ((Message_CS *) message_cs)->get_fr();
                root["to"] = ((Message_CS *) message_cs)->get_to();
                root["time"] = ((Message_CS *) message_cs)->get_time();
                root["msg"] = ((Message_CS *) message_cs)->get_msg();
            }

            static void deserialize(const string &json, void *&message_cs) {
                if (!message_cs) {
                    message_cs = new Message_CS();
                }

                StaticJsonBuffer<MessageCS_json_len> jsonBuffer;
                JsonObject &root = jsonBuffer.parseObject(json);

                ((Message_CS *) message_cs)->set_fr(root["fr"]);
                ((Message_CS *) message_cs)->set_to(root["to"]);
                ((Message_CS *) message_cs)->set_time(root["time"]);
                ((Message_CS *) message_cs)->set_msg(root["msg"]);

            }
        };
    }
}

#endif //SOFTWARE_ENGINEERING_MESSAGE_CS_H
