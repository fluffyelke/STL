/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SetAndMultiset.h
 * Author: default
 *
 * Created on August 5, 2022, 9:22 AM
 */

#ifndef SETANDMULTISET_H
#define SETANDMULTISET_H

#include <condition_variable>
#include <set>
#include <iostream>


namespace C07Containers {
//    template<typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>>
//    class set;
//    
//    template<typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>>
//    class multiset;
    
    
    //cont/setrange1.cpp
    extern void exampleOfLowerUpperBound();
    
    /**Insert in set*/
//    void insertInSet() {
//        std::set<double> cont;
//        if(cont.insert(5.5).second) {
//            std::cout << "Value 5.5 inserted!\n";
//        }
//        else {
//            std::cout << "Value already exist"
//            
//        }
//    }
    
    extern void setMultisetExample();
    
    /**
     * Example of sorting criteria at runtime
     * cont/setcmp1.cpp
     */
    extern void testRuntimeCmp();
}

#endif /* SETANDMULTISET_H */

