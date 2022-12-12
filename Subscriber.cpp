/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

Subscriber::Subscriber(int newid){
    id = newid;
    rentedList = new LinkedList<Movie>();
}
Subscriber::~Subscriber(){
    delete rentedList;
}
int Subscriber::getId(){
    return id;
}
void Subscriber::setId(int& newid){
    id = newid;
}
void Subscriber::rentMovie(Node<Movie>* n){
    rentedList->insert(n);
}
void Subscriber::returnMovie(Node<Movie>* n){
    rentedList->remove(n);
}