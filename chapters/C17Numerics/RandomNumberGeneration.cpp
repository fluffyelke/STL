/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <iomanip>
#include "RandomNumberGeneration.h"


namespace C15RNG {
    void randomExample() {
        //create default engine as source of randomness
        std::default_random_engine dre;
        
        //use engine to generate integral numbers between 10 and 20 (both included); 
        std::uniform_int_distribution<int> di(10, 20);
        
        for(int i = 0; i < 20; i++) {
            std::cout << di(dre) << " ";
        }
        std::cout << std::endl;
        
        //use engine to generate floating-point numbers between 10.0 and 20.0 (10.0 included, 20.0 not included)
        std::uniform_real_distribution<double> dr(10, 20);
        for(int i = 0; i < 20; i++) {
            std::cout << dr(dre) << " ";
        }
        std::cout << std::endl;
        
        //use engine to shuffle elements
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        std::shuffle(v.begin(), v.end(),        //range
                     dre);                      //source of randomness
        
        for(auto elem : v) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    
    
    
    void randomExample2() {
        auto printNumbers = [] (std::default_random_engine& dre) -> void {
            for(int i = 0; i < 6; ++i) {
                std::cout << dre() << ' ';
            }  
            std::cout << std::endl;
        };
        
        //create engine and generate numbers
        std::default_random_engine dre;
        printNumbers(dre);
        
        
        //create equal engine and generate numbers
        std::default_random_engine dre2;    //same initial state as dre
        printNumbers(dre2);
        
        
        //create engine with initial state and generate numbers
        std::default_random_engine dre3(42);  
        printNumbers(dre3);
        
        //save state of engine dre
        std::stringstream engineState;
        engineState << dre;
        
        //generate numbers according current state of dre
        printNumbers(dre);
        
        //restore saved state of engine dre and create numbers again
        engineState >> dre;
        printNumbers(dre);
        
        //restore saved state of engine dre, skip 2 numbers and create numbers again.
        engineState.clear(); //clear EOF bit
        engineState.seekg(0);   //and move read position to the beginning
        engineState >> dre;
        dre.discard(2);
        printNumbers(dre);
    }
    
    template<typename Distr, typename Eng>
    void distr(Distr d, Eng e, const std::string& name) {
        //print min, max and four example values
        std::cout << name << ":" << std::endl;
        std::cout << "- min():    " << d.min() << std::endl;
        std::cout << "- max():    " << d.max() << std::endl;
        std::cout << "- values(): " << d(e) << ' ' << d(e) << ' ' << d(e) << ' ' << d(e)<< std::endl;
        
        //count generated values converted to integral values
        std::map<long long, int> valueCounter;
        for(int i = 0; i < 200000; ++i) {
            valueCounter[d(e)]++;
        }
        
        //and print the resulting distribution
        std::cout << "====" << std::endl;
        for(auto elem : valueCounter) {
            std::cout << std::setw(3) << elem.first << ": " << elem.second << std::endl;
        }
        std::cout << "====" << std::endl;
        std::cout << std::endl;
    }
    
    void distributionExample() {
        std::knuth_b e;
        
        std::uniform_real_distribution<> ud(0, 10);
        distr(ud, e, "uniform_real_distribution");
        
        std::normal_distribution<> nd;
        distr(nd, e, "normal_distribution");
        
        std::exponential_distribution<> ed;
        distr(ed, e, "exponential_distribution");
        
        std::gamma_distribution<> gd;
        distr(gd, e, "gamma_distribution");
    }
}