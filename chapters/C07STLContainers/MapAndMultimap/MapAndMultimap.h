/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapAndMultimap.h
 * Author: default
 *
 * Created on August 5, 2022, 11:22 AM
 */

#ifndef MAPANDMULTIMAP_H
#define MAPANDMULTIMAP_H

#include <condition_variable>
#include <algorithm>
#include <map>
#include "../../../utils/RuntimeStringCmp.h"

namespace C07Containers {
    /**
     * Rules for map 
     * 1. both key and value must be copyable and movable
     * 2. the key must be comparable with sorting criterion
     * 
     * 
     * for using lambda as criteria we should explicitly declare the element type
     */
//    template<typename Key, typename T, 
//             typename Compare = std::less<T>,
//             typename Allocator = std::allocator<std::pair<const Key, T> > >;
//    class map;
//    
//    template<typename Key, typename T, 
//             typename Compare = std::less<T>,
//             typename Allocator = std::allocator<std::pair<const Key, T> > >;
//    class multimap;
    
//    void example() {
//        std::map<std::string, float> myMap;
//        //...
//        std::for_each(myMap.begin(), myMap.end(),
//                     [](std::pair<const std::string, float>& elem) {
//                        elem.second += 10; 
//                     });
//        //or
//        std::for_each(myMap.begin(), myMap.end(),
//                     [](std::map<const std::string, float>& elem) {
//                        elem.second += 10; 
//                     }); 
//        //or decltype(myMap)::value_type  ?!?!?
////        std::for_each(myMap.begin(), myMap.end(),
////                     [](decltype(myMap)::value_type elem)) {
////                        elem.second += 10; 
////                     });
//    }
    
    /**
     * Deleting a element by value correct way before C++11
     * 
     */
//    void exampleDelete() {
//        using StringFloatMap = std::map<std::string, float>;
//        StringFloatMap myMap;
//        StringFloatMap::iterator pos;
//        //...
//        int value;
//        //remove all elements having a certain value
//        for(pos = myMap.begin(), pos != myMap.end(); ) {
//            if(pos->second == value) {
//                myMap.erase(pos);
//            }
//            else {
//                ++pos;
//            }
//        }
//    }
    //Using Algorithms and Lambdas on Map and Multimap
    //cont/map1.cpp
    extern void mapMultimapExample();
    
    //Using map as associative array
    //cont/map2.cpp
    extern void mapMultimapExample2();
    
    
    //Using multimap as dictionary
    //cont/multimap1.cpp
    extern void multimapDictionary();
    
    //Finding elements with certain values
    //cont/mapfind1.cpp
    extern void findElemInMap();
    
    //Example with Maps, Strings and sorting criterion at runtime.
    //!advance programing
    /**
     * container type:
     * -map with 
     *      -string keys
     *      -string values
     *      -the special comparison object 
     */
    using StringStringMap = std::map<std::string, std::string, Utils::RuntimeStringCmp>;
    
    //function that fill and print string,string container
    extern void fillAndPrint(StringStringMap& myMap);
    extern void mapWithSortCriterionAtRunTimeExample();
}

#endif /* MAPANDMULTIMAP_H */

