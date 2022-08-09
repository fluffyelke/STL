/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashVal.h
 * Author: default
 *
 * Created on August 8, 2022, 10:22 AM
 */

#ifndef HASHVAL_H
#define HASHVAL_H

#include <cstdlib>
#include <vector>


namespace HashVal {
    //cont/hashval.hpp
    //from boost(functional/hash)
    template<typename T>
    inline void hashCombine(std::size_t& seed, const T& val) {
        seed ^= std::hash<T>() (val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    
    //auxiliary generic functions to create a hash value using a seed
    template<typename T>
    inline void hashVal(std::size_t& seed, const T& val) {
        hashCombine(seed, val);
    }
    
    template<typename T, typename... Types>
    inline void hashVal(std::size_t& seed, const T& val, const Types&... args) {
        hashCombine(seed, val);
        hashVal(seed, args...);
    }
    
    //auxiliary generic function to create a hash value out of a heterogeneous list of arguments
    template<typename... Types>
    inline std::size_t hashVal(const Types&... args) {
        std::size_t seed = 0;
        hashVal(seed, args...);
        return seed;
    }
}

#endif /* HASHVAL_H */

