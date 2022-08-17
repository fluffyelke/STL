/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C10FunctionObject.h
 * Author: default
 *
 * Created on August 10, 2022, 10:21 AM
 */

#ifndef C10FUNCTIONOBJECT_H
#define C10FUNCTIONOBJECT_H

namespace C10FuncObj {
    // fo/sequence1.cpp
    class IntSequence {
        int value;
        
    public:
        IntSequence(int initialValue);  //constructor
        
        int operator () ();     //"function call"
    };
    
    extern void sequenceTest1();
    
    // fo/sequence2.cpp   pass function object by reference
    extern void sequenceTest2();
    
    //Return value of for_each is its function object
    // fo/foreach3.cpp
    //Function object to process mean value
    class MeanValue {
    private:
        long num;       //number of elements
        long sum;       //sum of all elements
    public:
        // constructor
        MeanValue();
        
        //"function call"
        //-process one more element of the sequence
        void operator () (int elem);
        
        //return mean value
        double value();
    };
    
    extern void forEachReturnExample();
    
    
    
    //Predicates vs Function objects
    // fo/removeif1.cpp
    class Nth {     //function object that returns true for the nth call
        int nth;        //call for which to return true
        int count;      //call counter
    public:
        Nth(int n);
        //!!!predicate should not change the state of the object. So should be declared const " bool operator() (args) const; "
        bool operator () (int);     
    };
    extern void predVsFuncObjTest();
}

#endif /* C10FUNCTIONOBJECT_H */

