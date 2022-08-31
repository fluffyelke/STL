/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CIString.hpp
 * Author: default
 *
 * Created on August 26, 2022, 10:45 AM
 */

#ifndef CISTRING_HPP
#define CISTRING_HPP

#include <string>


//class providing case insensitive string characteristics

//replace functions of the standard char_traits<char> 
//so that string behave in case insensitive way

namespace C13Strings {

    class IgnoreCaseTraits : public std::char_traits<char> {
    public:
        //return whether c1 and c2 are equal
        static bool eq(const char& c1, const char& c2) {
            return std::toupper(c1) == std::toupper(c2);
        }

        //return whether c1 is less than c2
        static bool lt(const char& c1, const char& c2) {
            return std::toupper(c1) < std::toupper(c2);
        }

        //compare up to n characters of s1 and s2
        static int compare(const char* s1, const char* s2, std::size_t n) {
            for(std::size_t i = 0; i < n; ++i) {
                if(!eq(s1[i], s2[i])) {
                    return lt(s1[i], s2[i]) ? -1 : 1;
                }
            }
            return 0;
        }

        //search c in s
        static const char* find(const char* s, std::size_t n, const char& c) {
            for(std::size_t i = 0; i < n; ++i) {
                if(eq(s[i], c)) {
                    return &(s[i]);
                }
            }
            return 0;
        }
    };

    using ICString = std::basic_string<char, IgnoreCaseTraits>;
    
    //define an output operator
    //because the traits type is different from that for std::ostream
    inline std::ostream& operator << (std::ostream& os, const ICString& obj) {
        //simply convert ICString to a normal string
        return os << std::string(obj.data(), obj.length());
    }
}

#endif /* CISTRING_HPP */

