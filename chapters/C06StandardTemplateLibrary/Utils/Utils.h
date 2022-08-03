/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: default
 *
 * Created on August 2, 2022, 9:58 AM
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>

namespace Containers {
    template<typename T>
    void printElements(const T& cont, const std::string& msg = "") {
        std::cout << msg;
        for(const auto& elem : cont) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    
    
    template<typename T>
    void printMaps(const T& cont, const std::string& msg = "") {
        if(msg != "") {
            std::cout << msg << std::endl;
        }
        for(const auto& elem : cont) {
            std::cout << "[" << elem.first << "]: " << elem.second << std::endl; 
        }
    } 
}

#endif /* UTILS_H */

