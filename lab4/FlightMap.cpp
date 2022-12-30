//
//  FlightMap.cpp
//  hw4
//
//  Created by Bora Haliloglu on 19.12.2022.
//

#include "FlightMap.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <algorithm>
using namespace std;
int stringToInteger(string);
FlightMap::FlightMap(const string cityFile, const string flightFile){
    string originCity, toCity;
    string flightId, cost;
    string cityName;
    ifstream cities;
    ifstream flight;
    flight.open(flightFile);
    cities.open(cityFile);
    assert(cities && flight);
    //    flights
    //    ------------------------
    //    cities
    if(cities.is_open()){
        while(cities.eof()==false){
            getline(cities, cityName);
            if(cityName != ""){
                citiesVector.push_back(cityName); // all the cities in the map
                std::sort(citiesVector.begin(), citiesVector.end());
            }
        }
    }
    
    if(flight.is_open()){
        while(flight.eof()==false){
            getline(flight, originCity, ';');
            getline(flight, toCity, ';');
            getline(flight, flightId, ';');
            getline(flight, cost, '\n');
            cityIdAndNames.insert({originCity, stringToInteger(flightId)}); // the origin city and flight id
            Flight* newFlight = new Flight;
            newFlight->id = stringToInteger(flightId);
            newFlight->toCity = toCity;
            newFlight->fromCity = originCity;
            newFlight->cost = stringToInteger(cost);
            newFlight->visited = false;
            allFlights.insert({newFlight->id, newFlight}); // added flight to all flight map
            
//            insert adjacent city
            bool cityExist = 0;
            int cityIndex = 0;
            for(auto a = adjacentVectorList.begin(); a != adjacentVectorList.end(); ++a){
                if(a->front() == newFlight->fromCity){
                    cityExist = 1;
                    break;
                }
                cityIndex++;
            }
            cityIndex = (cityExist) ? cityIndex:-1;
            if(cityExist && cityIndex >= 0){
                adjacentVectorList.at(cityIndex).push_back(newFlight->toCity);
            }
            else{
                list<string> first;
                first.push_back(newFlight->fromCity);
                first.push_back(newFlight->toCity);
                adjacentVectorList.push_back(first);
            }
        }
    }
}
FlightMap::~FlightMap(){
    
}
void FlightMap::displayAllCities()const{
    cout << "The list of the cities that HPAir serves is given below:" <<endl;
    for(auto a = citiesVector.begin(); a != citiesVector.end(); a++){
        cout << *a << ", ";
    }
}
void FlightMap::displayAdjacentCities(const string cityName)const{
    cout  << "The cities adjacent to "<< cityName <<" are:" << endl;
    displayAdjacentCitiesHelper(cityName);
}
void FlightMap::displayAdjacentCitiesHelper(const string cityName)const{
    int index = 0;
    for(auto i = adjacentVectorList.begin(); i!=adjacentVectorList.end();++i){
        if(i->front() == cityName){
            break;
        }
        index++;
    }
    list<string>::iterator it;
    if(index >= adjacentVectorList.size()){
        cout << cityName << " -> ";
    }
    else{
        list<string> temp =adjacentVectorList.at(index);
        cout << cityName << " -> ";
        //map<string,int> tempMap;
        for(it = temp.begin(); it!=temp.end();it++){
            if(it == temp.begin()){
                continue;
            }
            //tempMap.insert(pair<string,int>(*it+", " , 0));
            cout << *it << ", ";
        }
        /*
        for(map<string,int>::iterator ala = tempMap.begin(); ala!=tempMap.end();ala++){
            if(ala == tempMap.begin()){
                continue;
            }
            cout<<ala->first;
        }*/
    }
    cout << endl;
}
void FlightMap::displayFlightMap()const{
    cout<<"The whole flight map is given below:"<<endl;
    for(auto i = citiesVector.begin(); i != citiesVector.end();++i){ //TODO : yanlis output
        displayAdjacentCitiesHelper(*i);
    }
}
void FlightMap::unVisitAll(){
    for(auto i = allFlights.begin(); i != allFlights.end();++i){
        i->second->visited = 0;
    }
}
int stringToInteger(string aStr){
    int result = 0;
    for(int a = 0; a < aStr.length(); a++){
        result = result*10 + (aStr[a] - '0');
    }
    return result;
}
void FlightMap::findFlights(const string deptCity, const string destCity){
    cout<<"Request is to fly from "+deptCity+" to "+destCity+":"<<endl;
    bool neverFoundPath = 1;
    map<int, string> sortMap;
    unVisitAll();
    stack<Flight> stk;
    Flight* fptr = nullptr;
    bool first = 1;
    bool possible = findTheFirstUnvisitedFligthFor(deptCity,fptr);
    if(possible){
        if(first){
            stk.push(*fptr);
        }
        while(possible ){
            fptr->visited = true;
            if(!first){
                stk.push(*fptr);
            }
            first = 0;
            while(!stk.empty() && fptr->toCity != destCity){
                Flight* nextFligth = nullptr;
                findTheFirstUnvisitedFligthFor(fptr->toCity, nextFligth);
                if(nextFligth == nullptr){
                    stk.pop();
                }
                else{
                    bool k = isContainFlight((*nextFligth).toCity , stk);
                    if(k){
                        nextFligth->visited = 1;
                        if(!stk.empty()){
                            while(stk.top().fromCity != (*nextFligth).toCity){
                                stk.pop();
                            }
                            if(!stk.empty()){
                                stk.pop();
                                if(!stk.empty()){
                                    fptr = &stk.top();
                                }
                            }
                        }
                            continue;
                    }
                    else{
                        stk.push(*nextFligth);
                        nextFligth->visited = 1;
                    }
                }
                if(!stk.empty()){
                    fptr = &stk.top();
                }
            }
            if(!stk.empty()){
                neverFoundPath = 0;
                int cost = 0;
                possible = 0;
                toStringFlight(stk,cost, sortMap);
                Flight memory = stk.top();
                int i = 1;
                while(!stk.empty() && !possible){
                    if(!stk.empty()){
                        if(i == 2){
                            momoryChange(memory.id, 0);
                            i = 1;
                            memory = stk.top();
                            stk.pop();
                        }
                        else if(i!=2){
                            stk.pop();
                        }
                        if(!stk.empty()){
                            possible = findTheFirstUnvisitedFligthFor(stk.top().toCity,fptr);
                            i++;
                        }
                    }
                }
            }
            if(stk.empty()){
                possible = findTheFirstUnvisitedFligthFor(deptCity,fptr);
            }
        }
        if(neverFoundPath){
            cout<< "Sorry. HPAir does not fly from "+deptCity+" to "+destCity+"."<<endl;
            return;
        }
        cout << print(sortMap);
    }
    else{
        cout<< "Sorry. HPAir does not fly from "+deptCity+" to "+destCity+"."<<endl;
    }
}
bool FlightMap::findTheFirstUnvisitedFligthFor(const string deptCity, Flight* &fptr){
    for(auto i = allFlights.begin(); i != allFlights.end(); i++){ //sonsuz loop?
        //cout<<i->second->fromCity<<"\n";
        if(i->second->fromCity == deptCity && (i->second->visited == false) ){
            fptr = i->second; //BURADA HATA
            return true;
        }
    }
    fptr = nullptr;
    return false;
}
bool FlightMap::isContainFlight(string des, stack<Flight> stk){
    while(!stk.empty()){
        if(stk.top().fromCity == des){
            stk.pop();
            //cout<<"stk empty?:  "<< stk.empty() <<endl;
            return true;
        }
        stk.pop();
    }
    //cout<<"\nislem tama stk empty?: "<< stk.empty() <<endl;
    return false;
}

void FlightMap::toStringFlight(stack<Flight> stk,int& cost, map<int, string> &storeString){
    string str = "";
    while(!stk.empty()){
        Flight f = stk.top();
        cost += f.cost;
        str = "Flight #" + to_string(f.id) + " from "+f.fromCity+ " to "+ f.toCity+ ", Cost: " + to_string(f.cost) + " TL\n" + str;
        stk.pop();
    }
    str += "Total Cost: " + to_string(cost) + " TL\n";
    storeString.insert({cost, str});
}
bool FlightMap::copyStack(stack<Flight> &to, stack<Flight> from){
    bool done = 0;
    stack<Flight> temp;
    while(!from.empty()){
        temp.push(from.top());
        from.pop();
    }
    while(!temp.empty()){
        to.push(temp.top());
        temp.pop();
    }
    return done;
}
bool FlightMap::momoryChange(int id, bool visited){
    for(auto a = allFlights.begin(); a != allFlights.end(); a++){
        if(a->second->id == id){
            a->second->visited = visited;
            return true;
        }
    }
    return false;
}
string FlightMap::print(map<int, string> print){
    string a = "";
    for(auto i = print.begin(); i!= print.end(); i++){
        a += i->second;
    }
    return a;
}
