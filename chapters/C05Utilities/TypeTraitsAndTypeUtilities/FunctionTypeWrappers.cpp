/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <functional>
#include <iostream>

#include "FunctionTypeWrappers.h"

namespace FuncWrappers {
        MyClass::MyClass() {
            std::cout << "MyClass() created!\n";
        }

        MyClass::~MyClass() {
            std::cout << "MyClass() destroyed!\n";
        }

    void MyClass::myClassFunc(int x, int y) const {
        std::cout << "Called void MyClass::myClassFunc(int, int): ";
        std::cout << x << " " << y << std::endl;
    }
    void testMemberFunc() {
        std::function<void(const MyClass&, int, int)> memFunc;
        memFunc = &MyClass::myClassFunc;
        memFunc(MyClass(), 33, 66);
    }
}