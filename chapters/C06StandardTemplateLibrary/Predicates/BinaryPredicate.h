/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryPredicate.h
 * Author: default
 *
 * Created on August 3, 2022, 10:07 AM
 */

#ifndef BINARYPREDICATE_H
#define BINARYPREDICATE_H

#include <string>


namespace C06STL {
    class Person {
    public:
        Person(const std::string& first, const std::string& second);
        std::string getFirstName() const;
        std::string getSecondName() const;
        
        std::string firstName;
        std::string secondName;
        
        friend std::ostream& operator << (std::ostream& os, const Person& obj);
    };
    
    //binary function predicate
    //-return whether a person is less than another person
    extern bool personSortCriterion(const Person& left, const Person& right);
    
    extern void testPersonSortPredicate();
}

#endif /* BINARYPREDICATE_H */

