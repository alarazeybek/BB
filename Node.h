/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "string"
using namespace std;


template <class ItemType>
struct Node{
    ItemType* itemptr = nullptr;
    Node* next = nullptr;
    Node(){
        itemptr = nullptr;
        next = nullptr;
    }
    ~Node(){
        delete itemptr;
        next = nullptr;
    }
    Node(ItemType* data){
        itemptr = data;
        next = nullptr;
    }
};
   
#endif