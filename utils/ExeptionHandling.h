/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExeptionHandling.h
 * Author: default
 *
 * Created on July 25, 2022, 4:32 PM
 */

#ifndef EXEPTIONHANDLING_H
#define EXEPTIONHANDLING_H

#include <exception>
#include <system_error>
#include <future>
#include <iostream>

namespace Utils {
    /**
     * This allows exception to be handle like this
     * 
     * try {
     * ...
     * }
     * catch(...) {
     *      processException();
     * }
     * 
     */
    
    template<typename T>
    void processCodeException(const T& e) {
        auto c = e.code();
        
        std::cerr << "- category: " << c.category().name() << std::endl;
        std::cerr << "- value: " << c.value() << std::endl;
        std::cerr << "- message: " << c.message() << std::endl;
        std::cerr << "- default category: " << c.default_error_condition().category().name() << std::endl;
        std::cerr << "- default value: " << c.default_error_condition().value() << std::endl;
        std::cerr << "- default message: " << c.default_error_condition().message() << std::endl;
    }
    
    void processException() {
        try {
            throw;
        }
        catch(const std::ios_base::failure& e) {
            std::cerr << "I/O EXCEPTION: " << e.what() << std::endl;
            processCodeException(e);
        }
        catch(const std::system_error& e) {
            std::cerr << "SYSTEM EXCEPTION: " << e.what() << std::endl;
            processCodeException(e);
        }
        catch(const std::future_error& e) {
            std::cerr << "FUTURE EXCEPTION: " << e.what() << std::endl;
            processCodeException(e);
        }
        catch(const std::bad_alloc& e) {
            std::cerr << "BAD ALLOC EXCEPTION: " << e.what() << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << "EXCEPTION: " << e.what() << std::endl;
        }
        catch(...) {
            std::cerr << "EXCEPTION UNKNOWN" << std::endl;
        }
    }
    
}

#endif /* EXEPTIONHANDLING_H */

