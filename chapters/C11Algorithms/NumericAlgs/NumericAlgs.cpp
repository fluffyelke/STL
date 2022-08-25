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
#include "NumericAlgs.h"

namespace C11Algorithms {
    void accumulateExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec);
        
        //process sum of elements
        std::cout << "sum: "
                  << std::accumulate(intVec.cbegin(), intVec.cend(),    //range
                                     0)                                //initial value.
                  << std::endl;                      
        
        
        //process sum of elements less 100
        std::cout << "sum: "
                  << std::accumulate(intVec.cbegin(), intVec.cend(),    //range
                                     -100)                                //initial value.
                  << std::endl;
        
        //process product of elements
        std::cout << "sum: "
                  << std::accumulate(intVec.cbegin(), intVec.cend(),    //range
                                     1,
                                     std::multiplies<int>())            //initial value.
                  << std::endl;
        
        //process product of elements (use 0 as initial value)
        std::cout << "sum: "
                  << std::accumulate(intVec.cbegin(), intVec.cend(),    //range
                                     0,
                                     std::multiplies<int>())            //initial value.
                  << std::endl;
    }
    
    void innerProductExample() {
        std::list<int> intList;
        C11Utils::insertElements(intList, 1, 6);
        C11Utils::printElements(intList);
        
        //process sum of all products
        //(0 + 1 * 1 + 2 * 2 + 3 * 3...)
        std::cout << "inner product: ";
        std::cout << std::inner_product(intList.cbegin(), intList.cend(),   //first range
                                        intList.cbegin(),                   //second range
                                        0)                                 //initial value
                  << std::endl;
        
        //process sum of 1 * 6 ... 6 * 1
        //(0 + 1 * 6 + 2 * 5 + 3 * 4 + 4 * 3 + 5 * 2 + 6 * 1)
        std::cout << "inner reverse product: ";
        std::cout << std::inner_product(intList.cbegin(), intList.cend(),   //first range
                                        intList.crbegin(),                   //second range
                                        0)                                 //initial value
                  << std::endl;
        
        //process product of all sums
        //(1 * 1+1 * 2+2 * 3+3...)
        std::cout << "product of sums: ";
        std::cout << std::inner_product(intList.cbegin(), intList.cend(),   //first range
                                        intList.cbegin(),                   //second range
                                        1,                                  //initial value
                                        std::multiplies<int>(),             //outer operation
                                        std::plus<int>())                   //inner operation                    
                  << std::endl;
    }
    
    void partialSumExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 6);
        C11Utils::printElements(intVec);
        
        //print all partial sums
        std::partial_sum(intVec.cbegin(), intVec.cend(),                    //source range
                         std::ostream_iterator<int>(std::cout, " "));       //destination
        std::cout << std::endl;
        
        //print all partial products
        std::partial_sum(intVec.cbegin(), intVec.cend(),                    //source range
                         std::ostream_iterator<int>(std::cout, " "),
                         std::multiplies<int>());       //destination
        std::cout << std::endl;
    }
    
    void adjacentDiffExample() {
        std::deque<int> intDeq;
        
        C11Utils::insertElements(intDeq, 1, 6);
        C11Utils::printElements(intDeq);
        
        //print all differences between the elements
        std::adjacent_difference(intDeq.begin(), intDeq.end(),                  //source 
                                 std::ostream_iterator<int>(std::cout, " "));   //destination
        std::cout << std::endl;
        
        //print all sum with the predecessors
        std::adjacent_difference(intDeq.begin(), intDeq.end(),              //source
                                 std::ostream_iterator<int>(std::cout, " "),    //destination
                                 std::plus<int>());                         //operation
        std::cout << std::endl;
        
        //print all products between the elements
        std::adjacent_difference(intDeq.begin(), intDeq.end(),              //source
                                 std::ostream_iterator<int>(std::cout, " "),    //destination
                                 std::multiplies<int>());                         //operation
        std::cout << std::endl;
    }
    
    void relativeAbsExample() {
        std::vector<int> intVec = {17, -3, 22, 13, 13, -9};
        C11Utils::printElements(intVec, "intVec:    ");
        
        //convert into relative values
        std::adjacent_difference(intVec.cbegin(), intVec.cend(),    //source
                                 intVec.begin());                  //destination
        
        C11Utils::printElements(intVec, "relative:  ");
        
        //convert into absolute values
        std::partial_sum(intVec.cbegin(), intVec.cend(),    //source
                                 intVec.begin());          //destination
        C11Utils::printElements(intVec, "absolute:  ");
    }
}