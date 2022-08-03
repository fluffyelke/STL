/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncObject.h
 * Author: default
 *
 * Created on August 3, 2022, 11:05 AM
 */

#ifndef FUNCOBJECT_H
#define FUNCOBJECT_H

#include <iostream>


namespace C06STL {
    //Simple function object that print the passed argument
    class PrintInt {
    public:
        void operator() (int number);
    };
    
    extern void testFuncObject();
}

#endif /* FUNCOBJECT_H */

