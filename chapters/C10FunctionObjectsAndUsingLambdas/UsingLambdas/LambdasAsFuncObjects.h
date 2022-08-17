/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LambdasAsFuncObjects.h
 * Author: default
 *
 * Created on August 10, 2022, 3:17 PM
 */

#ifndef LAMBDASASFUNCOBJECTS_H
#define LAMBDASASFUNCOBJECTS_H

namespace C10FuncObj {
    // fo/lambda1.cpp
    extern void compareToSTDBind();
    
    //Lambdas vs Stateful function objects
    // fo/lambda2.cpp
    extern void lambdaMean();
    
    //using mutable, provide writing access to value variable.
    // fo/lambda2.cpp
    extern void lambdaMutableUse();
    
    //Lambdas calling global member functions
    // fo/lambda4.cpp
    char myToupper(char c);
    extern void lambdaCallsGlobal();
    
    //Calling Member functions
    // fo/lambda5.cpp  //using Person class
    extern void testPersonLambda();
}

#endif /* LAMBDASASFUNCOBJECTS_H */

