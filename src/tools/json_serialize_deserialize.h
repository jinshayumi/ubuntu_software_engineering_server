//
// Created by swchen on 18-10-23.
//

#ifndef SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H
#define SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H

#include <iostream>
#include <map>
#include <list>

using namespace std;

namespace SwChen{

    namespace tools{

        template <typename T>
        char *serialize(const list<T> _list);

    }
}

#endif //SOFTWARE_ENGINEERING_JSON_SERIALIZE_DESERIALIZE_H
