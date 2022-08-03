/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ratio.h
 * Author: default
 *
 * Created on July 29, 2022, 2:40 PM
 */

#ifndef RATIO_H
#define RATIO_H

#include <cstdint>


namespace Ratio {
    template<std::intmax_t N, std::intmax_t D = 1>
    class MyRatio {
        public:
//            typedef MyRatio<num, den> type;
            static constexpr std::intmax_t num{};
            static constexpr std::intmax_t den{};
    };
    
    extern void testRatio();
}

#endif /* RATIO_H */

