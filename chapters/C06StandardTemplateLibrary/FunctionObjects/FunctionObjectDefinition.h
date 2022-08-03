/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunctionObjectDefinition.h
 * Author: default
 *
 * Created on August 3, 2022, 10:54 AM
 */

#ifndef FUNCTIONOBJECTDEFINITION_H
#define FUNCTIONOBJECTDEFINITION_H

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

namespace C06STL {
    class MyClass {
    public:
        //define "function call" operator
        //!!!!!
        //return-type operator () (arguments) const;
        
        
        //examples
        bool operator() (int x, int y) const {
            return x < y;
        }
    };
    
    
//    //examples with problems which are resolved using function objects, problems get complicated when we need to pass 
//    //the function at the run time.
//    void add10(int& elem) {
//        elem += 10;
//    }
//    void example1() {
//        std::vector<int> myCont{1, 2, 3, 4, 5};
//        //usable only when we know the number which we will add at compile time
//        std::for_each(myCont.begin(), myCont.end(), //range
//                        add10);                     //operation
//    }
//    
//    template<int numValue>
//    void add(int& elem) {
//        elem += numValue;
//    }
//    void example2() {
//        std::vector<int> myCont{1, 2, 3, 4, 5};
//        //usable only when we know the number which we will add at compile time
//        std::for_each(myCont.begin(), myCont.end(), //range 
//                        add<10>);                   //operation
//    }
    
    ////////////////////////
    //Because of the previous examples the Function Objects are still usable, and will work at runtime.
    class AddValue {
    private:
        int intValue;       //the value to add
    public:
        //constructor initialize the value to add
        AddValue(int val) : intValue{val} {}
        
        //the "function call"
        void operator() (int& elem) const{
            elem += intValue;
        }
    };
    extern void exampleAddValueFuncCall();
}

#endif /* FUNCTIONOBJECTDEFINITION_H */

