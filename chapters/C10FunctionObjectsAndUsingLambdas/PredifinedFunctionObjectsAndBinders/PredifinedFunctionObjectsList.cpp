/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

#include "PredifinedFunctionObjectsList.h"


namespace C10FuncObj {
    void bindExample() {
        auto plus10 = std::bind(std::plus<int>(), 
                               std::placeholders::_1,
                               10);         
        std::cout << "+10:    " << plus10(7) << std::endl;
        
        auto plus10times2 = std::bind(std::multiplies<int>(),
                                      std::bind(std::plus<int>(),
                                                std::placeholders::_1,
                                                10),
                                     2);
        std::cout << "+10 *2: " << plus10times2(7) << std::endl;
        
        auto pow3 = std::bind(std::multiplies<int>(),
                              std::bind(std::multiplies<int>(),
                                        std::placeholders::_1,
                                        std::placeholders::_1),
                              std::placeholders::_1);
        std::cout << "x*x*x:  " << pow3(7) << std::endl;
        
        auto inverseDivide = std::bind(std::divides<double>(),
                                      std::placeholders::_2,
                                      std::placeholders::_1);
        std::cout << "invdiv: " << inverseDivide(49, 7) << std::endl;
    }
    
    char toUpper(char c) {
        std::locale loc;
        return std::use_facet<std::ctype<char> >(loc).toupper(c);
    }
    
    void testBindGlobalFunc() {
        std::string s("Internationalization");
        std::string sub("Nation");
        
        //search substring case insensitive
        std::string::iterator pos;
        pos = std::search(s.begin(), s.end(),                                           //string to search in
                          sub.begin(), sub.end(),                                       //substring to search
                          std::bind(std::equal_to<char>(),                              //searching criterion
                                        std::bind(toUpper, std::placeholders::_1),
                                        std::bind(toUpper, std::placeholders::_2)));
        
        if(pos != s.end()) {
            std::cout << "\"" << sub << "\" is part of \"" << s << "\"" << std::endl;
        }
        
    }

    
    Person::Person(const std::string& s) 
        : name{s} {
        
    }

    void Person::print() const {
        std::cout << name << std::endl;
    }

    void Person::print2(const std::string& prefix) const {
        std::cout << prefix << name << std::endl;
    }
    void testCallingMemberFuncs() {
        std::vector<Person> stringVec = {
            Person("Tick"),
            Person("Trick"),
            Person("Track")
        };  
        
        //call member function print() for each person
        std::for_each(stringVec.begin(), stringVec.end(),
                      std::bind(&Person::print, std::placeholders::_1));
        std::cout << std::endl;
        
        //call member function print2() with additional argument for each person
        std::for_each(stringVec.begin(), stringVec.end(),
                      std::bind(&Person::print2, std::placeholders::_1, "Person: "));
        std::cout << std::endl;
        
        //call print2() for temporary person
        std::bind(&Person::print2, std::placeholders::_1, "This is: ")(Person("Nico"));
    }

}