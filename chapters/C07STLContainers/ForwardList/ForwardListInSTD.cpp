/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <forward_list>
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
#include "ForwardListInSTD.h"


namespace C07Containers {
    void forwardListFind() {
        std::forward_list<int> list = {1, 2, 3, 4, 5, 97, 98, 99};
        
        //find the position before the first even element
        auto posBefore = list.before_begin();
        for(auto pos = list.begin(); pos != list.end(); ++pos, ++posBefore) {
            if(*pos % 2 == 0) {
                break;
            }
        }
        
        //and insert new element infront of the first even element
        list.insert_after(posBefore, 42);
        Containers::printElements(list, "forwardList: ");
    }
    
    void testSpliceAfter() {
        std::forward_list<int> listOne = {1, 2, 3, 4, 5};
        std::forward_list<int> listTwo = {97, 98, 99};
        
        //find 3 in listOne
        auto pos1 = listOne.before_begin();
        for(auto find3 = listOne.begin(); find3 != listOne.end(); ++find3, ++pos1) {
            if(*find3 == 3) {
                break;      //found
            }
        }
        
        //find 99 in listTwo
        auto pos2 = listTwo.before_begin();
        for(auto find99 = listTwo.begin(); find99 != listTwo.end(); ++find99, ++pos2) {
            if(*find99 == 99) {
                break;      //found
            }
        }
        
        //splice 3 from listOne to listTwo before 99
        listOne.splice_after(pos2, listTwo,     //destination
                            pos1);              //source
        
        Containers::printElements(listOne, "list one: ");
        Containers::printElements(listTwo, "list two: ");
    }
    
    void exampleOfForwardList() {
        
    }
}