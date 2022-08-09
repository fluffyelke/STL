/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsingLambdaAsHash.h
 * Author: default
 *
 * Created on August 8, 2022, 10:47 AM
 */

#ifndef USINGLAMBDAASHASH_H
#define USINGLAMBDAASHASH_H

#include <ostream>


namespace C07Containers {
    //cont/hashfunc2.cpp
    class Customer2 {
    private:
        std::string firstName;
        std::string lastName;
        long no;
        
    public:
        Customer2(const std::string& f, const std::string& l, long n);
        
        std::string getFirstName() const;
        std::string getLastName() const;
        long getNumber() const;
        
        friend std::ostream& operator << (std::ostream& os, const Customer2& obj);
    };
    
    
    extern void testLambdaHash();
}

#endif /* USINGLAMBDAASHASH_H */

