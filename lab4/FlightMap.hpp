//
//  FlightMap.hpp
//  hw4
//
//  Created by Bora Haliloglu on 19.12.2022.
//

#ifndef FlightMap_hpp
#define FlightMap_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <list>
#include <cassert>
#include <stack>
using namespace std;
struct Flight;

class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity );
    map<int,Flight>::iterator operator=(const map<int, Flight>);

 private:
    bool findTheFirstUnvisitedFligthFor(const string deptCity, Flight* &fptr);
    void displayAdjacentCitiesHelper(const string cityName) const;
    map<string, int> cityIdAndNames; // to get either the city name from id and visa versa
    vector<string> citiesVector; //the name of the city with a given id can be obtained from the vector,
    map<int, Flight*> allFlights;
    vector<list<string>> adjacentVectorList; // The flight graph must be stored using adjacency lists
    string getNextCity(string city, int index);
    void unVisitAll();
    bool isContainFlight(string des, stack<Flight> stk);
    void toStringFlight(stack<Flight> stk,int& cost, map<int, string> &aMap);
    bool copyStack(stack<Flight> &to, stack<Flight> from);
    bool momoryChange(int id, bool visited);
   // void help
   string print(map<int, string> print);
    
    
    
    
    
    int getFlightCount(string city, int flightCount);
};

struct Flight{
    string fromCity;
    string toCity;
    int id;
    int cost;
    bool visited;
};
//#include "FlightMap.cpp"
#endif /* FlightMap_hpp */
