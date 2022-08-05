/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RuntimeStringCmp.h
 * Author: default
 *
 * Created on August 5, 2022, 2:46 PM
 */

#ifndef RUNTIMESTRINGCMP_H
#define RUNTIMESTRINGCMP_H

#include <locale>


namespace Utils {
    /**
     * Function object to compare strings in runtimetime
     * -allows you to set the comparison criterion at runtime
     * -allows you to comapre case sensitive
     * 
     */
    class RuntimeStringCmp {
    public:
        //constants for comparison criterion
        enum class CmpMode {
            normal, 
            nocase
        };
        
        RuntimeStringCmp(CmpMode m = CmpMode::normal);
        
        //the comparison
        bool operator () (const std::string& s1, const std::string& s2);
    private:
        //actual comparison mode
        const CmpMode mode;
        //auxiliary function to compare case sensitive
        static bool nocaseCompare(char c1, char c2) {
            return std::toupper(c1) < std::toupper(c2);
        }
    };
}

#endif /* RUNTIMESTRINGCMP_H */

