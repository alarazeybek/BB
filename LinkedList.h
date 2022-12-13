/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
//#include "Node.h"
#include "Movie.h"
//#include "Subscriber.h"
#include "Transaction.h"
#include "string"
using namespace std;

//-------------------------------------NODE----------------------

template <class ItemType>
struct Node{
    public:
    ItemType* itemptr = nullptr;
    Node* next = nullptr;
    Node(){
        itemptr = nullptr;
        next = nullptr;
    };
    Node( const Node<ItemType>& n){
        ItemType* i = new ItemType;
        itemptr = n->itemptr;
        next = nullptr;
    };
    ~Node(){
        delete itemptr;
        next = nullptr;
    };
    Node(ItemType* data){
        itemptr = data;
        next = nullptr;
    };
};

//---------------------------------------------------------------
template <class ItemType>
class LinkedList
{
private:
   int nodeNumber;
public:
    Node<ItemType> *head = nullptr;

    LinkedList<ItemType>();
    ~LinkedList<ItemType>();
    bool isEmpty();
    bool isExist(Node<ItemType>*& n);
    int getLength();
    bool insert(Node<ItemType>* n);
    bool remove(Node<ItemType>*& n);
    ItemType* getItem(int index);
    Node<ItemType>* getNodeFromId(int id);
    int compareIDs(Node<ItemType>* n1, Node<ItemType>* n2);
};
#endif
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
class Subscriber{
    private:
        int id;
    public:
        LinkedList<Movie> *rentedList = nullptr;

        Subscriber(int newid);
        ~Subscriber();
        void rentMovie(Node<Movie>* n);
        void returnMovie(Node<Movie>* n);
        int getId();
        void setId(int& newid);
};
#endif
template <>
int LinkedList<Movie>::compareIDs(Node<Movie>* n1, Node<Movie>* n2);
template <>
int LinkedList<Subscriber>::compareIDs(Node<Subscriber>* n1, Node<Subscriber>* n2);
template <>
int LinkedList<Transaction>::compareIDs(Node<Transaction>* n1, Node<Transaction>* n2);
template <>
Node<Transaction>* LinkedList<Transaction>::getNodeFromId(int id);
template <>
Node<Movie>* LinkedList<Movie>::getNodeFromId(int id);
template <>
Node<Subscriber>* LinkedList<Subscriber>::getNodeFromId(int id);
template<>
bool LinkedList<Transaction>::insert(Node<Transaction>* n);

//-----------------------------------------------------CONSTRUCTOR & DESTRUCTOR----------------------------------------
template <class ItemType>
LinkedList<ItemType>::LinkedList(){
    head = nullptr;
    nodeNumber = 0;
}
template <class ItemType>
LinkedList<ItemType>::~LinkedList(){
    /* while(head != nullptr){
        remove(head);
    } */
        if(head != nullptr){
                Node<ItemType>* ptr = head;
                while(ptr != nullptr){
                        Node<ItemType>* temp = ptr->next;
                        delete ptr;
                        ptr = temp;
                }
                head = nullptr;
        }

}
//-------------------------------------------------ADD NODE----------------------------------------------------------------
template <class ItemType>
bool LinkedList<ItemType>::insert(Node<ItemType>* n){ 
    if(isExist(n)){
        delete n; //TODO : error verebilir. List e eklenmezse silinmez ve leak verir //siliyor ve ram loc basıyor
        //cout<<"already exists, cannot insert. "<<endl;
        return false;
    } 
    else if(head == nullptr){ //empty list
        head = n;
        nodeNumber++;
        return true;
    }
    else if(compareIDs(n,head)<0){ //n is the smallest ID
        n->next = head;
        head = n;
        nodeNumber++;
        return true;
    }
    else{
        Node<ItemType>* left = head;
        Node<ItemType>* right = head->next;
        while(right != nullptr && compareIDs(n,right)>0){
            left = right;
            right = right->next;
        }
        left->next = n;
        n->next = right;
        nodeNumber++;
        return true;
    }
}
//------------------------------------------------REMOVE NODE---------------------------------------------------------------
template <class ItemType>
bool LinkedList<ItemType>::remove(Node<ItemType>*& n){
    if(isEmpty()){
       // cout<<"There are no element to remove in the list"<<endl;
        delete n;
        return false;
    }
    else if(!isExist(n)){
       // cout<<"Element to remove cannot be found in the list"<<endl;
        delete n;
        return false;
    }
    else if(compareIDs(head,n) == 0){//first element
        Node<ItemType>* right = head->next;
        delete head;
        nodeNumber--;
        head = right;
        n = nullptr;
        return true;
    }
    else{
        Node<ItemType>* left = head;
        while(left->next != nullptr && left->next != n){
            left = left->next;
        }
        Node<ItemType>* right = left->next->next;
        delete left->next;
        nodeNumber--;
        left->next = right;
        n = nullptr;
        return true;
    }
}
//create a remove method which took a index and deleted that one

//------------------------------------------------HELPER METHODS-----------------------------------------------------------
template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeFromId(int id){
    return nullptr;
}
template <class ItemType>
bool LinkedList<ItemType>::isExist(Node<ItemType>*& n){
    Node<ItemType>* temp = head;
    if(n == nullptr){
        return false;
    }
    while(temp!=nullptr){
        if(compareIDs(temp,n) == 0){
            return true;
        }
        temp = temp->next;
    }
    return false;
    delete n;
}
template <class ItemType>
ItemType* LinkedList<ItemType>::getItem(int index){
    bool valid = (index<=nodeNumber) && (index>0);
    if(valid){
        Node<ItemType>* temp = head;
        while(temp!=nullptr && temp->next != nullptr && index > 1){
                temp = temp->next;
                index--;
        }
        return temp->itemptr;
    }
    cout<<"No item in the specified index";
    return nullptr;
}
template <class ItemType>
bool LinkedList<ItemType>::isEmpty(){
    return head == nullptr;
}
template <class ItemType>
int LinkedList<ItemType>::getLength(){
    return nodeNumber;
}
template <class ItemType>
int LinkedList<ItemType>::compareIDs(Node<ItemType>* n1, Node<ItemType>* n2){
    return -666;
}