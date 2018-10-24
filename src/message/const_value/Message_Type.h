//
// Created by swchen on 18-10-24.
//

#ifndef SOFTWARE_ENGINEERING_MESSAGE_TYPE_H
#define SOFTWARE_ENGINEERING_MESSAGE_TYPE_H

namespace SwChen{

    namespace message{

        struct Message_Type{
            static const unsigned short DEFAULT = 0;
            static const unsigned short Cancellation = 0;
            static const unsigned short Load = 1;
        };
    }
}

#endif //SOFTWARE_ENGINEERING_MESSAGE_TYPE_H
