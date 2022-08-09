/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BucketInterface.h
 * Author: default
 *
 * Created on August 8, 2022, 11:02 AM
 */

#ifndef BUCKETINTERFACE_H
#define BUCKETINTERFACE_H

#include <ostream>
#include <iostream>
#include <iomanip>
#include <typeinfo>

/**
 * Use this to print internal layout of unordered containers
 * @param os
 * @param p
 * @return 
 */
namespace C07Containers {
    //generic output for pairs (map elements)
    template<typename T1, typename T2>
    std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) {
        return os << "[" << p.first << "," << p.second << "]";
    }
    
    //print hash table state
    template<typename T>
    void printHashTableState(const T& cont) {
        //basic layout data
        std::cout << "size:            " << cont.size() << std::endl;
        std::cout << "buckets:         " << cont.bucket_count() << std::endl;
        std::cout << "load factor:     " << cont.load_factor() << std::endl;
        std::cout << "max load factor: " << cont.max_load_factor() << std::endl;
        
        //iterator category
        if(typeid(typename std::iterator_traits<typename T::iterator>::iterator_category) == typeid(std::bidirectional_iterator_tag)) {
            std::cout << "chaining style: doubly-linked" << std::endl;
        }
        else {
            std::cout << "chaining style: singly-linked" << std::endl;
        }
        
        //elements per bucket
        std::cout << "data: " << "\n";
        for(auto idx = 0; idx != cont.bucket_count(); ++idx) {
            std::cout << " b[" << std::setw(2) << idx << "]: ";
            for(auto pos = cont.begin(idx); pos != cont.end(idx); ++pos) {
                std::cout << *pos << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }
}

#endif /* BUCKETINTERFACE_H */

