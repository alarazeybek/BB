/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "MovieRentalSystem.h"
using namespace std;
//---------------------------------------CONSTRUCTOR & DECONSTRUCTOR--------------------------------
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

//------------------------------------REMOVE MOVIE-SUBS & ADD MOVIE---------------------------------
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

//--------------------------------------RENT & RETURN MOVIE--------------------------------------
void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId ){ 
    Node<Subscriber>* whoRent = subsList->getNodeFromId(subscriberId);
    Node<Movie>* movieFromId = movieList->getNodeFromId(movieId);
    if(movieList->isExist(movieFromId) && subsList->isExist(whoRent)){ //checking movie and subs exist
        if(movieFromId->itemptr->getLeftCount()>0){ //checking available copy exist
            movieFromId->itemptr->setLeftCount(-1);
            Movie* m = new Movie(*(movieFromId->itemptr));
            Node<Movie>* beRented = new Node<Movie>(m);
            whoRent->itemptr->rentMovie(beRented);
            Transaction* t = new Transaction(movieId,subscriberId,true);
            Node<Transaction>* trans = new Node<Transaction>(t);
            transList->insert(trans);
            return;
        }
       else{
            cout<<"no available copy";
       }
    }
    else if(!movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"no movie and no subs\n";
        return;
    }
    else if(!movieList->isExist(movieFromId) && subsList->isExist(whoRent)){
        cout<<"no movie and yes subs\n";
        return;
    }
    else if(movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"yes movie and no subs\n";
        return;
    }
}
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ){
    Node<Subscriber>* whoRent = subsList->getNodeFromId(subscriberId);
    Node<Movie>* movieFromId = movieList->getNodeFromId(subscriberId);
    if(movieList->isExist(movieFromId) && subsList->isExist(whoRent)){ //checking movie and subs exist
        Node<Movie>* temp = whoRent->itemptr->rentedList->getNodeFromId(movieId);
        if(whoRent->itemptr->rentedList->isExist(temp)){ //checking subscriber has rented that movie or not
            movieFromId->itemptr->setLeftCount(1);
            whoRent->itemptr->returnMovie(temp);
            Transaction* t = new Transaction(movieId,subscriberId,false);
            Node<Transaction>* trans = new Node<Transaction>(t);
            transList->insert(trans);
            return;
        }
       else{
            cout<<"Subs has not rented that movie";
       }
    }
    else if(!movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"no movie and no subs\n";
        return;
    }
    else if(!movieList->isExist(movieFromId) && subsList->isExist(whoRent)){
        cout<<"no movie and yes subs\n";
        return;
    }
    else if(movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"yes movie and no subs\n";
        return;
    }
}

//----------------------------------------------TO STRINGS-------------------------------------------
void showMoviesRentedBy( const int subscriberId ) { 

}
void showSubscribersWhoRentedMovie( const int movieId ) {

}

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