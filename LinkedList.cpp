/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "string"
using namespace std;

template <class ItemType>
LinkedList<ItemType>::LinkedList(){
    head = nullptr;
    nodeNumber = 0;
}
template <class ItemType>
LinkedList<ItemType>::LinkedList(ItemType data){
    head = new Node<ItemType>(data);
    nodeNumber = 1;
}
template <class ItemType>
LinkedList<ItemType>::~LinkedList(){
    clear();
    nodeNumber=0;
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
void LinkedList<ItemType>::insert( const ItemType& newEntry){
    Node<ItemType>* temp = head ;
    while(temp != nullptr && temp->next != nullptr){
        temp = temp->next;
    }
    nodeNumber++;
    temp->next = new Node<ItemType>(newEntry);
}
template <class ItemType>
void LinkedList<ItemType>::remove(const int position){return;}

template <class ItemType>
void LinkedList<ItemType>::clear(){
    while(!isEmpty()){
        Node<ItemType> *temp = head->next;
        delete head;
        nodeNumber--;
        head = temp;
    }
}

template <class ItemType>
ItemType LinkedList<ItemType>::getItem(int index){
    bool valid = (index<=nodeNumber) && (index>0);
    if(valid){
        Node<ItemType>* temp = head;
        while(temp!=nullptr && temp->next != nullptr && index > 0){
                temp = temp->next;
                index--;
        }
        return (*temp).data;
    }
}
*/
