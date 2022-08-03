/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "WeakPtrExample.h"


namespace WeakPtr {

    Person::Person(const std::string& n, std::shared_ptr<Person> m, std::shared_ptr<Person> f) 
        : name{n},
          mother{m},
          father{f}{

    }

    Person::~Person() {
        std::cout << "Person delete: " << name << std::endl; 
    }
    
    std::shared_ptr<Person> initFamily(const std::string& name) {
        std::shared_ptr<Person> mom{new Person(name + "'s mom")};
        std::shared_ptr<Person> dad{new Person(name + "'s dad")};
        std::shared_ptr<Person> kid{new Person(name, mom, dad)};
        mom->kids.push_back(kid);
        dad->kids.push_back(kid);
        return kid;
    }
    
    void testWeakPtr() {
        std::shared_ptr<Person> p = initFamily("Vanya");
        
        std::cout << "Vanya's family exist" << std::endl;
        std::cout << "- Vanya is shared: " << p.use_count() << " times " << std::endl;
        std::cout << "- name of 1st kid of vanya's mom: " << p->mother->kids[0].lock()->name << std::endl;
        
        p = initFamily("Elinna");
        std::cout << "elinna's family exists" << std::endl;
    }

}