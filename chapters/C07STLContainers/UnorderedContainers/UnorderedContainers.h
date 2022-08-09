/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UnorderedContainers.h
 * Author: default
 *
 * Created on August 5, 2022, 3:22 PM
 */

#ifndef UNORDEREDCONTAINERS_H
#define UNORDEREDCONTAINERS_H

#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

namespace C07Containers {

//    
//    template<typename T, 
//             typename Hash = std::hash<T>,
//             typename EqPred = std::equal_to<T>,
//             typename Allocator = std::allocator<T> >
//    class unordered_set;
//    
//    template<typename T, 
//             typename Hash = std::hash<T>,
//             typename EqPred = std::equal_to<T>,
//             typename Allocator = std::allocator<T> >
//    class unordered_multiset;
//    
//    template<typename T, 
//             typename Hash = std::hash<T>,
//             typename EqPred = std::equal_to<T>,
//             typename Allocator = std::allocator<std::pair<const Key, T>> >
//    class unordered_map;
//    
//    template<typename T, 
//             typename Hash = std::hash<T>,
//             typename EqPred = std::equal_to<T>,
//             typename Allocator = std::allocator<std::pair<const Key, T>> >
//    class unordered_multimap;
    
    /**
     * Providing own Hash Function
     * The Hash function must return std::size_t type.
     * 
     * class Customer {
            //...
        };
        class CustomerHash {
        public:
            std::size_t operator () (const Customer& c) const {
                //...
            }
        };
     *  std::unordered_set<Customer, CustomerHash> mySet;
     */
    
    
    //Examples of using unordered containers
    //cont/unordset1.cpp
    extern void exampleOfUnorderedSet();
    
    //cont/unordmultiset1.cpp
    extern void exampleOfUnorderedMultiset();
    
    
    //Example of providing your own function and equivalence criterion
    
    
    //Print hashtable  cont/unordinspect1.cpp
    extern void testBucketInterface();
    
    //cont/unordmultimap1.cpp
    extern void unordMultiMapHash();
}

#endif /* UNORDEREDCONTAINERS_H */

