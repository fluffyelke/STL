/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stack>
#include <iostream>

#include "Stack.h"
#include "Stack.hpp"


namespace C12Containers {
    
    void stackExample() {
        std::stack<int> st;
        
        //push 3 elements into stack
        st.push(1);
        st.push(2);
        st.push(3);
        
        //pop and print 2 elements from the stack
        std::cout << st.top() << ' ';
        st.pop();
        std::cout << st.top() << ' ';
        st.pop();
        
        //modify top element
        st.top() = 77;
        
        //push two new elements
        st.push(4);
        st.push(5);
        
        //pop 1 element without processing it
        st.pop();
        
        //pop and print remaining elements
        while(!st.empty()) {
            std::cout << st.top() << ' ';
            st.pop();
        }
        std::cout << std::endl;
    }
    
    void testUserDefinedStack() {
        try {
            C11Containers::Stack<int> st;
            
            //push 3 elements into stack
            st.push(1);
            st.push(2);
            st.push(3);

            //pop and print 2 elements from the stack
            std::cout << st.top() << ' ';
            st.pop();
            std::cout << st.top() << ' ';
            st.pop();

            //modify top element
            st.top() = 77;

            //push two new elements
            st.push(4);
            st.push(5);

            //pop 1 element without processing it
            st.pop();
        
            //pop and print 3 elements
            //Error - one element to many
            std::cout << st.pop() << ' ';
            std::cout << st.pop() << std::endl;
            std::cout << st.pop() << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << "EXCEPTION: " << e.what() << std::endl;
        }
    }
    
}