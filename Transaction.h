/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "string"
using namespace std;

class Transaction{
    private:
        int mID;
        int sID;
    public:
        Transaction(int movieID, int SubsID);
        int getMovie();
        int getSubscriber();
        string getLabel();
};
#endif