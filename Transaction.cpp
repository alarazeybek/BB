/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(int movieID, int SubsID, bool isRent){
    mID = movieID;
    sID = SubsID;
    rent = isRent;
    if(isRent){
        lable = "Subscriber " + to_string(sID) +" rented Movie " + to_string(mID);
    }
    else{
        lable = "Subscriber " + to_string(sID) +" returned Movie " + to_string(mID);
    }
}
int Transaction::getMovie(){
    return mID;
}
int Transaction::getSubscriber(){
    return sID;
}
string Transaction::getLabel(){
    return lable;
}
bool Transaction::getRent(){
    return rent;
}