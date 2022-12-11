/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include <iostream>
#include "string"
using namespace std;

class Subscriber{
    private:
        int id;
    public:
        Subscriber(int newid);
        int getId();
        void setId(int& newid);
};
#endif