/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>

#include "../Utils/C11Utils.h"
#include "ForEach.h"

namespace C11Algorithms {
    
    void print(int elem) {
        std::cout << elem << " ";
    }
    
    void testForEach1() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        
        //call print() for each element
        std::for_each(intVec.cbegin(), intVec.cend(),       //range
                      [](int elem) {                    //operation
                         std::cout << elem << ' '; 
                      });
        std::cout << std::endl;
        
        //instead of lambda we can pass ordinary function
        //call print() for each element
        std::for_each(intVec.cbegin(), intVec.cend(),       //range
                      print);
        std::cout << std::endl;
    }
    
    void testForEach2() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        
        // add 10 to each element
        std::for_each(intVec.begin(), intVec.end(),
                     [](int& elem) {
                        elem += 10; 
                     });
        C11Utils::printElements(intVec);
        
        //add value of first elem to each element
        std::for_each(intVec.begin(), intVec.end(),
                     [=](int& elem) {
                         elem += *intVec.begin();
                     });
        C11Utils::printElements(intVec);
    }
    
    
    MeanValue::MeanValue() 
        : num(0),
          sum(0) {

    }

    void MeanValue::operator() (int elem) {
        num++;
        sum += elem;
    }
    MeanValue::operator double() {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
        
        
    void testForEach3() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 8);
        
        //process and print mean value
        double mv = std::for_each(intVec.cbegin(), intVec.cend(),       //range
                     MeanValue());                          //operation
        std::cout << "mean value: " << mv << std::endl;
    }
}