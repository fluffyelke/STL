/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>

#include "ListInSTD.h"


namespace C07Containers {
    template<typename T>
    void printLists(const std::list<T>& first, const std::list<T>& second) {
        std::cout << "First  List: ";
        std::copy(first.cbegin(), first.cend(),
            std::ostream_iterator<T>(std::cout," "));
        
        std::cout << std::endl;
        
        std::cout << "Second List: ";
        std::copy(second.cbegin(), second.cend(),
            std::ostream_iterator<T>(std::cout," "));
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    void listsExample() {
        std::list<int> first, second;
        
        //fill both list with elements
        for(int i = 1; i <= 6; ++i) {
            first.push_back(i);
            second.push_front(i);
        }
        
        printLists(first, second);
        
        //inserts all elements of first list before first element of second list with value 3.
        // - find() returns the iterator to the first element with value 3
        second.splice(std::find(second.begin(), second.end(), //destination position
                                3),                 //searched element
                                first);             //source list
        printLists(first, second);
        
        //move first element of second list, to the end
        second.splice(second.end(),         //destination position
                      second,               //source list
                      second.begin());      //source position
        printLists(first, second);
        
        //sort second list, assign to first list and remove duplicates
        second.sort();
        first = second;
        second.unique();
        printLists(first, second);
        
        //merge both sorted list into the first list
        first.merge(second);
        printLists(first, second);
    }
}