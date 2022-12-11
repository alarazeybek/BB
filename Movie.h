/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include "string"
using namespace std;

class Movie{
    private:
        int id;
        int count;
    public:
        Movie(int newid, int newcount);
        int getId();
        int getCount();
        void setId(int& newid);
        void setCount(int& newcount); 
};
#endif