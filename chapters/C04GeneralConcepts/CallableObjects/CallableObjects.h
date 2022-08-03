/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CallableObjects.h
 * Author: default
 *
 * Created on July 26, 2022, 10:15 AM
 */

#ifndef CALLABLEOBJECTS_H
#define CALLABLEOBJECTS_H

#include <iostream>

namespace Callable {
    
    extern void func(int x, int y, const std::string& msg);
    
    auto myLambda = [] (int x, int y, const std::string& msg) {
        std::cout << "Using myLambda() from: " << msg << "\n";
    };
    
    class MyClass {
    public:
        void operator() (int x, int y, const std::string& msg) const;
        void memberFunc(int x, int y, const std::string& msg) const; 
    };
    
    extern void testCallable();
}

#endif /* CALLABLEOBJECTS_H */

