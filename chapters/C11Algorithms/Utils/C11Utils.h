/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C11Utils.h
 * Author: default
 *
 * Created on August 11, 2022, 12:25 PM
 */

#ifndef C11UTILS_H
#define C11UTILS_H
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>

namespace C11Utils {
    //Helper methods for C11 Algorithms
    // algo/algostuff.hpp
    
    //insertElements(collection, first, last);
    //-fill values from first to last into the collection
    //-NOTE no half-open range
    template<typename T>
    inline void insertElements(T& coll, int first, int last) {
        for(int i = first; i <= last; ++i) {
            coll.insert(coll.end(), i);
        }
    }
    
    //printElements()
    //-print optional string str followed by
    //-all elements of the collection coll
    //-separated by spaces
    template<typename T>
    inline void printElements(const T& coll, const std::string& str = "") {
        std::cout << str;
        for(auto elem : coll) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    
    //print mapped elements
    //-print optional string str followed by
    //-all elements of the key/value collection coll
    //-separated by spaces
    template<typename T>
    inline void printMappedElements(const T& coll, const std::string& str = "") {
        std::cout << str;
        for(auto elem : coll) {
            std::cout << "[" << elem.first << "," << elem.second << "] ";
        }
        std::cout << std::endl;
    }
}

#endif /* C11UTILS_H */

