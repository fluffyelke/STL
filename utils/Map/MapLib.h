/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapLib.h
 * Author: default
 *
 * Created on August 5, 2022, 12:09 PM
 */

#ifndef MAPLIB_H
#define MAPLIB_H

namespace Utils {
    template<typename Cont>
    inline bool replaceKey(Cont& c, 
                           const typename Cont::key_type& oldKey,
                           const typename Cont::key_type& newKey) {
        
        typename Cont::iterator pos;
        pos = c.find(oldKey);
        
        if(pos != c.end()) {
            //insert new element with value of old element
            c.insert(typename Cont::value_type(newKey, pos->second));
            
            //remove old element
            c.erase(pos);
            return true;
        }
        else {
            //key not found
            return false;
        }
    }
}

#endif /* MAPLIB_H */

