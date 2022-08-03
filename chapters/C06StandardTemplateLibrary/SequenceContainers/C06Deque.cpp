/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <deque>
#include <iostream>

#include "C06Deque.h"


namespace C06STL {
    void testDeque() {
        std::deque<float> myCont;
        
        for(int i = 1; i <= 6; i++){
            myCont.push_front(i * 1.1);     //insert at the front
        }
        
        for(int i = 0; i < myCont.size(); i++) {
            std::cout << myCont[i] << " ";
        }
        
        std::cout << std::endl;
    }
}