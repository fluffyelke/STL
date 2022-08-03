/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PairsExamples.h
 * Author: default
 *
 * Created on July 26, 2022, 11:10 AM
 */

#ifndef PAIRSEXAMPLES_H
#define PAIRSEXAMPLES_H

#include <tuple>
#include <iostream>


namespace Pairs {
    
    extern void testPairFunctionality();
    
    class Foo {
    public:
        Foo(std::tuple<int, float>);
        
        template<typename... Args>
        Foo(Args... args) {
            std::cout << "Foo...Foo(args...)" << std::endl;
        }
    };
    
    /** util/pair1.cpp */
    extern void testPairOne();
    
    
    extern void pairRefSemantic();
    
    extern void extractElementFromPair();
}

#endif /* PAIRSEXAMPLES_H */

