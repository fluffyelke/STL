/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <random>
#include <iterator>

#include "../Utils/C11Utils.h"
#include "MutatingAlgs.h"


namespace C11Algorithms {
    void reverseExample() {
        std::vector<int> intVec;
        
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec: ");
        
        //reverse order of elements
        std::reverse(intVec.begin(), intVec.end());
        C11Utils::printElements(intVec, "intVec: ");
        
        //reverse order from second to last element but one
        std::reverse(intVec.begin() + 1, intVec.end() - 1);
        C11Utils::printElements(intVec, "intVec: ");
        
        //print all of them in reverse order
        std::reverse_copy(intVec.cbegin(), intVec.cend(),               //source
                          std::ostream_iterator<int>(std::cout, " "));  //destination
        std::cout << std::endl;
    }
    
    void rotateExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec: ");
        
        //rotate 1 element to the left
        std::rotate(intVec.begin(),             //beginning of the range
                    intVec.begin() + 1,         // new first element
                    intVec.end());              // end of range
        C11Utils::printElements(intVec, "one left: ");
        
        //rotate 2 elements to the right
        std::rotate(intVec.begin(),             //beginning of the range
                    intVec.end() - 2,         // new first element
                    intVec.end());              // end of range
        C11Utils::printElements(intVec, "two right: ");
        
        //rotate so that the element with value 4 is the beginning
        std::rotate(intVec.begin(),                                     //beginning of the range
                    std::find(intVec.begin(), intVec.end(), 
                              4),         // new first element
                    intVec.end());                                      // end of range
        C11Utils::printElements(intVec, "4 first: ");
    }
    
    void rotateExample2() {
        std::set<int> intSet;
        C11Utils::insertElements(intSet, 1, 9);
        C11Utils::printElements(intSet);
        
        //print element rotate 1 element to the left.
        std::set<int>::iterator pos = std::next(intSet.cbegin());
        std::rotate_copy(intSet.cbegin(),                               //beginning of the source
                         pos,                                           //new first element
                         intSet.cend(),                                 //end of source 
                         std::ostream_iterator<int>(std::cout, " "));   //destination
        std::cout << std::endl;
        
        //print elements rotate 2 elements to the right
        pos = intSet.cend();
        std::advance(pos, -2);
        std::rotate_copy(intSet.cbegin(),                               //beginning of the source
                         pos,                                           //new first element
                         intSet.cend(),                                 //end of source 
                         std::ostream_iterator<int>(std::cout, " "));   //destination
        std::cout << std::endl;
        
        //print elements rotated so that element with value 4 is the beginning
        std::rotate_copy(intSet.cbegin(),                               //beginning of the source
                         intSet.find(4),                                           //new first element
                         intSet.cend(),                                 //end of source 
                         std::ostream_iterator<int>(std::cout, " "));   //destination
        std::cout << std::endl;
    }
    
    void permutationExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 4);
        C11Utils::printElements(intVec, "on entry:  ");
        
        //permute elements until they are sorted
        //runs through all permutations because the elements are sorted now.
        while(std::next_permutation(intVec.begin(), intVec.end())) {
            C11Utils::printElements(intVec, " ");
        }
        C11Utils::printElements(intVec, "afterward: ");
        
        //permute until descending sorted
        //this is the next permutation after ascending sorting
        //so the loops ends immediately
        while(std::prev_permutation(intVec.begin(), intVec.end())) {
            C11Utils::printElements(intVec, " ");
        }
        C11Utils::printElements(intVec, "now:       ");
        
        
        //permute elements until they are sorted in descending order
        //runs through all elements because elements are sorted in descending order now.
        while(std::prev_permutation(intVec.begin(), intVec.end())) {
            C11Utils::printElements(intVec, " ");
        }
        C11Utils::printElements(intVec, "afterward:       ");
    }
    
    void shuffleExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec:   ");

        //shuffle all elements randomly
        std::random_shuffle(intVec.begin(), intVec.end());
        C11Utils::printElements(intVec, "shuffled: ");
        
        //sort them again
        std::sort(intVec.begin(), intVec.end());
        C11Utils::printElements(intVec, "sorted:   ");
        
        //shuffle elements with default engine
        std::default_random_engine  dre;
        std::shuffle(intVec.begin(), intVec.end(),  //range
                     dre);                          //random number generator.
        C11Utils::printElements(intVec, "shuffled: ");
    }
    
    
    class MyRandom {
    public:
        std::ptrdiff_t operator() (std::ptrdiff_t max) {
            double tmp;
            tmp = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
            return static_cast<std::ptrdiff_t> (tmp * max);
        }
    };
    
    void randomShuffleExample() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec: ");
        
        // shuffle elements with self-writen random number generator
//        MyRandom rd;
        std::random_shuffle(intVec.begin(), intVec.end(),   //range
                            MyRandom());                            //random number generator.
        C11Utils::printElements(intVec, "shuffled: ");
    }
    
    void partitionExample() {
        std::vector<int> intVec1;
        std::vector<int> intVec2;
        
        C11Utils::insertElements(intVec1, 1, 9);
        C11Utils::insertElements(intVec2, 1, 9);
        C11Utils::printElements(intVec1, "intVec1: ");
        C11Utils::printElements(intVec2, "intVec2: ");
        std::cout << std::endl;
        
        //move all even elements to the front
        std::vector<int>::iterator pos1, pos2;
        pos1 = std::partition(intVec1.begin(), intVec1.end(),       //range
                              [](int elem) {                        //criterion
                                 return elem % 2 == 0; 
                              });
                              
        pos2 = std::stable_partition(intVec2.begin(), intVec2.end(),        //range
                                     [](int elem) {                         //criterion
                                        return elem % 2 == 0; 
                                     });
                                     
        //print collections and first odd element
        C11Utils::printElements(intVec1, "intVec1: ");
        std::cout << "first odd element: " << *pos1 << std::endl;
        C11Utils::printElements(intVec2, "intVec2: ");
        std::cout << "first odd element: " << *pos2 << std::endl;
    }
    
    void partitionCopyExample() {
        std::vector<int> intVec = {1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5};
        C11Utils::printElements(intVec, "intVec: ");
        
        //destination collections
        std::vector<int> evenVec;
        std::vector<int> oddVec;
        
        //copy all elements partitioned accordingly into even and odd elements
        std::partition_copy(intVec.cbegin(), intVec.cend(),     //source range
                            std::back_inserter(evenVec),        //destination for even elements
                            std::back_inserter(oddVec),         //destination for odd elements
                            [](int elem) {                      //predicate: check for even elements
                               return elem % 2 == 0; 
                            });
        C11Utils::printElements(evenVec, "evenVec: ");
        C11Utils::printElements(oddVec,  "oddVec:  ");
    }
}