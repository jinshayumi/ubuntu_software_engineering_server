//
// Created by swchen on 18-10-24.
//

#ifndef SOFTWARE_ENGINEERING_BODY_MSG_H
#define SOFTWARE_ENGINEERING_BODY_MSG_H

#include <iostream>
#include <string>
#include <list>

#include "Load_msg.h"

#include "Message_Type.h"
#include "Define_Member.h"

using namespace std;

const u_int32_t body_json_len = 10000;

namespace SwChen{

    namespace message{

        class Message{
        public:
            DEFINE_SIMPLE_MEMBER(op, unsigned short);
            DEFINE_POINTER_MEMBER(body, void *);

            explicit Message(unsigned short op = Message_Type::DEFAULT, void *body = nullptr){
                this -> op = op;
                this -> body = body;
            }

            const string serialize();

            void deserialize(const char *json);
        };
    }
}

#endif //SOFTWARE_ENGINEERING_BODY_MSG_H
