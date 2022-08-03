/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <functional>

#include "TypeTraits.h"

namespace Traits {
    void myFunc(int x, int y) {
        std::cout << x << " * " << y << " = " << x * y << std::endl;
    }
    void testFunctionWrappers() {
        std::vector<std::function<void(int,int)>> tasks;
        tasks.push_back(myFunc);
        tasks.push_back([](int x, int y) {
           std::cout << x << " + " << y << " = " << x + y << std::endl; 
        });
        tasks.push_back([](int x, int y) {
           std::cout << x << " - " << y << " = " << x - y << std::endl; 
        });
        tasks.push_back([](int x, int y) {
           std::cout << x << " / " << y << " = " << x / y << std::endl; 
        });
        
        for(auto f : tasks) {
            f(10, 20);
        }
    }
}