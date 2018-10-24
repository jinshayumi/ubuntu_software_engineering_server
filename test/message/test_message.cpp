//
// Created by swchen on 18-10-24.
//

#include "message/Message.h"
#include "message/Load_msg.h"

using namespace SwChen::message;

int main()
{
    Load_msg loadMsg;
    loadMsg.set_acount("2849297846");
    loadMsg.set_password("123456");

    Message message(0, &loadMsg);
    string output = message.serialize();
    cout<<output<<endl;

    Message message_(0, nullptr);
    message_.deserialize(output.c_str());
    cout<<((Load_msg*)message_.get_body())->get_acount()<<endl;
    cout<<((Load_msg*)message_.get_body())->get_password()<<endl;

    return 0;
}