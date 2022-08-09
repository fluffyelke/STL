/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserDefinedHashFunctionAndEquivalentCriterion.h
 * Author: default
 *
 * Created on August 8, 2022, 10:21 AM
 */

#ifndef USERDEFINEDHASHFUNCTIONANDEQUIVALENTCRITERION_H
#define USERDEFINEDHASHFUNCTIONANDEQUIVALENTCRITERION_H

#include <ostream>
#include <cstdlib>


namespace C07Containers{
    //cont/hashfunc1.cpp
    class Customer {
    private:
        std::string firstName;
        std::string secondName;
        long no;
        
    public:
        Customer(std::string firstName, std::string secondName, long no);
        
        friend std::ostream& operator << (std::ostream& os, const Customer& obj);
        
        friend class CustomerHash;
        friend class CustomerEqual;

    };
    
    class CustomerHash {
    public:
        std::size_t operator () (const Customer& obj) const;
    };
    
    class CustomerEqual {
    public:
        bool operator () (const Customer& left, const Customer& right) const;
    };
    
    extern void testOwnHash();
}

#endif /* USERDEFINEDHASHFUNCTIONANDEQUIVALENTCRITERION_H */

