/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include <set>

#include "C06InsertIterators.h"
#include "../../Utils/Utils.h"

namespace C06STL {
    void copy2() {
        std::list<int> listCont = {1, 2, 3, 4, 5, 6 ,7 ,8, 9};      
        Containers::printElements(listCont, "List: ");
        
        std::vector<int> vecCont;
        //copy elements from listCont to vecCont by appending them
        std::copy(listCont.begin(), listCont.end(),     //source
            std::back_inserter(vecCont));   //destination
        Containers::printElements(vecCont, "Vector: ");
        
        std::deque<int> dequeCont;
        //copy elements from listCont to dequeCont, by inserted them at the front (reverse the order of elements)
        std::copy(listCont.begin(), listCont.end(), //from
            std::front_inserter(dequeCont));    //to
        Containers::printElements(dequeCont, "Deque: ");
        
        std::set<int> setCont;
        //only inserter that works for associative container
        std::copy(listCont.begin(), listCont.end(),         //from
            std::inserter(setCont, setCont.begin()));       //to
        Containers::printElements(setCont, "Set: ");
    }
    
    void testIOIterators() {
        std::vector<std::string> vecCont;
        
        //read all words from the standard input
        //- source all string until end of file(or error)
        //- destination vecCont(inserting)
        
        std::vector<std::string> str = {"first", "second", "third", "fourth", "fifth", "sisth", "seventh", "eight", "nineth", "ten" };
        std::stringstream ss;
        for(auto& elem : str) {
            elem = elem + " ";
            ss << elem;
        }
        //        std::copy(std::istream_iterator<std::string>(std::cin),     //start of source
        std::copy(std::istream_iterator<std::string>(ss),     //start of source
                  std::istream_iterator<std::string>(),             //end of source
                  std::back_inserter(vecCont));                     //destination
        
        Containers::printElements(vecCont, "Vector: ");
        
        std::sort(vecCont.begin(), vecCont.end());
        Containers::printElements(vecCont, "After Sort: ");
        
        //print all elements without duplicates
        //- source: vecCont
        //- destination: standard output with new line in between
        std::unique_copy(vecCont.cbegin(), vecCont.cend(),                      //source
                        std::ostream_iterator<std::string>(std::cout, "\n"));   //destination
    }
}