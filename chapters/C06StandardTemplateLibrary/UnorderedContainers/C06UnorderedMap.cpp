/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unordered_map>
#include "../Utils/Utils.h"
#include "C06UnorderedMap.h"


namespace C06STL {
    void testUnorderedMap() {
        std::unordered_map<std::string, double> myCont {
            {"tim", 9.9},
            {"struppi", 11.77},
            {"struppi", 25.77},
        };
        
        Containers::printMaps(myCont, "Before Square Map: ");
        //square the value of each element
        for(std::pair<const std::string, double>& elem : myCont) {
            elem.second *= elem.second;
        }
        Containers::printMaps(myCont, "After Square Map: ");
        
    }
    
    void assoArray1() {
        std::unordered_map<std::string, float> myCont;
        
        //insert element using array syntax
        myCont["VAT1"] = 0.16;
        myCont["VAT2"] = 0.07;
        myCont["Pi"] = 3.1415;
        myCont["an arbitrary number"] = 4983.223;
        myCont["Null"] = 0;
        
        //change value
        myCont["VAT1"] += 0.03;
        
        //print difference of vat values
        std::cout << "VAT difference: " << myCont["VAT1"] - myCont["VAT2"] << std::endl;
    }
}