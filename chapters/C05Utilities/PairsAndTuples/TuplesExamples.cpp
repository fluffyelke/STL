/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <tuple>
#include <complex>
#include <iostream>

#include "TuplesExamples.h"
#include "../../../utils/IOTuples.h"


namespace Tuples {
    
    void tupleExamples() {
        // create a four-element tuple
        // elements are created with default value 0 for fundamental types.
        std::tuple<std::string, int, int, std::complex<double>> t;
        
        //Create and initialize tuple explicitly
        std::tuple<int, float, std::string> t2(41, 6.3, "Vanya");
        
        
        //iterate over elements
        std::cout << std::get<0>(t2) << " ";
        std::cout << std::get<1>(t2) << " ";
        std::cout << std::get<2>(t2) << " ";
        std::cout << std::endl;
        
        //create a tuple with make_tuple, auto
        auto t3 = std::make_tuple(22, 44, "Elina");
        
        //assign second value in t2 to t1.
        std::get<1>(t) = std::get<1>(t3);
        
        //comparison and assignment 
        //including type conversion from tuple<int, int, float, char*>, to tuple<int,float, string>
        if(t2 < t3) {   //compares value by value
            t2 = t3; //ok assign t2 to t1.
        }
        
    }
    
    void printTuple() {
        std::tuple<int, float, std::string, std::string, char, int> t(5, 2.4, "Brrr", "Vanya", 'b', 44);
        std::cout << "IO tuple: " << t << std::endl; 
    }
    
}