/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputOutput.h
 * Author: default
 *
 * Created on August 26, 2022, 3:04 PM
 */

#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <istream>


namespace C15IOStreams {
    
    // io/io1.cpp
    extern void inputOutputExample1();
    
    // io/timemanipulator1.cpp
    extern void processAndPrintDateAndTime();
    
    
    extern double readAndProcessSum(std::istream& is);
    
    //io/summain.cpp
    extern double testProcessSum();
    
}

#endif /* INPUTOUTPUT_H */

