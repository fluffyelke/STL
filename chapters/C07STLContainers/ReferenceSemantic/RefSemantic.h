/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RefSemantic.h
 * Author: default
 *
 * Created on August 8, 2022, 11:41 AM
 */

#ifndef REFSEMANTIC_H
#define REFSEMANTIC_H

#include <iostream>


namespace C07Containers {
    class Item {
    private:
        std::string name;
        float price;
    public:
        Item(const std::string& n, float p);
        
        void setName(const std::string& n);
        std::string getName() const;
        
        void setPrice(const float& p);
        float getPrice() const;
    };
    
    
    //helper method
    template<typename Coll>
    void printItems(const std::string& msg, const Coll& coll) {
        std::cout << msg << std::endl;
        for(const auto& elem : coll) {
            std::cout << ' ' << elem->getName() << ": "
                             << elem->getPrice() << std::endl;
        }
    }
    
    extern void testRefSemantic();
}

#endif /* REFSEMANTIC_H */

