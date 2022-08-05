/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

#include "SetAndMultiset.h"
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
#include "../../../utils/RuntimeCmp.h"

namespace C07Containers {
    void exampleOfLowerUpperBound() {
        std::set<int> setCont;
        setCont.insert({1, 2, 4, 5, 6});
        
        std::cout << "lower_bound(3): " << *setCont.lower_bound(3) << std::endl;
        std::cout << "upper_bound(3): " << *setCont.upper_bound(3) << std::endl;
        std::cout << "equal_range(3): " << *setCont.equal_range(3).first << " " 
                                        << *setCont.equal_range(3).second << std::endl;
        
        std::cout << std::endl;
        std::cout << "lower_bound(5): " << *setCont.lower_bound(5) << std::endl;
        std::cout << "upper_bound(5): " << *setCont.upper_bound(5) << std::endl;
        std::cout << "equal_range(5): " << *setCont.equal_range(5).first << " " 
                                        << *setCont.equal_range(5).second << std::endl;
    }
    
    
    void setMultisetExample() {
        //type of the collection
        //- no duplicates
        //- elements are integral values
        //- descending order
        std::set<int, std::greater<int>> setOne;
        
        //insert elements in random order using different operations
        setOne.insert({4, 3, 5, 6, 1, 2});
        setOne.insert(5);
        
        Containers::printElements(setOne, "setOne init: ");
        std::cout << std::endl;
        
        //insert 4 again and process return value
        auto status = setOne.insert(4);
        if(status.second) {
            std::cout << "4 inserted as element " << std::distance(setOne.begin(), status.first) + 1;
        }
        else {
            std::cout << "4 already exists!\n";
        }
        
        //assign elements to another set with ascending order
        std::set<int> setTwo(setOne.cbegin(), setOne.cend());
        //print all elements using stream iterator
        std::copy(setTwo.cbegin(), setTwo.cend(),
                 std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //removes all element up to value 3
        setTwo.erase(setTwo.begin(), setTwo.find(3));
        
        //removes all elements with value 5;
        int num;
        num = setTwo.erase(5);
        std::cout << num << " elemen(s) removed" << std::endl;
        
        //print all elements using stream iterator
        std::copy(setTwo.cbegin(), setTwo.cend(),
                 std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
    
    using IntSet = std::set<int, Utils::RuntimeCmp>;
    
    void testRuntimeCmp() {
        //create fill and print set with normal element order
        //- uses default sorting criteria
        IntSet setOne = {4, 7, 5, 1, 6, 2, 5};
        Containers::printElements(setOne, "setOne init: ");
        
        //create sorting criteria with reverse element order
        Utils::RuntimeCmp reverseOrder(Utils::RuntimeCmp::CmpMode::reverse);
        
        IntSet setTwo({4, 7, 5, 1, 6, 2, 5}, reverseOrder);
        Containers::printElements(setTwo, "setTwo init: ");
        
        //assign elements AND sorting criterion
        setOne = setTwo;
        setOne.insert(3);
        Containers::printElements(setOne, "setOne: ");
        
        //just to make sure
        if(setOne.value_comp() == setTwo.value_comp()) {
            std::cout << "setOne and setTwo have the same sorting criteria" << std::endl;
        }
        else {
            std::cout << "setOne and setTwo have different sorting criteria" << std::endl;
        }
    }
}