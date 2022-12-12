/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "string"
#include "Node.h"
#include "Movie.h"
//#include "Subscriber.h"
#include "Transaction.h"
using namespace std;


template <class ItemType>
class Node{
    public:
    ItemType* itemptr = nullptr;
    Node* next = nullptr;
    Node();*//*{
        itemptr = nullptr;
        next = nullptr;
    };
    */
    /*Node( const Node<ItemType>& n);{
        ItemType* i = new ItemType;
        itemptr = n->itemptr;
        next = nullptr;
    };*/
    //~Node();
    /*{
        delete itemptr;
        next = nullptr;
    };
    */
   // Node(ItemType* data);
   /*{
        itemptr = data;
        next = nullptr;
    };*/

/*
template <>
Node<Movie>::Node( const Node<Movie>& n);
template <>
Node<Transaction>::Node( const Node<Transaction>& n);
 
#endif */