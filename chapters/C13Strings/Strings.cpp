/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

#include "Strings.h"
#include "CIString.hpp"

namespace C13Strings {
    
    void stringExample1(int argc, const char* argv[]) {
        std::string filename, basename, extname, tmpname;
        const std::string suffix("tmp");
        
        //for each command-line argument, which is ordinary C-String
        for(int i = 0; i < argc; i++) {
            //process the argument as filename
            filename = argv[i];
            
            //search period in the filename
            std::string::size_type idx = filename.find('.');
            if(idx == std::string::npos) {
                //filename does not contain any period
                tmpname = filename + '.' + suffix;
            }
            else {
                //split filename into base name and extension
                //base name contains all characters before the period
                //extension contains all characters after the period
                basename = filename.substr(0, idx);
                extname = filename.substr(idx + 1);
                
                if(extname.empty()) {
                    //contains period but no extension add tmp
                    tmpname = filename;
                    tmpname += suffix;
                }
                else if(extname == suffix){
                    //replace extension tmp with xxx
                    tmpname = filename;
                    tmpname.replace(idx + 1, extname.size(), "xxx");
                }
                else {
                    //replace any extension with tmp
                    tmpname = filename;
                    tmpname.replace(idx + 1, std::string::npos, suffix);
                }
            }
            
            //print filename and temporary name
            std::cout << filename << " => " << tmpname << std::endl;
        }
    }
    
    void stringExample2() {
        const std::string delims(" \t.,;");
        std::string line;
        
        // for every read line successfully
        while(getline(std::cin, line)) {
            std::string::size_type begIdx, endIdx;
            
            //search beginning of the first word
            begIdx = line.find_first_not_of(delims);
            
            //while beginning of the word found
            while(begIdx != std::string::npos) {
                //search end of the actual word
                endIdx = line.find_first_of(delims, begIdx);
                
                
                if(endIdx == std::string::npos) {
                    //end of word is end of line
                    endIdx = line.length();
                }
                
                //print characters in reverse order
                for(int i = endIdx - 1; i >= static_cast<int>(begIdx); --i) {
                    std::cout << line[i];
                }
                std::cout << ' ';
                
                //search beginning of the next word
                begIdx = line.find_first_not_of(delims, endIdx);
            }
            
            std::cout << std::endl;
        }
    }
    
    void stringIterExample() {
        //create a string
        std::string s("The zip code of Branschweig in Germany is 38100");
        std::cout << "original: " << s << std::endl;
        
        //lowercase all characters
        std::transform(s.cbegin(), s.cend(),        //source
                       s.begin(),                   //destination
                       [](char c) {                 //operation
                          return std::tolower(c); 
                       });
                       
        std::cout << "lowered:  " << s << std::endl;
        
        //uppered all characters
        std::transform(s.cbegin(), s.cend(),        //source
                       s.begin(),                   //destination
                       [](char c) {                 //operation
                          return std::toupper(c); 
                       });
                       
        std::cout << "uppered:  " << s << std::endl;
        
        //search case insensitve for Germany
        std::string g("Germany");
        std::string::const_iterator pos;
        pos = std::search(s.cbegin(), s.cend(),                             //source string in which to search
                          g.cbegin(), g.cend(),                             //substring to search
                          [](char c1, char c2) {                            //comparison criterion
                             return std::toupper(c1) == std::toupper(c2); 
                          });
        if(pos != s.cend()) {
            std::cout << "substring \"" << g << "\" found at index: "
                      << pos - s.cbegin() << std::endl;
        }
    }
    
    void stringIterExample2() {
        //create const string
        const std::string hello("Hello, how are you?");
        
        //initialize string s with all characters of string hello
        std::string s(hello.cbegin(), hello.cend());
        
        //ranged based for loop that iterates through all characters
        for(char c : s) {
            std::cout << c;
        }
        std::cout << std::endl;
        
        //reverse the order of all characters inside the string
        std::reverse(s.begin(), s.end());
        std::cout << "reverse:       " << s << std::endl;
        
        //sort all characters inside the string s
        std::sort(s.begin(), s.end());
        std::cout << "ordered:       " << s << std::endl;
        
        //remove adjacent duplicates
        //-unique() reorders and returns new end()
        //-erase() shrinks accordingly
        s.erase(std::unique(s.begin(), 
                            s.end()),
                s.end());
        std::cout << "no duplicates: " << s << std::endl;
    }
    
    void stringIterExample3() {
        std::string input;
        
        //dont skip leading whitespaces
        std::cin.unsetf(std::ios::skipws);
        
        //read all characters while compressing whitespaces
        const std::locale& loc(std::cin.getloc());  //locale
        std::unique_copy(std::istream_iterator<char>(std::cin),                     //beginning of source
                         std::istream_iterator<char>(),                             //end of source
                         std::back_inserter(input),                                 //destination
                         [=](char c1, char c2) {                                    //criterion for adj. duplicates
                            return std::isspace(c1, loc) && std::isspace(c2, loc);
                         });
                         
        //process input
        //here add it to standard output
        std::cout << input << std::endl;
    }
    
    void stringICExample() {
        C13Strings::ICString s1("hallo");
        C13Strings::ICString s2("otto");
        C13Strings::ICString s3("hALLo");
        
        std::cout << std::boolalpha;
        std::cout << s1 << " == " << s2 << " : " << (s1 == s2) << std::endl;
        std::cout << s1 << " == " << s3 << " : " << (s1 == s3) << std::endl;
        
        C13Strings::ICString::size_type idx = s1.find("All");
        if(idx != C13Strings::ICString::npos) {
            std::cout << "index of \"All\" in \"" << s1 << "\": " << idx << std::endl;
        }
    }
}