/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <deque>

#include "IteratorAdapters.h"


namespace C09Iterators { 
    void print(int elem) {
        std::cout << elem << ' ';
    }
    void revIterExample() {
        std::list<int> intList = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        //print all elements in normal order
        std::for_each(intList.cbegin(), intList.cend(),    //range 
                      print);                           //operation
        std::cout << std::endl;
        
        //print all elements in reverse order
        std::for_each(intList.crbegin(), intList.crend(),     //range
                     [](int elem) {
                         std::cout << elem << ' ';
                     });                                //operation
        std::cout << std::endl;
    }
    
    void revIterExample2() {
        std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int>::const_iterator pos;
        pos = std::find(intVec.cbegin(), intVec.cend(),     //range
                        5);                                 //searched value
        std::cout << "pos: " << *pos << std::endl;
        
        
        //convert to reverse iterator
        std::vector<int>::const_reverse_iterator rPos(pos);
        //print value to which reverse iterator refers
        std::cout << "rpos: " << *rPos << std::endl;
    }
    
    void revIterExample3() {
        std::deque<int> intDeque = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        //find position of element 2
        std::deque<int>::const_iterator pos1;
        pos1 = std::find(intDeque.cbegin(), intDeque.cend(),    //range
                        2);                                     //value
        
        //find position of element 7
        std::deque<int>::const_iterator pos2;
        pos2 = std::find(intDeque.cbegin(), intDeque.cend(),    //range
                        7);
        //print all elements in range [pos1, pos2)
        std::for_each(pos1, pos2,       //range 
                        print);         //operation
        std::cout << std::endl;
        
        //convert iterators to reverse iterators
        std::deque<int>::const_reverse_iterator rPos1(pos1);
        std::deque<int>::const_reverse_iterator rPos2(pos2);
        
        //print all elements in range [pos1, pos2) in reverse order
        std::for_each(rPos2, rPos1,                     //range
                     [](int elem) {                     //operation
                         std::cout << elem << ' ';
                     });
        std::cout << std::endl;
    }
    
    void revIterExample4() {
        std::list<int> intList = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        //find position of element 5
        std::list<int>::const_iterator pos;
        pos = std::find(intList.cbegin(), intList.cend(), 
                        5);
        
        //print value of the element
        std::cout << "pos: " << *pos << std::endl;
        
        //convert iterator to reverse iterator
        std::list<int>::const_reverse_iterator rPos(pos);
        
        //print value of the element to which reverse iterator refer
        std::cout << "rPos: " << *rPos << std::endl;
        
        //convert reverse iterator back to normal iterator
        std::list<int>::const_iterator rrPos;
        rrPos = rPos.base();
        
        //print value of the element to which normal iterator refer.
        std::cout << "rrPos: " << *rrPos << std::endl;
    }
}