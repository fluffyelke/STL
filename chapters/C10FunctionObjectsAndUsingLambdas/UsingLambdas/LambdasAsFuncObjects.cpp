/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../PredifinedFunctionObjectsAndBinders/PredifinedFunctionObjectsList.h"
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
#include "LambdasAsFuncObjects.h"


namespace C10FuncObj {
    void compareToSTDBind() {
        auto plus10 = [](int i) {
          return i + 10;  
        };
        std::cout << "+10:    " << plus10(7) << std::endl;
        
        auto plus10times2 = [](int i) {
          return (i + 10) * 2;  
        };
        std::cout << "+10 *2: " << plus10times2(7) << std::endl;
        
        auto pow3 = [](int i) {
          return i * i * i;  
        };
        std::cout << "x*x*x:  " << pow3(7) << std::endl;
        
        auto inverseDivide = [](double d1, double d2) {
          return d2 / d1;  
        };
        std::cout << "invdiv: " << inverseDivide(49,7) << std::endl;
    }
    
    void lambdaMean() {
        std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8};
        int sum = 0;
        std::for_each(intVec.begin(), intVec.end(),
                      [&sum](int elem) {
                         sum += elem; 
                      });
        double meanValue = static_cast<double>(sum) / static_cast<double>(intVec.size());
        std::cout << "mean value: " << meanValue << std::endl;
    }
    
    void lambdaMutableUse() {
        std::list<int> intList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Containers::printElements(intList, "intList:     ");
        
        //remove third element 
        std::list<int>::iterator pos;
        int count = 0;
        pos = std::remove_if(intList.begin(), intList.end(),    //range
                             [count](int) mutable {             //remove criterion
                                 return ++count == 3;
                             });
        intList.erase(pos, intList.end());
        Containers::printElements(intList, "3rd removed: ");
    }
    
    char myToupper(char c) {
        std::locale loc;
        return std::use_facet<std::ctype<char>>(loc).toupper(c);
    }
    void lambdaCallsGlobal() {
        std::string s("Internationalization");
        std::string sub("Nation");
        
        //search substring case insensitive
        std::string::iterator pos;
        pos = std::search(s.begin(), s.end(),                       //string to search in
                         sub.begin(), sub.end(),                    //substring to search
                         [](char c1, char c2) {                     //comparison criterion
                            return myToupper(c1) == myToupper(c2);  
                         });
                         
        if(pos!= s.end()) {
            std::cout << "\"" << sub << "\" is part of \"" << s << "\"" << std::endl;
        }
    }

    void testPersonLambda() {
        std::vector<Person> personVec = {
            Person("Tick"),
            Person("Trick"),
            Person("Track"),
        };
        
        //call member function print() for each person
        std::for_each(personVec.begin(), personVec.end(),
                      [](const Person& p) {
                         p.print(); 
                      });
        std::cout << std::endl;
        
        //call member function print2() with additional argument for each person
        std::for_each(personVec.begin(), personVec.end(),
                      [](const Person& p) {
                         p.print2("Person: "); 
                      });
        std::cout << std::endl;
    }
}