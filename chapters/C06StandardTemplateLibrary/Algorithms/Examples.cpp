/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>
#include <ios>
#include <list>
#include <deque>

#include "../Utils/Utils.h"
#include "Examples.h"


namespace C06STL {
    void minMaxExamples() {
        std::vector<int> myCont{2, 5, 4, 1, 6, 3};
        Containers::printElements(myCont, "Initial: ");
        auto minPos = std::min_element(myCont.cbegin(), myCont.cend());
        std::cout << "Min Element: " << *minPos << std::endl;
        
        auto maxPos = std::max_element(myCont.cbegin(), myCont.cend());
        std::cout << "Max Element: " << *maxPos << std::endl;
        
        std::sort(myCont.begin(), myCont.end());
        
        auto pos3 = std::find(myCont.begin(), myCont.end(), 3);
        
        //reverse the order of the found element with value 3 and all following elements
        std::reverse(pos3, myCont.end());
        Containers::printElements(myCont, "End: ");
    }
    
    void stlFind1() {
        std::list<int> myCont;
        for(int i = 20; i <= 40; i++){
            myCont.push_back(i);
        }
        
        //there is no element 3 in myCont so pos3 points to myCont.end()
        auto pos3 = std::find(myCont.begin(), myCont.end(), 3);
        
        //pos3 points to end so this reverse empty range
        std::reverse(pos3, myCont.end());
        
        std::list<int>::iterator pos25, pos35;
        pos25 = std::find(myCont.begin(), myCont.end(), 25);
        pos35 = std::find(myCont.begin(), myCont.end(), 35);
        
        //include pos25 but exclude pos35
        std::cout << "min element: " << *std::min_element(pos25, pos35) << std::endl;
        
        //process the elements but include the last position
        std::cout << "max element: " << *std::max_element(pos25, ++pos35) << std::endl;
    }
    
    void testCopy1() {
        std::list<int> listCont = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Containers::printElements(listCont, "List: ");
        std::vector<int> vecCont;
        vecCont.resize(listCont.size());
        
        //copy elements from first to second container
        std::copy(listCont.begin(), listCont.end(), vecCont.begin());
        
        Containers::printElements(vecCont, "Vector: ");
        
        std::deque<int> dequeCont(listCont.size());
        std::copy(listCont.begin(), listCont.end(), dequeCont.begin());
        
        Containers::printElements(dequeCont, "Deque: ");
    }
}