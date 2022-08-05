/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <ios>
#include <iomanip>

#include "MapAndMultimap.h"
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
//#include "../../../utils/RuntimeStringCmp.h"

namespace C07Containers {
    void mapMultimapExample() {
        std::map<std::string, double> myMap {
            {"tim", 9.9},
            {"struppi", 11.77},
        };
        
        //square the value of each element
        std::for_each(myMap.begin(), myMap.end(),
                     [](std::pair<const std::string, double>& elem) {
                        elem.second *= elem.second; 
                     });
                     
        //print each element
        std::for_each(myMap.cbegin(), myMap.cend(),
                      [](const std::map<const std::string, double>::value_type& elem){
                         std::cout << "[" << elem.first << "]: " << elem.second << std::endl; 
                      });
    }
    
    void mapMultimapExample2() {
        //create map associative array
        //- keys are strings
        //values are floats
        using StringFloatMap = std::map<std::string, float>;
        StringFloatMap stocks;
        
        //insert some elements
        stocks["BASF"] = 369.50;
        stocks["VW"] = 413.50;
        stocks["Daimler"] = 819.00;
        stocks["BMW"] = 834.00;
        stocks["Siemens"] = 842.30;
        
        StringFloatMap::iterator pos;       //left adjust values
        std::cout << std::left;
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
            std::cout << "stock: " << std::setw(12) << pos->first << "price: " << pos->second << std::endl;
        }
        std::cout << std::endl;
        
        //boom all priced doubled
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
            pos->second *= 2;
        }
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
            std::cout << "stock: " << std::setw(12) << pos->first << "price: " << pos->second << std::endl;
        }
        std::cout << std::endl;
        
        //rename key from VW to Volkswagen
        //- provided only by exchanging element
        stocks["Volkswagen"] = stocks["VW"];
        stocks.erase("VW");
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
            std::cout << "stock: " << std::setw(12) << pos->first << "price: " << pos->second << std::endl;
        }
        std::cout << std::endl;
        
        Containers::printMaps(stocks, "Map:");
    }
    
    void multimapDictionary() {
        //create multimap as string/string dictionary
        std::multimap<std::string, std::string> dictionary;
        
        //insert some elements in random order
        dictionary.insert({
            {"day", "Tag"}, {"strange", "fremd"}, 
            {"car", "Auto"}, {"smart", "elegant"}, 
            {"trait", "Merkmal"}, {"strange", "seltsam"}, 
            {"smart", "raffiniert"}, {"smart", "klug"}, 
            {"clever", "raffiniert"},
        });
        
        //print all elements
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout << ' ' << std::setw(10) << "english " << "german " << std::endl;
        
        std::cout << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;
        
        for(const auto& elem : dictionary) {
            std::cout << ' ' << std::setw(10) << elem.first << elem.second << std::endl;
        }
        std::cout << std::endl;
        
        //print all values for key "smart"
        std::string word("smart");
        std::cout << word << ": " << std::endl;
        
        for(auto pos = dictionary.lower_bound(word); pos != dictionary.upper_bound(word); ++pos) {
            std::cout << "    " << pos->second << std::endl;
        }
        
        //print all keys for value "rafiniert"
        word = ("raffiniert");
        std::cout << word << ": " << std::endl;
        for(const auto& elem : dictionary) {
            if(elem.second == word) {
                std::cout << "   " << elem.first << std::endl;
            }
        }
    }
    
    void findElemInMap() {
        //map with float as key and value
        //-initializing keys and values are automatically converted to floats
        std::map<float, float> myMap = {
            {1, 7}, {2, 4}, {3, 2}, {4, 3},
            {5, 6}, {6, 1}, {7, 3},
        };
        
        //search element with KEY 3.0 logarithmic complexity
        auto posKey = myMap.find(3.0);
        if(posKey != myMap.end()) {
            std::cout << "key 3.0 found: (" << posKey->first << ": " << posKey->second << ")" << std::endl;
        }
        
        //search element with VALUE 3.0 linear complexity
        auto posVal = std::find_if(myMap.begin(), myMap.end(), 
                                  [](const std::pair<float,float>& elem) {
                                      return elem.second == 3.0;
                                  });
                                
        if(posVal != myMap.end()) {
            std::cout << "value 3.0 found: (" << posVal->first << ": " << posVal->second << ")" << std::endl;
        }
    }
    
    
    void fillAndPrint(StringStringMap& myMap) {
        //insert elements in random order
        myMap["Deutschland"] = "Germany";
        myMap["deutsch"] = "German";
        myMap["Haken"] = "snag";
        myMap["arbeiten"] = "work";
        myMap["Hund"] = "dog";
        myMap["gehen"] = "go";
        myMap["Unternehmen"] = "enterprise";
        myMap["unternehmen"] = "undertake";
        myMap["gehen"] = "walk";
        myMap["Bestatter"] = "undertaker";
        
        //print elements
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for(const auto& elem : myMap) {
            std::cout << std::setw(15) << elem.first << " " << elem.second << std::endl;
        }
        std::cout << std::endl;
    }
    
    void mapWithSortCriterionAtRunTimeExample() {
        //create a container with default comparison mode
        StringStringMap mapOne;
        fillAndPrint(mapOne);
        
        //create a object for case-insensitive criterion
        Utils::RuntimeStringCmp ignorecase(Utils::RuntimeStringCmp::CmpMode::nocase);
        
        //create a container with case-insensitive comparison criterion
        StringStringMap mapTwo(ignorecase);
        fillAndPrint(mapTwo);
    }
}