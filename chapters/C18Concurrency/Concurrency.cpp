/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <random>
#include <thread>
#include <iostream>
#include <future>
#include <list>

#include "Concurrency.h"


namespace C18Concurrency {
    
    int doSomething(char c) {
        //random number generator used as seed to get different sequences
        std::default_random_engine dre(c);
        std::uniform_int_distribution<int> id(10, 1000);
        
        //loop to print character after a random period of time
        for(int i = 0; i < 10; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
            std::cout.put(c).flush();
        }
        
        return c;
    }
    
    int func1() {
        return doSomething('.');
    }
    int func2() {
        return doSomething('+');
    }
    
    void asyncExample1() {
        std::cout << "starting func1() in background and func2() in foreground:\n";
        
        //start func1() asynchronously now or later or never
        std::future<int> result1(std::async(func1));
        
        int result2 = func2();      //call func2() synchronously here and now.
        
        //print result wait for func1() to finish and its result to result2.
        int result = result1.get() + result2;
        
        std::cout << "\nresult of func1() + func2(): " << result << std::endl;
    }
    
    
    void task1() {
        //endless insertion and memory allocation
        //will sooner or later raise exception
        //beware this is bad practice
        std::list<int> v;
        while(true) {
            for(int i = 0; i < 1000000; ++i) {
                v.push_back(i);
            }
            std::cout.put('.').flush();
        }
    }
    void asyncExample2() {
        std::cout << "Starting 2 tasks" << std::endl;
        std::cout << "- task1: process endless loop of memory consumption" << std::endl;
        std::cout << "- task2: wait for <return> and than for task1" << std::endl;
        
        auto f1 = std::async(task1);    //start task1 asynchronously now or later or never.
        std::cin.get();     //read a char (like getchar();)
        
        std::cout << "\nnow wait for the end of task1:" << std::endl;
        
        try {
            f1.get();   //wait for task1() to finish, (raise exception if any).
        }
        catch(const std::exception& e) {
            std::cerr << "EXCEPTION: " << e.what() << std::endl;
        }
    }
}