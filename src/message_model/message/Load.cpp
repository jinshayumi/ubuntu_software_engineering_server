//
// Created by swchen on 18-10-24.
//

#include "Load.h"

using namespace SwChen::message;

void Load::serialize(JsonObject &root, const void *load) {
    root["acount"] = ((Load*)load)->get_acount();
    root["password"] = MD5(((Load*)load)->get_password()).toStr();
    root["ip"] = ((Load*)load)->get_ip();
    root["port"] = ((Load*)load)->get_port();
    root["device"] = ((Load*)load)->get_device();
}

void Load::deserialize(const string &json, void *&load) {
    if(!load){
        load = new Load();
    }

    StaticJsonBuffer<Load_json_len> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    ((Load*)load)->set_acount(root["acount"]);
    ((Load*)load)->set_password(root["password"]);
    ((Load*)load)->set_ip(root["ip"]);
    ((Load*)load)->set_port(root["port"]);
    ((Load*)load)->set_device(root["device"]);

}