/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WeakPtrExample.h
 * Author: default
 *
 * Created on July 27, 2022, 1:35 PM
 */

#ifndef WEAKPTREXAMPLE_H
#define WEAKPTREXAMPLE_H

#include <memory>
#include <vector>


namespace WeakPtr {
    //weakptr1.cpp
    class Person {
    public:
        std::string name;
        std::shared_ptr<Person> mother;
        std::shared_ptr<Person> father;
        /**
         * if we use shared pointer here
         * the destructor wont be used because all shared+ptrs points to each other.
         * the problem is resolved with using weak_ptr
         */
//        std::vector<std::shared_ptr<Person>> kids;    
        std::vector<std::weak_ptr<Person>> kids;
        
        Person(const std::string& n, std::shared_ptr<Person> m = nullptr, std::shared_ptr<Person> f = nullptr);
        ~Person();
    };
    
    extern std::shared_ptr<Person> initFamily(const std::string& name);
    
    extern void testWeakPtr();
}

#endif /* WEAKPTREXAMPLE_H */

