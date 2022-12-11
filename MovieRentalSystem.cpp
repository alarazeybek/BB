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
    //finding the ID movie
    Node<Movie>* toRemove = movieList->getNodeFromId(movieId);
    movieList->remove(toRemove); //nullptr olmasını remove methodu check eder
}
void MovieRentalSystem::addMovie( const int movieId, const int numCopies ){
    Movie* m = new Movie(movieId,numCopies);
    Node<Movie>* n = new Node<Movie>(m);
    movieList->insert(n);
}
void MovieRentalSystem::removeSubscriber( const int subscriberId ){
    Node<Subscriber>* toRemove = subsList->getNodeFromId(subscriberId);
    subsList->remove(toRemove); //nullptr olmasını remove methodu check eder
}
void rentMovie( const int subscriberId, const int movieId );
void returnMovie( const int subscriberId, const int movieId );
void showMoviesRentedBy( const int subscriberId ) const;
void showSubscribersWhoRentedMovie( const int movieId ) const;

void MovieRentalSystem::showAllMovies() const{
    cout<<"Movies in the movie rental system:"<<endl;
    if(movieList->isEmpty()){
        cout<<"None"<<endl;
    }
    else{
        Node<Movie>* temp = movieList->head;
        while(temp!=nullptr){
            cout<<temp->itemptr->getId()<<" "<<temp->itemptr->getCount()<<endl;
            temp = temp->next;
        }
    }
}
void MovieRentalSystem::showAllSubscribers() const{
    cout<<"Subscribers in the movie rental system:"<<endl;
    if(subsList->isEmpty()){
        cout<<"None"<<endl;
    }
    else{
        Node<Subscriber>* temp = subsList->head;
        while(temp!=nullptr){
            cout<<temp->itemptr->getId()<<endl;
            temp = temp->next;
        }
    }
}