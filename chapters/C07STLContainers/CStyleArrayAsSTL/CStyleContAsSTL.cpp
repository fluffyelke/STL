/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "CStyleContAsSTL.h"


namespace C07Containers {
    void cstyleArrAsSTL() {
        int arr[] = {33, 67, -4, 13, 5, 2};
        std::vector<int> myVec(std::begin(arr), std::end(arr));
        
        //use global begin() end() for containers
        std::copy(std::begin(myVec), std::end(myVec),
                  std::ostream_iterator<int>(std::cout, " "));
        
        std::cout << std::endl;
    }
}