//
//  main.cpp
//  hw4
//
//  Created by Bora Haliloglu on 28.12.2022.
//

#include <stdio.h>
#include "FlightMap.hpp"
int main() {
    FlightMap fm( "cityFile.txt", "flightFile.txt" );
    fm.displayAllCities();
    cout << endl;
    fm.displayAdjacentCities( "W" );
    cout << endl;
    fm.displayAdjacentCities( "X" );
    cout << endl;
    fm.displayFlightMap();
    cout << endl;
    fm.findFlights( "W", "Z" );
    cout << endl;
   fm.findFlights( "S", "P" );
    cout << endl;
    fm.findFlights( "Y", "Z" );
    cout << endl;
    fm.findFlights( "P", "Z" );
    cout << endl;
    
    return 0;
}
