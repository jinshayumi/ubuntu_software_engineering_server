//
// Created by swchen on 18-10-24.
//

#ifndef SOFTWARE_ENGINEERING_MESSAGE_TYPE_H
#define SOFTWARE_ENGINEERING_MESSAGE_TYPE_H

namespace SwChen{

    namespace message{

        class Message_Type{

        public:
            enum {
                DEFAULT = -1,
                Cancelation = 0,
                Load = 1,
                Req_Friends = 2,
                Message_Client = 3,
                Friend_Add_Delete = 4,
                Add_Confirm_Client = 5,
                Message_Confirm_Client = 6,
                Message_Confirm_Server = 7,
                Friend_List = 8,
                Add_Transport = 9,
                Delete_Confirm = 10,
                Add_Confirm_Server = 11
            };

        };



    }
}

#endif //SOFTWARE_ENGINEERING_MESSAGE_TYPE_H
