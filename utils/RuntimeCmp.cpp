/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RuntimeCmp.h"

namespace Utils {

    RuntimeCmp::RuntimeCmp(CmpMode m) 
        :mode{m} {
        
    }

    bool RuntimeCmp::operator == (const RuntimeCmp& rc) const {
        return mode == rc.mode;
    }
}