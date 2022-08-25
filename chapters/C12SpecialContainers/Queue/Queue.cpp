/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <queue>
#include <iostream>

#include "Queue.h"


namespace C12Containers {
    
    void queueExample() {
        std::queue<std::string> q;
        
        //insert 3 elements into the queue
        q.push("These ");
        q.push("are ");
        q.push("more than ");
        
        //read and print 2 elements from the queue
        std::cout << q.front();
        q.pop();
        std::cout << q.front();
        q.pop();
        
        //insert 2 new elements
        q.push("four ");
        q.push("words!");
        
        //skip one element
        q.pop();
        
        //read and print 2 elements
        std::cout << q.front();
        q.pop();
        std::cout << q.front() << std::endl;
        q.pop();
        
        //print number of elements in the queue
        std::cout << "number of elements in the queue: " << q.size() << std::endl;
    }
    
    void priorityQueueExample() {
        std::priority_queue<float> q;
        
        //insert 3 elements into priority queue
        q.push(66.6);
        q.push(22.2);
        q.push(44.4);
        
        //read and print 2 elements from the queue
        std::cout << q.top() << ' ';
        q.pop();
        std::cout << q.top() << std::endl;
        q.pop();
        
        
        //insert 3 elements into priority queue
        q.push(11.1);
        q.push(55.5);
        q.push(33.3);
        
        //skip 1 element
        q.pop();
        
        //pop and print remaining elements
        while(!q.empty()) {
            std::cout << q.top() << ' ';
            q.pop();
        }
        std::cout << std::endl;
    }
    
}