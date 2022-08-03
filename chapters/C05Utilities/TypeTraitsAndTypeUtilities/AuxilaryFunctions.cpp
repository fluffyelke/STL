/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <algorithm>
#include <iostream>
#include "AuxilaryFunctions.h"

namespace AuxilaryFunc {
    bool intPtrCompare(int* left, int* right){
        return *left < *right;
    }
    
    void testIntPtrComp() {
        int x = 17;
        int y = 42;
        int z = 33;
        int* px = &x;
        int* py = &y;
        int* pz = &z;
        //call std::max() with special comparison function
        int* pMax = std::max(px, py, intPtrCompare);
        std::cout << "Max: " << *pMax << std::endl;
        
        //call minmax() for initializer list with special comparison function
        std::pair<int*, int*> extremes = std::minmax({px, py, pz}, intPtrCompare);
        std::cout << "MinMax: Min: " << *extremes.first << ", Max: " << *extremes.second << std::endl; 
        
        std::cout << "Using Lambda Comparator\n";
        auto extremesLambda = std::minmax({px, py, pz}, [](int* x, int* y) {
           return *x < *y; 
        });
        std::cout << "Lambda MinMax: Min: " << *extremesLambda.first << ", Max: " << *extremesLambda.second << std::endl; 
    }
}