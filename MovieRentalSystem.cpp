/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "MovieRentalSystem.h"
#include <string>
#include <fstream>
using namespace std;
//---------------------------------------CONSTRUCTOR & DECONSTRUCTOR--------------------------------
MovieRentalSystem::MovieRentalSystem( const string movieInfoFileName,
const string subscriberInfoFileName ){
    movieList = new LinkedList<Movie>();
    subsList = new LinkedList<Subscriber>();
    transList = new LinkedList<Transaction>();
    string m = movieInfoFileName;
    string s = subscriberInfoFileName;
    int begin1 = 0, begin2 = 0;
    int movieId = 0, numCount = 0, subscriberInfo = 0;
    ifstream movie;
    ifstream sub;
    movie.open(m);
    sub.open(s);
if(!movie || !sub){
        if(!movie && !sub){
            cout << "Input files " << movieInfoFileName << " and " << subscriberInfoFileName << " do not exist" << endl;
        }
        else if(!movie){
            cout << "Input file " << movieInfoFileName << " does not exist" << endl;
        }
        else{
            cout << "Input file " << subscriberInfoFileName << " does not exist" << endl;
        }
    }
    else{
        movie >> begin1;
        while(movie.eof() == false){
            movie>>movieId;
            movie>>numCount;
            Movie* tempMovie = new Movie(movieId,numCount);
            Node<Movie>* tempNode = new Node<Movie>(tempMovie);
            movieList->insert(tempNode);
        }
        sub>>begin2;
        while(sub.eof() == false){
            sub>>subscriberInfo;
            Subscriber* tempSubs = new Subscriber(subscriberInfo);
            Node<Subscriber>* tempNode = new Node<Subscriber>(tempSubs);
            subsList->insert(tempNode);
        }
        //cout<<subsList->getLength()<<" subscribers and "<<movieList->getLength()<<" movies have been loaded"<<endl;
        cout<<begin2<<" subscribers and "<<begin1<<" movies have been loaded"<<endl; 
    }
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
    int count , leftCount;
    if(toRemove!=nullptr){
        count = toRemove->itemptr->getCount();
        leftCount = toRemove->itemptr->getLeftCount();
    }
    if(toRemove != nullptr){
        if(count == leftCount){ //toRemove->itemptr->getLeftCount() == toRemove->itemptr->getCount()
            movieList->remove(toRemove);
            cout<<"Movie "<<movieId<<" has been removed"<<endl;
        }
        else{
            cout<<"Movie "<<movieId<<" cannot be removed -- at least one copy has not been returned"<<endl;
        }
    }
    else{
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
    }
}

void MovieRentalSystem::addMovie( const int movieId, const int numCopies ){
    Movie* m = new Movie(movieId,numCopies);
    Node<Movie>* n = new Node<Movie>(m);
    bool b = movieList->insert(n);
    if(b){
        cout<<"Movie "<<movieId<<" has been added"<<endl;
    }
    else{
        cout<<"Ne basacam \n";
    }
}

void MovieRentalSystem::removeSubscriber( const int subscriberId ){
    Node<Subscriber>* toRemove = subsList->getNodeFromId(subscriberId);
    bool NoRentedMovie = 0;
    if(toRemove!=nullptr){
       NoRentedMovie = toRemove->itemptr->rentedList->isEmpty();
    }
    bool b = subsList->isExist(toRemove);
    if(b){
        if(NoRentedMovie){
            subsList->remove(toRemove); //nullptr olmasını remove methodu check eder
            //butun transcriptleri silmek:
            Node<Transaction>* ptr = transList->head;
            while(ptr != nullptr){
                Node<Transaction>* temp = ptr->next;
                if(ptr->itemptr->getSubscriber() == subscriberId){
                //cout<<"6666 icin ->"<< ptr->itemptr->getLabel()<<endl;
                    transList->remove(ptr);
                }
                ptr = temp;
            }
            cout<<"Subscriber "<<subscriberId<<" has been removed"<<endl; //ta forgot endl
        }
        else{
            cout<<"Subscriber "<<subscriberId<<" cannot be removed -- at least one movie has not been returned"<<endl;
        }
    }
    else{
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
    }
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
            cout<<"Movie "<<movieId<<" has been rented by subscriber "<<subscriberId<<endl;
            return;
        }
       else{
            cout<<"Movie "<<movieId<<" has no available copy for renting"<<endl;
       }
    }
    else if(!movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
        return;
    }
    else if(!movieList->isExist(movieFromId) && subsList->isExist(whoRent)){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    else if(movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
    }
}
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ){
    Node<Subscriber>* whoRent = subsList->getNodeFromId(subscriberId);
    Node<Movie>* movieFromId = movieList->getNodeFromId(movieId);
    if(movieList->isExist(movieFromId) && subsList->isExist(whoRent)){ //checking movie and subs exist
        Node<Movie>* temp = whoRent->itemptr->rentedList->getNodeFromId(movieId);
        if(whoRent->itemptr->rentedList->isExist(temp)){ //checking subscriber has rented that movie or not
            movieFromId->itemptr->setLeftCount(1);
            whoRent->itemptr->returnMovie(temp);
            Transaction* t = new Transaction(movieId,subscriberId,false);
            Node<Transaction>* trans1 = new Node<Transaction>(t);
            transList->insert(trans1);
            //-------------------------updateTansactionForReturnedElement---------------
            Node<Transaction>* trans = transList->head;
            while(trans!=nullptr){
                if(trans->itemptr->getMovie() == t->getMovie() && trans->itemptr->getSubscriber() == t->getSubscriber() && trans->itemptr->getIsBack() == false){
                    break;
                }
                trans = trans->next;
            }
            trans->itemptr->setIsBack(true);


            cout<<"Movie "<<movieId<<" has been returned by subscriber "<<subscriberId<<endl;
            return;
        }
       else{
            cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
       }
    }
    else if(!movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
        return;
    }
    else if(!movieList->isExist(movieFromId) && subsList->isExist(whoRent)){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    else if(movieList->isExist(movieFromId) && !subsList->isExist(whoRent)){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
    }
}

//----------------------------------------------TO STRINGS-------------------------------------------
//TODO ornek file da const functionlar deneme icin const yazilarini sildim
void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) { 
    Node<Subscriber>* subs = subsList->getNodeFromId(subscriberId);
    if(subs == nullptr){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
    }
    else if(subs->itemptr->rentedList->getLength() == 0){
        cout<<"Subscriber "<<subscriberId<<" has not rented any movies"<<endl;
        return;
    }
    cout<<"Subscriber "<<subscriberId<<" has rented the following movies:\n";
    Node<Transaction>* temp = transList->head;
    while(temp != nullptr){
        if(temp->itemptr->getSubscriber() == subscriberId){
            if(temp->itemptr->getRent()){
                if(temp->itemptr->getIsBack()){
                    cout<<temp->itemptr->getMovie()<<" returned"<<endl;
                }
                else{
                    cout<<temp->itemptr->getMovie()<<" not returned"<<endl;
                }
            }
        }
        temp = temp->next;
    }
    /*Node<Transaction>* temp = transList->head;
    Node<Movie>* temp2 = subs->itemptr->rentedList->head;
    while(temp!=nullptr){
        if(temp->itemptr->getSubscriber() == subscriberId){
            bool b = temp->itemptr->getRent();
            if(!b){//returning
                if(temp->itemptr->getMovie() >= temp2->itemptr->getId()){
                    cout<< temp->itemptr->getMovie() << "returned"<<endl;
                    temp = temp->next;
                }
                else if (temp->itemptr->getMovie() < temp2->itemptr->getId()){
                    cout<< temp2->itemptr->getId() << " not returned"<<endl;
                    temp2 = temp2->next;
                }
            }
        }
        
    }*/
    /*Node<Subscriber>* subs = subsList->getNodeFromId(subscriberId);
    if(subs == nullptr){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
    }
    else if(subs->itemptr->rentedList->getLength() == 0){
        cout<<"Subscriber "<<subscriberId<<" has not rented any movies"<<endl;
        return;
    }
    else{
        cout<<"Subscriber "<<subscriberId<<" has rented the following movies:\n"; //trans arrayi geç eğer bool true ise subs->rented arrayinde de exist is not returned bas değilse returned bas
        Node<Transaction>* trans = transList->head;
        while(trans != nullptr){
            if(trans->itemptr->getSubscriber() == subscriberId && trans->itemptr->getRent()){
                Node<Movie>* notReturned = subs->itemptr->rentedList->getNodeFromId(trans->itemptr->getMovie());
                if(subs->itemptr->rentedList->isExist(notReturned)){
                    cout<<trans->itemptr->getMovie()<<" not returned"<<endl;
                }
                else{
                    cout<<trans->itemptr->getMovie()<<" returned"<<endl;
                }
            }
            trans = trans->next;
        }
    }*/
}
void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) {
    
    Node<Movie>* movie = movieList->getNodeFromId(movieId);
    if(movie == nullptr){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    Node<Transaction>* temp = transList->head;
    bool isExist = false;
    while(temp != nullptr){
        if(temp->itemptr->getMovie() == movieId){
            isExist = true;
            break;
        }
        temp = temp->next;
    }
    if(isExist){
        cout<<"Movie "<<movieId<<" has been rented by the following subscribers:"<<endl;
        temp = transList->head;
        while(temp != nullptr){
            if(temp->itemptr->getMovie() == movieId){
                if(temp->itemptr->getRent() == true){
                    if(temp->itemptr->getIsBack() == true){
                        cout<<temp->itemptr->getSubscriber()<<" returned"<<endl;
                    }
                    else{
                        cout<<temp->itemptr->getSubscriber()<<" not returned"<<endl;
                    }
                }
            }
            temp = temp->next;
        }
    }
    else{
        cout<<"Movie "<<movieId<<" has not been rented by any subscriber"<<endl;
    }
   

    

}

void MovieRentalSystem::showAllMovies() {
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
void MovieRentalSystem::showAllSubscribers() {
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
void MovieRentalSystem::showTransactions(){
    cout<<  "Transactions\n";
    Node<Transaction>* ptr = transList->head;
    while(ptr!=nullptr){
        cout<<ptr->itemptr->getLabel()<<endl;
        ptr = ptr->next;
    }
}
