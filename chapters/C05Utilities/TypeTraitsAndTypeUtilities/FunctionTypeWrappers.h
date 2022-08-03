/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunctionTypeWrappers.h
 * Author: default
 *
 * Created on July 29, 2022, 1:50 PM
 */

#ifndef FUNCTIONTYPEWRAPPERS_H
#define FUNCTIONTYPEWRAPPERS_H

namespace FuncWrappers {
    class MyClass {
    public:
        MyClass();
        ~MyClass();
        void myClassFunc(int x, int y) const;
    };
    
    extern void testMemberFunc();
}


#endif /* FUNCTIONTYPEWRAPPERS_H */

