/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
#include "Movie.h"
#include "Subscriber.h"
#include "Transaction.h"
using namespace std;
//typedef Movie ItemType;

int main() {
    Movie* m = new Movie(133,5);
    Node<Movie>* tm = new Node<Movie>(m);
    
    Movie* k = new Movie(44,1);
    Node<Movie>* km = new Node<Movie>(k);
    
    Movie* z = new Movie(1,500);
    Node<Movie>* zm = new Node<Movie>(z);
    
    Movie* d = new Movie(43,1);
    Node<Movie>* dm = new Node<Movie>(d);
    
    Movie* b = new Movie(300,4);
    Node<Movie>* bm = new Node<Movie>(b);

    LinkedList<Movie> *dene = new LinkedList<Movie>(); //3 ile aynı, 4
    dene->insert(tm); //uninitiliazed value 3
    dene->insert(km);
    dene->insert(zm);
    dene->insert(dm);
    dene->insert(bm);

int length = dene->getLength();
   cout<<"First length: "<<length<<"\n";

    while(length > 0){
        cout<< dene->getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";

    dene->remove(tm);
    length = dene->getLength();
    cout<<"Second length: "<<length<<"\n";
    while(length > 0){
        cout<<dene->getItem(length)->getId()<<endl; //1
        length--; //2
    }
    Movie* m1 = new Movie(133,5);
        Node<Movie>* tm1 = new Node<Movie>(m1);
cout<<"IS tm Exist. Expected output:" << false<< "my output: "<<dene->isExist(tm1)<<endl;
    dene->remove(tm1);
 /*   length = dene->getLength();
    cout<<"Third length: "<<dene->getLength()<<"\n";
    while(length > 0){
        cout<<dene->getItem(length)->getId()<<endl;
 length--;
    }
    cout<<"--------end---------\n";

    dene->remove(bm);
    dene->remove(zm);
    length = dene->getLength();
    cout<<"Fourth length: "<<dene->getLength()<<"\n";
    while(length > 0){
        cout<<dene->getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";

    dene->remove(km);
    dene->remove(dm);
    length = dene->getLength();
    cout<<"Fifth length: "<<dene->getLength()<<"\n";
    while(length > 0){
        cout<<dene->getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";
    delete dene;

/*    Movie* m = new Movie(133,5);
    Node<Movie>* tm = new Node<Movie>(m);
    Movie* k = new Movie(44,1);
    Node<Movie>* km = new Node<Movie>(k);
    Movie* z = new Movie(1,500);
    Node<Movie>* zm = new Node<Movie>(z);
    Movie* d = new Movie(43,1);
    Node<Movie>* dm = new Node<Movie>(d);
    Movie* b = new Movie(300,4);
    Node<Movie>* bm = new Node<Movie>(b);

    LinkedList<Movie> *dene = new LinkedList<Movie>();
    dene->insert(tm);
    dene.insert(km);
    dene.insert(zm);
    dene.insert(dm);
    dene.insert(bm);

int length = dene->getLength();
   cout<<"First length: "<<length<<"\n";

    while(length > 0){
        cout<< dene->getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";

    dene->remove(tm);
    length = dene->getLength();
    cout<<"Second length: "<<length<<"\n";
    while(length > 0){
        cout<< dene->getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";
/*
    dene.remove(tm);
    length = dene.getLength();
    cout<<"Third length: "<<dene.getLength()<<"\n";
    while(length > 0){
        cout<<dene.getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";

    dene.remove(bm);
    dene.remove(zm);
 length = dene.getLength();
    cout<<"Fourth length: "<<dene.getLength()<<"\n";
    while(length > 0){
        cout<<dene.getItem(length)->getId()<<endl;
        length--;
    }
    cout<<"--------end---------\n";

    dene.remove(km);
    dene.remove(dm);
    length = dene.getLength();
    cout<<"Fifth length: "<<dene.getLength()<<"\n";
    while(length > 0){
        cout<<dene.getItem(length)->getId()<<endl;
        length--;
    }
*/
    cout<<"--------end---------\n";
    /*
    delete km;
    delete zm;
    delete dm;
    delete bm;
     */
    delete dene;
}

