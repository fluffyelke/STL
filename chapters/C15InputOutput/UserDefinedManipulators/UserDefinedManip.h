/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserDefinedManip.h
 * Author: default
 *
 * Created on August 31, 2022, 1:49 PM
 */

#ifndef USERDEFINEDMANIP_H
#define USERDEFINEDMANIP_H

#include <istream>
#include <limits>


namespace C15UDManip {
    //manipulator that ignore all characters until the end of the line
    template<typename charT, typename traits>
    std::basic_istream<CharT, traits>& ignoreLine(std::basic_istream<charT, traits>& strm) {
        // skip until the end of the line
        strm.ignore(std::numeric_limits<std::streamsize>::max(), strm.widen('\n'));
        
        //return strm for concatenation
        return strm;
    } 
    
    
    //other way to write manipulators
    //the following class ignore n lines from the stream
    class IgnoreLines {
    private:
        int num;
    public:
        explicit IgnoreLine(int n = 1) : num(n) {}
        
        
        template<typename charT, typename trairts>
        friend std::basic_istream<charT, traits>& operator >> (std::basic_stream<charT, traits>& strm, const IgnoreLine& ign) {
            // skip until end of num lines
            for(int i = 0; i < ign.num; ++i) {
                strm.ignore(std::numeric_limits<std::streamsize>::max(), strm.widen('\n'));
            }
            
            //return stream for concatenation
            return strm;
        }
    };
}

#endif /* USERDEFINEDMANIP_H */

