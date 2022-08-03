/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: default
 *
 * Created on July 25, 2022, 2:27 PM
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>


namespace Utils {
    
    template<typename T>
    void printElements(const T& container) {
        for(const auto& elem : container) {
            std::cout << elem << " ";
        }
    }
    
    
    //Variadic Templates
    void variadicPrint() {
        std::cout << "Stop Printing.\n";
    }
    
    /**
     * Print any type of elements recursively.
     * To end recursion, non-template overload method should be use.
     * @param firstArg
     * @param args
     */
    template<typename T, typename... Types>
    void variadicPrint(const T& firstArg, const Types... args) {
        std::cout << firstArg << std::endl;
        variadicPrint(args...);
    }
    
    /**
     * Generic output operator for pairs (limited solution)
     */
    template<typename T1, typename T2>
    std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p) {
        return strm << "[" << p.first << ", " << p.second << "]";
    }

    template<typename T>
    inline void mySwap(T& a, T& b) {
        T temp{std::move(a)};
        a = std::move(b);
        b = std::move(temp);
    }
    
    template<typename T, std::size_t N>
    void mySwap(T (&a)[N], T (&b)[N]) noexcept(noexcept(mySwap(*a, *b)));
    
}

#endif /* UTILS_H */

