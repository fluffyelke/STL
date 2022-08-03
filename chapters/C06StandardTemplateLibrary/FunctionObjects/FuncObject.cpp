/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>

#include "FuncObject.h"


namespace C06STL {

    void PrintInt::operator()(int number) {
        std::cout << number << ' ';
    }

    void testFuncObject() {
        std::vector<int> myCont;
        for(int i = 1; i <= 9; ++i) {
            myCont.push_back(i);
        }
        
        std::for_each(myCont.cbegin(), myCont.cend(),   //range
            PrintInt());                                //operation   
        std::cout << std::endl;
    }
}