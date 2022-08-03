/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <iostream>

#include "C06Vector.h"


namespace C06STL {
    void testVector() {
        std::vector<int> myCont;
        
        for(int i = 1; i <= 6; i++){
            myCont.push_back(i);
        }
        
        
        for(int i = 0; i < myCont.size(); i++) {
            std::cout << myCont[i] << " ";
        }
        std::cout << std::endl;
    }
}