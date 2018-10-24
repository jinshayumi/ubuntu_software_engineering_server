//
// Created by swchen on 18-10-24.
//

#include "Load_msg.h"

using namespace SwChen::message;

void Load_msg::serialize(JsonObject &root, void *load_msg) {
    root["acount"] = ((Load_msg*)load_msg)->get_acount();
    root["password"] = MD5(((Load_msg*)load_msg)->get_password()).toStr();
}

void Load_msg::deserialize(JsonObject &root, void *&load_msg) {
    if(!load_msg){
        load_msg = new Load_msg();
    }
    ((Load_msg*)load_msg)->set_acount(root["acount"]);
    ((Load_msg*)load_msg)->set_password(root["password"]);
}