/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <deque>
#include <algorithm>
#include <iostream>

#include "UsingLambda.h"


namespace C06STL {
    void firstNumBetweenXandY() {
        std::deque<int> myCont{1, 3, 19, 5, 7, 13, 11, 2, 17};
        
        int x = 5;
        int y = 12;
        auto pos = std::find_if(myCont.cbegin(), myCont.cend(),     //range
                                [=](int numInMyCont) -> bool {                  //search criterion
                                    return numInMyCont > x && numInMyCont < y;
                                });
            
        std::cout << "first elem > 5 && < 12: " << *pos << std::endl;
    }
}