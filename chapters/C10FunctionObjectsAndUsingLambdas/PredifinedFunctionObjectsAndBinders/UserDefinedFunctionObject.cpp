/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

#include "UserDefinedFunctionObjects.h"


namespace C10FuncObj {
    void testFoPow() {
        std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        /**
         * std::bind(fopow<float, int>(),...)  << the function object we pass to bind
         * std::bind(..., 3,...) << първия аргумент от структурата fopow,
         * std::bind(..., ..., std::placeholders::_1) << параметрите който подаваме като втори аргумент на структурата fopow, 
         *                                               идващи от контейнера intVec, всички елементи от begin() до end()
         */
        //print 3 raised to the power of all elements   
        std::transform(intVec.begin(), intVec.end(),                                //source
                       std::ostream_iterator<float>(std::cout, " "),                //destination
                       std::bind(fopow<float, int>(), 3, std::placeholders::_1));   //operation
        std::cout << std::endl;
        
        /**
         * std::bind(fopow<float, int>(),...)  << the function object we pass to bind
         * std::bind(..., std::placeholders::_1,...) << първия аргумент от структурата fopow,
         *                                              идващи от контейнера intVec, всички елементи от begin() до end()
         * std::bind(..., ..., 3) << втория аргумент на структурата fopow, повдигаме всяко число в intVec, на степен 3
         *                                              
         */
        //print all elements raised to the power of 3
        std::transform(intVec.begin(), intVec.end(),                                //source
                      std::ostream_iterator<float>(std::cout, " "),                 //destination
                      std::bind(fopow<float, int>(), std::placeholders::_1, 3));    //operation
    }
}