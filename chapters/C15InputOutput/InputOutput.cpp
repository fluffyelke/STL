/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <chrono>
#include <iomanip>

#include "InputOutput.h"


namespace C15IOStreams {
    
    void inputOutputExample1() {
        double x,y; //operands
        
        //print header string
        std::cout << "Multiplication of two floating point values" << std::endl;
        
        //read first operand
        std::cout << "first operand: ";
        if(!(std::cin >> x)) {
            //input error
            // => error message and exit program with error status
            std::cerr << "error while reading first floating value" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        
        //read second operand
        std::cout << "first operand: ";
        if(!(std::cin >> y)) {
            //input error
            // => error message and exit program with error status
            std::cerr << "error while reading second floating value" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        
        //print operands and result
        std::cout << x << " * " << y << " = " << x * y << std::endl; 
        
    }
    
    void processAndPrintDateAndTime() {
        //process and print current time
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        
        std::tm* nowTM = std::localtime(&t);
        
        std::cout << std::put_time(nowTM, "date: %x\ntime: %X\n") << std::endl;
        
        // read date
        std::tm* date;
        std::cout << "new date: ";
        std::cin >> std::get_time(date, "%x");  //read date
        if(!std::cin) {
            std::cerr << "Invalid format read " << std::endl;
        }
    }
    
    double readAndProcessSum(std::istream& is) {
        double value, sum;
        
        //save current state of exception flags
        std::ios::iostate oldExceptions = is.exceptions();
        
        //let failbit and badbit throw exceptions
        //note failbit is also set at the end of file
        is.exceptions(std::ios::failbit | std::ios::badbit);
        
        try {
            //while stream is ok
            //read value and add it to the sum
            while(is >> value) {
                sum += value;
            }
        }
        catch(...) {
            //if exception not cause by end of file
            //restore old state exceptions flag
            //rethrow exception
            if(!is.eof()) {
                is.exceptions(oldExceptions);       //restore exception flags
                throw;                              //rethrow
            }
        }
        
        //restore old state exception flags
        is.exceptions(oldExceptions);
        return sum;
    }
    
    double testProcessSum() {
        
        double sum;
        
        try {
            sum = readAndProcessSum(std::cin);
        }
        catch(const std::ios::failure& error) {
            std::cerr << "I/O exception: " << error.what() << std::endl;
            exit(EXIT_FAILURE);
        }
        catch(const std::exception& error) {
            std::cerr << "standard exception: " << error.what() << std::endl;
            exit(EXIT_FAILURE);
        }
        catch(...) {
            std::cerr << "unknown exception" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        std::cout << "sum: " << sum << std::endl;
    }
    
}