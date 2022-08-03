/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <list>
#include <algorithm>
#include <iostream>

#include "UnaryPredicate.h"


namespace C06STL {
    bool isPrime(int number) {
        //ignore negative sigh
        number = std::abs(number);
        
        //0 and 1 are not prime numbers
        if(number == 0 || number == 1) {
            return false;
        }
        
        //find divisor that divides without a remainder
        int divisor;
        for(divisor = number / 2; number % divisor != 0; --divisor) {
            ;
        }
        
        //if no divisor greater than 1 is found, it is a prime number
        return divisor == 1;
    }
    
    void testUnaryPredicate() {
        std::list<int> myCont;
        //insert elements from 24 to 30
        for(int i = 24; i <= 30; ++i) {
            myCont.push_back(i);
        }
        
        auto pos = std::find_if(myCont.cbegin(), myCont.cend(),  //range
            isPrime);           //predicate
        
        if(pos != myCont.end()) {
            //found
            std::cout << *pos << " is first prime number found" << std::endl;
        }
        else {
            //not found 
            std::cout << "no prime number found" << std::endl;
        }
    }
}