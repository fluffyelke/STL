/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <array>
#include <iostream>

#include "C06Arrays.h"


namespace C06STL {
    void testArrays() {
        std::array<std::string, 5> myCont = {"Hello", "World"};
        
        for(int i = 0; i < myCont.size(); i++) {
            std::cout << i << ": " << myCont[i] << std::endl;
        }
        
    }
}