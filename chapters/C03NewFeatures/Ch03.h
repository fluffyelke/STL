/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ch03.h
 * Author: default
 *
 * Created on July 25, 2022, 2:21 PM
 */

#ifndef CH03_H
#define CH03_H

#include <initializer_list>
#include <iostream>
#include <functional>



namespace Ch03 {
    extern void print(std::initializer_list<int> values);
    
    extern void rawStringLiterals();
    
    extern void simpleLambdas();
    
    
    extern std::function<int(int, int)> returnLambda(); 
}

#endif /* CH03_H */

