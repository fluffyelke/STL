/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PredifinedFunctionObjectsList.h
 * Author: default
 *
 * Created on August 10, 2022, 11:44 AM
 */

#ifndef PREDIFINEDFUNCTIONOBJECTSLIST_H
#define PREDIFINEDFUNCTIONOBJECTSLIST_H

/**
 * #include <functional>
 * 
 * Expression                   Effect 
 * negate<type>()               -param
 * plus<type>()                  param1 + param2
 * minus<type>()                 param1 - param2
 * multiplies<type>()            param1 * param2
 * divides<type>()               param1 / param2
 * modulus<type>()               param1 % param2
 * equal_to<type>()              param1 == param2
 * not_equal_to<type>()          param1 != param2
 * less<type>()                  param1 < param2
 * greater<type>()               param1 > param2
 * less_equal<type>()            param1 <= param2
 * greater_equal<type>()         param1 >= param2
 * logical_not<type>()           !param1
 * logical_and<type>()           param1 && param2
 * logical_or<type>()            param1 || param2
 * bit_and<type>()               param1 & param2
 * bit_or<type>()                param1 | param2
 * bit_xor<type>()               param1 ^ param2
 */

/**
 * Function adapters and binders
 * 
 * Expression                    Effect
 * bind(op, args...)             Binds args to op
 * mem_fn(op)                    Calls op() as a member function for an object or pointer to object
 * not1(op)                      Unary negation: !op(param)
 * not2(op)                      Binary negation: !op(param1, param2)
 */

namespace C10FuncObj {
    
    // fo/bind1.cpp
    extern void bindExample();
    
    
    //calling global functions
    // fo/compose3.cpp
    char toUpper(char c);
    extern void testBindGlobalFunc();
    
    
    //calling member functions
    // fo/bind2.cpp
    class Person {
        std::string name;
    public:
        Person(const std::string& s);
        void print() const;
        void print2(const std::string& prefix) const;
    };
    extern void testCallingMemberFuncs();
}

#endif /* PREDIFINEDFUNCTIONOBJECTSLIST_H */

