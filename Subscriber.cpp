/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "Subscriber.h"
using namespace std;

Subscriber::Subscriber(int newid){
    id = newid;
}
int Subscriber::getId(){
    return id;
}
void Subscriber::setId(int& newid){
    id = newid;
}