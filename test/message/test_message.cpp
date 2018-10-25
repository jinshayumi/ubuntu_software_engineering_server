//
// Created by swchen on 18-10-24.
//

#include "src/message_model/message/Message_handler.h"
#include "src/message_model/message/Load.h"

using namespace SwChen::message;

void test_Load_msg() {
    Load loadMsg("2849297846", "123456", "192.168.10.32", "1234", "Desktop");
    Message_handler message(Message_Type::Load, &loadMsg);

    string output = message.serialize();
    cout << output << endl;

    Message_handler message_(0, nullptr);
    message_.deserialize(output.c_str());

    cout << "op: " << message.get_op() << endl;
    cout << "acount: " << ((Load *) message_.get_body())->get_acount() << endl;
}

void test_Cancelation_msg() {
    Cancelation cancelationMsg("2849297846", "Desktop");
    Message_handler message(Message_Type::Cancelation, &cancelationMsg);

    string output = message.serialize();
    cout << output << endl;

    Message_handler message_(0, nullptr);
    message_.deserialize(output.c_str());

    cout << "op: " << message.get_op() << endl;
    cout << "acount: " << ((Load *) message_.get_body())->get_acount() << endl;
}

int main() {

    test_Load_msg();
    test_Cancelation_msg();
    return 0;
}