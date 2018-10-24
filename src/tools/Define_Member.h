//
// Created by swchen on 18-10-24.
//

#ifndef SOFTWARE_ENGINEERING_DEFINE_MEMBER_H
#define SOFTWARE_ENGINEERING_DEFINE_MEMBER_H

#define DEFINE_SIMPLE_MEMBER(ARG_NAME, ARG_TYPE)             \
private:                                                                            \
    ARG_TYPE ARG_NAME;                                                              \
public:                                                                             \
    void set_##ARG_NAME(const ARG_TYPE &(ARG_NAME)){this -> ARG_NAME = ARG_NAME;}     \
    const ARG_TYPE &get_##ARG_NAME()const{return ARG_NAME;}                         \
    ARG_TYPE &get_##ARG_NAME(){return this -> ARG_NAME;}

#define _DEFINE_POINTER_MEMBER(ARG_NAME, ARG_TYPE)               \
private:                                                      \
    ARG_TYPE ARG_NAME;                                      \
public:                                                 \
    ARG_TYPE const get_##ARG_NAME()const{return ARG_NAME;}         \
    ARG_TYPE get_##ARG_NAME(){return this->ARG_NAME;}              \
    void set_##ARG_NAME(ARG_TYPE ARG_NAME){this->ARG_NAME=ARG_NAME;}

#define DEFINE_POINTER_MEMBER(ARG_NAME, ARG_TYPE) _DEFINE_POINTER_MEMBER(ARG_NAME,ARG_TYPE)

#endif //SOFTWARE_ENGINEERING_DEFINE_MEMBER_H
