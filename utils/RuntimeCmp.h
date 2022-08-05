/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RuntimeCmp.h
 * Author: default
 *
 * Created on August 5, 2022, 11:00 AM
 */

#ifndef RUNTIMECMP_H
#define RUNTIMECMP_H

namespace Utils {
    //cont/setcmp1.cpp
    //type for runtime sorting criteria
    class RuntimeCmp {
        
    public:
        enum class CmpMode {
            normal,
            reverse
        };
        
        //constructor for sorting criteria
        //- default criterion uses value normal
        RuntimeCmp(CmpMode m = CmpMode::normal);
        
        //comparison of elements
        //- member function for any element type 
        template<typename T>
        bool operator () (const T& left, const T& right) const {
            return mode == CmpMode::normal ? left < right : right < left;
        }
        
        //comparison of sorting criteria
        bool operator == (const RuntimeCmp& rc) const;
        
    private:
        CmpMode mode;
    };
}

#endif /* RUNTIMECMP_H */

