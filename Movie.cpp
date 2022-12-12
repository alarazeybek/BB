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
    LeftCount = count;
}
Movie::Movie(const Movie& aMovie){
    id = aMovie.id;
    count = aMovie.count;
}
int Movie::getId(){
    return id;
}
int Movie::getCount(){
    return count;
}
int Movie::getLeftCount(){
    return LeftCount;
}
void Movie::setId(int& newid){
    id = newid;
}
void Movie::setLeftCount(int diff){
    LeftCount+=diff;
}

void Movie::setCount(int& diff){
    count += diff;
}