/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ForEach.h
 * Author: default
 *
 * Created on August 11, 2022, 12:39 PM
 */

#ifndef FOREACH_H
#define FOREACH_H

namespace C11Algorithms {
    //std::for_each() implementation
//    template<typename Iterator, typename Operation>
//    Operation for_each(Iterator act, Iterator end, Operation op) {
//        
//        while(act != end) {     //as long as not reach the end 
//            op(*act);           //call op() for actual element
//            ++act;              //move iterator to the next element
//        }
//        return op;
//        
//    }
    
//    extern void printElement();
    
    // algo/foreach1.cpp
    extern void testForEach1();
    
    /**
     * since c++11 is better for each loop
     * for(auto elem : coll) {
     *     std::cout << elem << ' ';
     * } 
     */
    
    // algo/foreach2.cpp
    extern void testForEach2();
    
    //function object to proces mean value
    // algo/foreach3.cpp
    class MeanValue {
        long num;
        long sum;
    public:
        MeanValue();
        //function call
        //-process one more element of the sequence
        void operator() (int elem);
        operator double();
    };
    
    extern void testForEach3();
}

#endif /* FOREACH_H */

