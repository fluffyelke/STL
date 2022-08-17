/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserDefinedIter.h
 * Author: default
 *
 * Created on August 9, 2022, 4:25 PM
 */

#ifndef USERDEFINEDITER_H
#define USERDEFINEDITER_H

#include <iterator>


namespace C09Iterators {
    //class template for insert iterator for associative and unordered containers
    template<typename Container>
    class AssociativeInsertIterator 
        : public std::iterator<std::output_iterator_tag, typename Container::value_type>{
        
    protected:
        Container& container;           //container in which elements are inserted
        
    public:
        //constructor
        explicit AssociativeInsertIterator(Container& c) : container{c} {}
        
        //assignment operator 
        //insert the value into container
        AssociativeInsertIterator<Container>& operator = (const typename Container::value_type& value) {
            container.insert(value);
            return *this;
        }
        
        //dereferencing is no-op that returns iterator itself
        AssociativeInsertIterator<Container>& operator * () {
            return *this;
        }
        
        //incrementing is no-op that returns iterator itself
        AssociativeInsertIterator<Container>& operator ++ () {
            return *this;
        }
        //incrementing is no-op that returns iterator itself
        AssociativeInsertIterator<Container>& operator ++ (int) {
            return *this;
        }
    };
    
    //convenience function to create the inserter
    template<typename Container>
    inline AssociativeInsertIterator<Container> assoInserter(Container& c) {
        return AssociativeInsertIterator<Container>(c);
    }
}

#endif /* USERDEFINEDITER_H */

