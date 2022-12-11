/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "Movie.h"
using namespace std;

Movie::Movie(int newid, int newcount){
    id = newid;
    count = newcount;
}
int Movie::getId(){
    return id;
}
int Movie::getCount(){
    return count;
}
void Movie::setId(int& newid){
    id = newid;
}


void Movie::setCount(int& diff){
    count += diff;
}