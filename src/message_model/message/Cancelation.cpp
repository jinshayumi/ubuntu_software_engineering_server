//
// Created by swchen on 18-10-25.
//

#include "Cancelation.h"

using namespace SwChen::message;

void Cancelation::serialize(JsonObject &root, const void *cancelation) {
    root["acount"] = ((Cancelation*)cancelation)->get_acount();
    root["device"] = ((Cancelation*)cancelation)->get_device();
}

void Cancelation::deserialize(const string &json, void *&cancelation) {
    if(!cancelation){
        cancelation = new Cancelation();
    }

    StaticJsonBuffer<Cancelation_json_len> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    ((Cancelation*)cancelation)->set_acount(root["acount"]);
    ((Cancelation*)cancelation)->set_device(root["device"]);

}