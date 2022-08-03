/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IOTuples.h
 * Author: default
 *
 * Created on July 26, 2022, 1:36 PM
 */

#ifndef IOTUPLES_H
#define IOTUPLES_H

#include <ostream>
#include <tuple>


namespace Utils {
    //This operator << will not work where ADL(argument-dependent lookup) does not work.
    //helper: print element with index IDX of tuple with MAX elements
    template<int IDX, int MAX, typename... Args>
    struct PRINT_TUPLE {
        static void print(std::ostream& os, const std::tuple<Args...>& t) {
            os << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
            PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
        }
    };
    
    //partial specilization to end recursion
    template<int MAX, typename... Args>
    struct PRINT_TUPLE<MAX, MAX, Args...> {
        static void print(std::ostream& os, const std::tuple<Args...>& t) {
//            os << "\nEnd of Print Tuple, end of recursion." << std::endl;
        }
    };
    

}
//output operator for tuples
template<typename... Args>
std::ostream& operator << (std::ostream& os, const std::tuple<Args...>& t) {
    os << "[";
    Utils::PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}
#endif /* IOTUPLES_H */

