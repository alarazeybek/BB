/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "MovieRentalSystem.h"
using namespace std;

MovieRentalSystem::MovieRentalSystem( const string movieInfoFileName,
const string subscriberInfoFileName ){
    movieList = new LinkedList<Movie>();
    subsList = new LinkedList<Subscriber>();
    transList = new LinkedList<Transaction>();
}
MovieRentalSystem::~MovieRentalSystem(){
    delete movieList;
    delete subsList;
    delete transList;
}
void MovieRentalSystem::removeMovie( const int movieId ){
    
}
