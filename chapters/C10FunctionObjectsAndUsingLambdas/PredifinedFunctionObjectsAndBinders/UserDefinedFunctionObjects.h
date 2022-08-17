/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserDefinedFunctionObjects.h
 * Author: default
 *
 * Created on August 10, 2022, 2:51 PM
 */

#ifndef USERDEFINEDFUNCTIONOBJECTS_H
#define USERDEFINEDFUNCTIONOBJECTS_H

#include <complex>


namespace C10FuncObj {
    // fo/fopow.hpp
    //process first argument raised by the power of the second argument 
    template<typename T1, typename T2>
    struct fopow {
        T1 operator() (T1 base, T2 exp) const {
            return std::pow(base, exp);
        }
    };
    
    //following program shows how to use the user-defined function object fopow<>()
    extern void testFoPow();
}

#endif /* USERDEFINEDFUNCTIONOBJECTS_H */

