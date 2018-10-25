//
// Created by swchen on 18-10-24.
//

#include "Message.h"

using namespace SwChen::message;

const string Message::serialize() {
    StaticJsonBuffer<body_json_len> jsonBuffer;
    JsonObject &root = jsonBuffer.createObject();

    root["op"] = this -> op;
    JsonObject &body = root.createNestedObject("body");
    typedef void (*Funcs)(JsonObject &, const void *);
    Funcs funcs[] = {
            Load::serialize,
            Cancelation::serialize
    };

    funcs[this->op](body, this -> body);

    string output;
    root.printTo(output);

    return output;
}

void Message::deserialize(const char *json) {
    StaticJsonBuffer<body_json_len> jsonBuffer;
    JsonObject &object = jsonBuffer.parseObject(json);

    typedef void (*Funcs)(const string &, void *&);
    Funcs funcs[] = {
            Load::deserialize,
            Cancelation::deserialize
    };

    string body = object["body"];

    int op = object["op"];
    funcs[op](body, this -> body);
}