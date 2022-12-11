/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(int movieID, int SubsID){
    mID = movieID;
    sID = SubsID;
}
int Transaction::getMovie(){
    return mID;
}
int Transaction::getSubscriber(){
    return sID;
}
string Transaction::getLabel(){
    string str = "Subscriber " + to_string(sID) +" rented Movie " + to_string(mID);
    return str;
}