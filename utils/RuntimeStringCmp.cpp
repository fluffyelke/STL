/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>

#include "RuntimeStringCmp.h"


namespace Utils {

    RuntimeStringCmp::RuntimeStringCmp(CmpMode m) 
        : mode{m} {

    }

    bool RuntimeStringCmp::operator()(const std::string& s1, const std::string& s2) {
        if(mode == CmpMode::normal) {
            return s1 < s2;
        }
        else {
            std::lexicographical_compare(s1.begin(), s1.end(),
                                         s2.begin(), s2.end(),
                                         nocaseCompare);
        }
    }


}