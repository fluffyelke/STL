/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <vector>
#include <random>
#include <iterator>
#include <deque>

#include "../Utils/C11Utils.h"
#include "SortingAlgs.h"


namespace C11Algorithms {
    void sortExample() {
        std::deque<int> intDeq;
        C11Utils::insertElements(intDeq, 1, 9);
        C11Utils::insertElements(intDeq, 1, 9);
        
        C11Utils::printElements(intDeq, "on entry: ");
        
        std::sort(intDeq.begin(), intDeq.end());
        C11Utils::printElements(intDeq, "sorted:   ");
        
        //sorted reverse
        std::sort(intDeq.begin(), intDeq.end(),     //range
                  std::greater<int>());             //criterion
        C11Utils::printElements(intDeq, "sorted > :   ");
    }
    
    bool lessLength(const std::string& s1, const std::string& s2) {
        return s1.length() < s2.length();
    }
    
    void sortExample2() {
        //fill 2 collections with same elements
        std::vector<std::string> strVec1 = {
          "1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
          "7xx", "8xxx", "9xx", "10xxx", "11", "12",
          "13", "14xx", "15", "16", "17",
        };
        std::vector<std::string> strVec2(strVec1);
        
        C11Utils::printElements(strVec1, "on Entry:\n");
        
        //sort according the length of the string
        std::sort(strVec1.begin(), strVec1.end(),   //range
                  lessLength);                      //criterion
        std::stable_sort(strVec2.begin(), strVec2.end(),   //range
                         lessLength);                      //criterion
        
        C11Utils::printElements(strVec1, "\nwith sort():\n ");
        C11Utils::printElements(strVec2, "\nwith stable_sort():\n ");
    }
    
    void partialSortExample() {
        std::deque<int> intDeq;
        C11Utils::insertElements(intDeq, 3, 7);
        C11Utils::insertElements(intDeq, 2, 6);
        C11Utils::insertElements(intDeq, 1, 5);
        
        C11Utils::printElements(intDeq);
        //sort until first 5 elements are sorted
        std::partial_sort(intDeq.begin(),           //beginning of the range
                          intDeq.begin() + 5,       //end of sorted range
                          intDeq.end());            //end of full range    
        C11Utils::printElements(intDeq);
        
        //sort inversely until first 5 elements are sorted
        std::partial_sort(intDeq.begin(),           //beginning of the range
                          intDeq.begin() + 5,       //end of sorted range
                          intDeq.end(),             //end of full range
                          std::greater<int>());     //sorting criterion
        C11Utils::printElements(intDeq);
        
        //sort all elements
        std::partial_sort(intDeq.begin(),   //beginning of the range
                          intDeq.end(),     //end of sorted range
                          intDeq.end());    //end of full range
        C11Utils::printElements(intDeq);
    }
    
    void partialSortCopyExample() {
        std::deque<int> intDeq;
        std::vector<int> intVec6(6);
        std::vector<int> intVec30(30);
        
        C11Utils::insertElements(intDeq, 3, 7);
        C11Utils::insertElements(intDeq, 2, 6);
        C11Utils::insertElements(intDeq, 1, 5);
        C11Utils::printElements(intDeq);
        
        //copy elements of intDeq into intVec6 sorted
        std::vector<int>::const_iterator pos6;
        pos6 = std::partial_sort_copy(intDeq.cbegin(), intDeq.cend(),
                                      intVec6.begin(), intVec6.end());
        
        std::copy(intVec6.cbegin(), pos6,
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //copy elements of intDeq sorted into the intVec30
        std::vector<int>::const_iterator pos30;
        pos30 = std::partial_sort_copy(intDeq.cbegin(), intDeq.cend(), 
                                       intVec30.begin(), intVec30.end(),
                                       std::greater<int>());
        std::copy(intVec30.cbegin(), pos30,
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
    
    void nthElementExample() {
        std::deque<int> intDeq;
        C11Utils::insertElements(intDeq, 3, 7);
        C11Utils::insertElements(intDeq, 2, 6);
        C11Utils::insertElements(intDeq, 1, 5);
        C11Utils::printElements(intDeq);
        
        //extract the four lowest elements  
        std::nth_element(intDeq.begin(),            // beginning of the range
                         intDeq.begin() + 3,        // element that should be sorted correctly
                         intDeq.end());             // end of range
        
        //print them
        std::cout << "The four lowest elements are: ";
        std::copy(intDeq.cbegin(), intDeq.cbegin() + 4,
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //extract the 4 highest elements
        std::nth_element(intDeq.begin(),        // beginning of the range
                         intDeq.end() - 4,      // element that should be sorted correctly
                         intDeq.end());         // end of range
        
        //print them
        std::cout << "1 The four highest elements are: ";
        std::copy(intDeq.cend() - 4, intDeq.cend(),
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //extract the 4 highest elements second version
        std::nth_element(intDeq.begin(),        // beginning of the range
                         intDeq.begin() + 3,      // element that should be sorted correctly
                         intDeq.end(),            // end of range
                         std::greater<int>()); 
        std::cout << "2 The four highest elements are: ";
        std::copy(intDeq.cbegin(), intDeq.cbegin() + 4,
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
                         
    }
    
    void heapExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 3, 7);
        C11Utils::insertElements(intVec, 5, 9);
        C11Utils::insertElements(intVec, 1, 4);
        C11Utils::printElements(intVec, "on entry:           ");
        
        //convert collection into heap
        std::make_heap(intVec.begin(), intVec.end());
        C11Utils::printElements(intVec, "after make_heap():  ");
        
        //pop next element out of the heap.
        std::pop_heap(intVec.begin(), intVec.end());
        intVec.pop_back();
        C11Utils::printElements(intVec, "after pop_heap():   ");
        
        //push new element into heap
        intVec.push_back(17);
        std::push_heap(intVec.begin(), intVec.end());
        C11Utils::printElements(intVec, "after push_heap():  ");
        
        //convert heap into sorted collection
        //note after the call is no longer a heap
        std::sort_heap(intVec.begin(), intVec.end());
        C11Utils::printElements(intVec, "after sort_heap():  ");
    }
}