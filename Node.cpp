/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3


#include <iostream>
#include "Node.h"

using namespace std;

    template <class ItemType>
    Node<ItemType>::Node(){
        data = NULL;
        next = nullptr;
    }
    
    template <class ItemType>
    Node<ItemType>::~Node(){
        delete data;
        next = nullptr;
    }
    template <class ItemType>
    Node<ItemType>::Node( ItemType* data){
        Node<ItemType>::data = data;
        next = nullptr;
    }*/
    /*
    template <class ItemType>
    Node<ItemType>::Node( const Node<ItemType>& n){
        ItemType* i = new ItemType;
        itemptr = n->itemptr;
        next = nullptr;
    }
    
    template <class ItemType>
    Node<ItemType>::Node( ItemType* data, Node<ItemType>* nextItem){
        Node<ItemType>::data = data;
        next = nextItem;
    }
    */
    