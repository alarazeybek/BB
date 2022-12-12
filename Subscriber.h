/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include <iostream>
#include "string"
#include "LinkedList.h"
#include "Movie.h"
using namespace std;

class Subscriber{
    private:
        int id;
    public:
        LinkedList<Movie> *rentedList = nullptr;

        Subscriber(int newid);
        ~Subscriber();
        void rentMovie(Node<Movie>* n);
        void returnMovie(Node<Movie>* n);
        int getId();
        void setId(int& newid);
};
#endif
*/