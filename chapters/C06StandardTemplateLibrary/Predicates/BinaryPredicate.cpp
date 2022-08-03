/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <deque>
#include <algorithm>

#include "BinaryPredicate.h"


namespace C06STL {

    Person::Person(const std::string& first, const std::string& second) 
        :firstName{first},
         secondName{second} {
//            std::cout << firstName << " " << secondName << " created!\n";
            std::cout << *this << std::endl;
    }
    std::string Person::getFirstName() const {
        return firstName; 
    }
    std::string Person::getSecondName() const {
        return secondName;
    }
    
    std::ostream& operator<<(std::ostream& os, const Person& obj) {
        return os << obj.firstName << " " << obj.secondName;
    }

    
    bool personSortCriterion(const Person& left, const Person& right) {
        /**
         * Person is less than another person if
         * -the last name is less,
         * -if the last name is equal and the first name is less
         */
        return left.getSecondName() < right.getSecondName() ||
            (left.getSecondName() == right.getSecondName() && left.getFirstName() < right.getFirstName());
    }
    
    
    void testPersonSortPredicate() {
        std::deque<Person> myCont;
        
        myCont.push_back(Person("Stefi", "Slavova"));
        myCont.push_back(Person("Desi", "Naidenova"));
        myCont.push_back(Person("Elina", "Georgieva"));
        myCont.push_back(Person("Elina", "Slavova"));
        myCont.push_back(Person("Vanya", "Dimitrova"));

        std::cout << "\nBefore sort: \n";
        for(auto& elem : myCont) {
            std::cout << elem << std::endl;
        }
        std::cout << "\nAfter Sort: \n";
        
        std::sort(myCont.begin(), myCont.end(),     //range
            personSortCriterion);                   //sort criterion, binary predicate function
        
        for(auto& elem : myCont) {
            std::cout << elem << std::endl;
        }
        
        
        //Using Lambda for sort criterion
//        std::sort(myCont.begin(), myCont.end(),
//            [](const Person& left, const Person& right) -> bool {
//                return left.getSecondName() < right.getSecondName() ||
//                        (left.getSecondName() == right.getSecondName() && left.getFirstName() < right.getFirstName());
//            });
    }

}