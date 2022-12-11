/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include "Movie.h"
#include "Subscriber.h"
#include "Transaction.h"
#include "string"
using namespace std;


template <class ItemType>
class LinkedList
{
private:
   Node<ItemType> *head = nullptr;
   int nodeNumber;
public:
    LinkedList<ItemType>();
    ~LinkedList<ItemType>();
    bool isEmpty();
    bool isExist(Node<ItemType>*& n);
    int getLength();
    void insert(Node<ItemType>* n);
    void remove(Node<ItemType>*& n);
    ItemType* getItem(int index);
    Node<ItemType>* getNodeFromId(int id);
    int compareIDs(Node<ItemType>* n1, Node<ItemType>* n2);
};

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
void LinkedList<ItemType>::insert(Node<ItemType>* n){ 
    if(isExist(n)){
        delete n; //TODO : error verebilir. List e eklenmezse silinmez ve leak verir //siliyor ve ram loc basıyor
        cout<<"already exists, cannot insert. "<<endl;
        return;
    } 
    else if(head == nullptr){ //empty list
        head = n;
        nodeNumber++;
        return;
    }
    else if(compareIDs(n,head)<0){ //n is the smallest ID
        n->next = head;
        head = n;
        nodeNumber++;
        return;
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
        return;
    }
}
//------------------------------------------------REMOVE NODE---------------------------------------------------------------
template <class ItemType>
void LinkedList<ItemType>::remove(Node<ItemType>*& n){
    if(isEmpty()){
        cout<<"There are no element to remove in the list"<<endl;
        delete n;
        return;
    }
    else if(!isExist(n)){
        cout<<"Element to remove cannot be found in the list"<<endl;
        delete n;
        return;
    }
    else if(compareIDs(head,n) == 0){//first element
        Node<ItemType>* right = head->next;
        delete head;
        nodeNumber--;
        head = right;
        n = nullptr;
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
        return;
    }
}
//create a remove method which took a index and deleted that one


//------------------------------------------------HELPER METHODS-----------------------------------------------------------
template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeFromId(int id){
    return nullptr;
}
template <>
Node<Movie>* LinkedList<Movie>::getNodeFromId(int id){
    Node<Movie> *temp = head;
    while(temp!=nullptr){
        if(temp->itemptr->getId() == id){
            return temp;
        }
        temp = temp->next;
    }
    //cout<<"Id cannot be found in the list!\n";
    return nullptr;
}
template <>
Node<Subscriber>* LinkedList<Subscriber>::getNodeFromId(int id){
    Node<Subscriber> *temp = head;
    while(temp!=nullptr){
        if(temp->itemptr->getId() == id){
            return temp;
        }
        temp = temp->next;
    }
    //cout<<"Id cannot be found in the list!\n";
    return nullptr;
}
template <class ItemType>
bool LinkedList<ItemType>::isExist(Node<ItemType>*& n){
    Node<ItemType>* temp = head;
    if(n == nullptr){
        return 0;
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
//-----------------------------------------COMPARE IDS-------------------------------------------
template <class ItemType>
int LinkedList<ItemType>::compareIDs(Node<ItemType>* n1, Node<ItemType>* n2){
    return -666;
}
template <>
int LinkedList<Movie>::compareIDs(Node<Movie>* n1, Node<Movie>* n2){
    if(n1->itemptr->getId() ==  n2->itemptr->getId()){
        return 0;
    }
    else if(n1->itemptr->getId() >  n2->itemptr->getId()){
        return 1;
    }
    else if(n1->itemptr->getId() <  n2->itemptr->getId()){
        return -1;
    }
//    May  need to delete here as well
    return -666;
}
template <>
int LinkedList<Subscriber>::compareIDs(Node<Subscriber>* n1, Node<Subscriber>* n2){
    if(n1->itemptr->getId() ==  n2->itemptr->getId()){
        return 0;
    }
    else if(n1->itemptr->getId() >  n2->itemptr->getId()){
        return 1;
    }
    else if(n1->itemptr->getId() <  n2->itemptr->getId()){
        return -1;
    }
//    May  need to delete here as well
    return -666;
}
#endif
