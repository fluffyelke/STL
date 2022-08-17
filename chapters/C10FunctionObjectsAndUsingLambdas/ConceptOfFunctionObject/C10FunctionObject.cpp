/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>
#include <algorithm>
#include <vector>

#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
#include "C10FunctionObject.h"


namespace C10FuncObj {

    IntSequence::IntSequence(int initialValue) 
        :value{initialValue}{
        
    }

    int IntSequence::operator()() {
        return ++value;
    }

    void sequenceTest1() {
        std::list<int> intList;
        
        //insert values from 1 to 9
        std::generate_n(std::back_inserter(intList),    //start
                       9,                               //number of elements
                       IntSequence(1));                 //generate values starting with (1).
        
        Containers::printElements(intList);
        
        //replace second to last element but one with values starting at 42
        std::generate(std::next(intList.begin()),           //start
                      std::prev(intList.end()),             //end
                      IntSequence(42));                     //generate values starting at 42
        
        Containers::printElements(intList);
    }
    
    
    void sequenceTest2() {
        std::list<int> intList;
        IntSequence seq(1);             //integral sequence starting with 1
        
        //insert values from 1 to 4
        // - pass function by reference
        // so that it will continue with 5
        std::generate_n<std::back_insert_iterator<std::list<int>>, 
                        int, IntSequence&>(std::back_inserter(intList), //start
                                           4,                           //num of elements
                                           seq);                       //generate values
        
        Containers::printElements(intList);
        
        //insert values from 42 to 45
        std::generate_n(std::back_inserter(intList),    //start
                        4,                              //number of elements
                        IntSequence(42));               //generate values
        Containers::printElements(intList);
        
        //Continues with first sequence
        // -pass function object by value
        // -so that it will continue with 5 again
        std::generate_n(std::back_inserter(intList),        //start
                       4,                                   //number of elements
                       seq);                                //generate values
        Containers::printElements(intList);
        
        //continue with first sequence again
        std::generate_n(std::back_inserter(intList),    //start
                        4,                              //number of elements
                        seq);                           //generate values
        Containers::printElements(intList);
        
    }
    
    
    MeanValue::MeanValue() 
        : num(0), sum(0) {

    }

    void MeanValue::operator()(int elem) {
        ++num;          //increment count
        sum += elem;    //add value
    }

    double MeanValue::value() {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
    
    void forEachReturnExample() {
        std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8};
        
        //process and print mean value
        MeanValue mv = std::for_each(intVec.begin(), intVec.end(),  //range
                                    MeanValue());                   //operation
        
        std::cout << "mean value: " << mv.value() << std::endl;
        
    }
    
    
    Nth::Nth(int n) 
        : nth(n), count(0) {
            
    }

    bool Nth::operator()(int) {
        return ++count == nth;
    }
    void predVsFuncObjTest() {
        std::list<int> intList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
        Containers::printElements(intList, "intList:     ");
        
        //Remove third element
        std::list<int>::iterator pos;
        pos = std::remove_if(intList.begin(), intList.end(),        //range
                            Nth(3));                                //remove criterion
        intList.erase(pos, intList.end());
        Containers::printElements(intList, "3rd removed: ");
    }
}