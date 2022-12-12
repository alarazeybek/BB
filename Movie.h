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
        int LeftCount;
    public:
        Movie(int newid, int newcount);
        Movie(const Movie& aMovie);
        int getId();
        int getCount();
        int getLeftCount();
        void setId(int& newid);
        void setCount(int& newcount); 
        void setLeftCount(int dif); 
};
#endif