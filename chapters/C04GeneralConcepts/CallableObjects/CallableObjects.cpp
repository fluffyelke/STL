/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <memory>
#include <future>
#include <iostream>

#include "CallableObjects.h"


namespace Callable {
    
    void func(int x, int y, const std::string& msg) {
        std::cout << "Using func() from: " << msg << "\n";
    }
    
    void MyClass::operator()(int x, int y, const std::string& msg) const {
        std::cout << "Using MyClass::operator() from: " << msg << "\n";
    }

    void MyClass::memberFunc(int x, int y, const std::string& msg) const {
        std::cout << "Using MyClass::memberFunc() from: " << msg << "\n";
    }

    void testCallable() {
        MyClass c;
        std::shared_ptr<MyClass> shardPtr(new MyClass);
        
        //bind() uses callable objects to bind arguments;
        std::bind(func, 77, 33, "std::bind") ();         //calls: func(77, 33);
        std::bind(myLambda, 77, 33, "std::bind") ();         //calls: myLambda(77, 33);
        std::bind(MyClass(), 77, 33, "std::bind") ();         //calls: MyClass::operator()(77, 33);
        std::bind(&MyClass::memberFunc, c, 77, 33, "std::bind") ();         //calls: c.memberFunc(77, 33);
        std::bind(&MyClass::memberFunc, shardPtr, 77, 33, "std::bind") ();         //calls: shardPtr->memberFunc(77, 33);
        
        //async() uses callable objects to start(background) tasks.
        std::async(func, 77, 33, "std::async");         //calls: func(77, 33);
        std::async(myLambda, 77, 33, "std::async");         //calls: myLambda(77, 33);
        std::async(c, 77, 33, "std::async");         //calls: c.operator()(77, 33);
        std::async(&MyClass::memberFunc, &c, 77, 33, "std::async");         //calls: c.memberFunc(77, 33);
        std::async(&MyClass::memberFunc, shardPtr, 77, 33, "std::async");         //calls: shardPtr->memberFunc(77, 33);
    }
}