/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <memory>
#include <set>
#include <deque>
#include <algorithm>

#include "RefSemantic.h"


namespace C07Containers {

    Item::Item(const std::string& n, float p) 
        : name{n},
          price{p} {

    }

    void Item::setName(const std::string& n) {
        name = n;
    }

    std::string Item::getName() const {
        return name;
    }

    void Item::setPrice(const float& p) {
        price = p;
    }

    float Item::getPrice() const {
        return price;
    }

    
    void testRefSemantic() {
        //two different collections sharing Items
        using ItemPtr = std::shared_ptr<Item>;
        
        std::set<ItemPtr> allItems;
        std::deque<ItemPtr> bestSellers;
        
        //insert objects into collections
        //-bestsellers are in both collections
        bestSellers = {
            ItemPtr(new Item("Kong Yize", 20.10)),
            ItemPtr(new Item("A Midsummer Night's Dream", 14.99)),
            ItemPtr(new Item("The Maltese Falcon", 9.88))
        };
        
        allItems = {
            ItemPtr(new Item("Water", 0.44)),
            ItemPtr(new Item("Pizza", 2.22))
        };
        allItems.insert(bestSellers.begin(), bestSellers.end());
        
        //print contents of both collections
        printItems("bestsellers: ", bestSellers);
        printItems("allItems: ", allItems);
        std::cout << std::endl;
        
        //double price of bestsellers
        std::for_each(bestSellers.begin(), bestSellers.end(),
                    [](std::shared_ptr<Item>& elem) {
                        elem->setPrice(elem->getPrice() * 2);
                    }); 
                    
        //replace second bestseller Item by first Item with name "Pizza"
        bestSellers[1] = *(std::find_if(allItems.begin(), allItems.end(),
                                        [](std::shared_ptr<Item> elem) {
                                            return elem->getName() == "Pizza";
                                        }));
        //set price of first bestseller
        bestSellers[0]->setPrice(44.77);
        
        //print contents of both collections
        printItems("bestsellers: ", bestSellers);
        printItems("allItems: ", allItems);
    }
}