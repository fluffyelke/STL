/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>
#include <algorithm>
#include <iterator>
#include <set>

#include "../../Utils/Utils.h"
#include "C06Removing.h"


namespace C06STL {
    void testRemove() {
        std::list<int> myCont;
        
        //insert elements from 6 to 1 and from 1 to 6
        for(int i = 1; i <= 6; i++) {
            myCont.push_front(i);
            myCont.push_back(i);
        }
        
        //print all elements in the collection
        Containers::printElements(myCont, "list pre: ");
        
//        std::copy(myCont.begin(), myCont.end(),
//            std::ostream_iterator<int>(std::cout, " "));
//        std::cout << std::endl;
        
        std::remove(myCont.begin(), myCont.end(),   //range to check
                                            3);     //value to remove
        
        Containers::printElements(myCont, "list post: ");
    }
    
       
    
    void testRemoveCorrect() {
        std::list<int> myCont;
        
        //insert elements from 6 to 1 and from 1 to 6
        for(int i = 1; i <= 6; i++) {
            myCont.push_front(i);
            myCont.push_back(i);
        }
        
        std::copy(myCont.cbegin(), myCont.cend(), 
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //remove all elements with value 3 and retain the end
        std::list<int>::iterator posEnd = std::remove(myCont.begin(), myCont.end(), 
                                                      3);
        
        std::copy(myCont.begin(), posEnd, 
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //print number of removed elements
        std::cout << "number of removed elements: " << std::distance(posEnd, myCont.end()) << std::endl;
        
        //remove "removed" elements
        myCont.erase(posEnd, myCont.end());
        
        //print all elements in the modified collection
        std::copy(myCont.cbegin(), myCont.cend(), 
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        
        //if we want to remove on one line everything
        myCont.erase(std::remove(myCont.begin(), myCont.end(), 2), 
            myCont.end());
         //print all elements in the modified collection
        std::copy(myCont.cbegin(), myCont.cend(), 
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
    }
    
    void testRemoveSet() {
        std::set<int> myCont = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::copy(myCont.cbegin(), myCont.cend(), 
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //Remove all elements with value 3
        // -algorithm remove does not work
        // -instead member function erase() work.
        
        int num = myCont.erase(3);
        //print number of erased elements
        std::cout << "number of erased elements: " << num << std::endl;
        
        //print modified collection
        std::copy(myCont.cbegin(), myCont.cend(), 
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
    }
}