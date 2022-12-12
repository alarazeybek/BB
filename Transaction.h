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
        string lable;
        bool rent;
    public:
        Transaction(int movieID, int SubsID,bool isRent);
        int getMovie();
        int getSubscriber();
        bool getRent();
        string getLabel();
};
#endif