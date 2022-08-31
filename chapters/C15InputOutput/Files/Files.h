/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Files.h
 * Author: default
 *
 * Created on August 31, 2022, 3:04 PM
 */

#ifndef FILES_H
#define FILES_H

#include <fstream>


namespace C15Files {
    // io/fstream1.cpp
    extern void fstreamExample1();
    
    
    
    //file utils
    extern std::ofstream openToWriteFile(const std::string& fileName);
    extern std::ifstream openToReadFile(const std::string& fileName);
}

#endif /* FILES_H */

