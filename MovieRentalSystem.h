/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef MOVIERNRENTALSYSTEM_H
#define MOVIERNRENTALSYSTEM_H
#include <iostream>
#include "Node.h"
#include "Movie.h"
#include "Subscriber.h"
#include "Transaction.h"
#include "LinkedList.h"
using namespace std;


class MovieRentalSystem {
    private:
        LinkedList<Movie> *movieList = nullptr;
        LinkedList<Subscriber> *subsList = nullptr;
        LinkedList<Transaction> *transList = nullptr;

    public:
        MovieRentalSystem( const string movieInfoFileName,
        const string subscriberInfoFileName );
        ~MovieRentalSystem();
        void removeMovie( const int movieId );
        void addMovie( const int movieId, const int numCopies );
        void removeSubscriber( const int subscriberId );
        void rentMovie( const int subscriberId, const int movieId );
        void returnMovie( const int subscriberId, const int movieId );
        void showMoviesRentedBy( const int subscriberId ) const;
        void showSubscribersWhoRentedMovie( const int movieId ) const;
        void showAllMovies() const;
        void showAllSubscribers() const;
};
#endif