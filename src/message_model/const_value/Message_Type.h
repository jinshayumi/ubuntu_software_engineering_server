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
                Load = 1
            };

        };



    }
}

#endif //SOFTWARE_ENGINEERING_MESSAGE_TYPE_H
