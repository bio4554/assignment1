// File Name: assign1_cac575.cpp
//
// Author: Austin Childress
// Date: 2/3/2020
// Assignment Number: 1
// CS 2308.252 Spring 2020
// Instructor: Vladyslav Prokopenko
//
// (Description of what the program does goes here).

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


struct Flight {
    string from;
    string to;
    int price;
    int distance;
};

int readFlights(Flight flightList[], ifstream &in);
void printFlights(Flight flightList[], int size);
void printFlightsFrom(Flight flightList[], int size, string name);
void findHighestDistanceToPriceRatio(Flight flightList[], int size, int &flightIndex);


int main() {
    ifstream in("flights.csv");

    Flight flightList[100]; // array of flight structs
    int flightIndex; // index in array of flight with highest ratio
    string cityChoice; // user given choice of city

    int size = readFlights(flightList, in); // size of array
    int selection = 0; // user menu selection

    while(selection != 4) {
        cout << "Select the action" << endl
             << "1) Display all flights" << endl
             << "2) Show flights that depart from a given city" << endl
             << "3) Find a flight with the best distance to price ratio" << endl
             << "4) Exit the program" << endl;
            cin >> selection;
        switch (selection) {
            case 1:
                printFlights(flightList, size);
                break;
            case 2:
                cout << "Please enter the city of departure: " << endl;
                cin.ignore();
                getline(cin, cityChoice);
                cout << endl;
                printFlightsFrom(flightList, size, cityChoice);
                cout << endl;
                break;
            case 3:
                findHighestDistanceToPriceRatio(flightList, size, flightIndex);
                cout << "The best distance to price ratio is " <<
                (flightList[flightIndex].distance / flightList[flightIndex].price) << " km/$." << endl;
                cout << fixed << left << setw(19) << flightList[flightIndex].from << setw(11)
                << flightList[flightIndex].to <<  setw(4) << flightList[flightIndex].price
                << flightList[flightIndex].distance << endl << endl;
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                break;
        }
    }




    in.close();

    return 0;
}

//***********************************************************
// readFlights: Reads flights from the file
//
// flightList: Flight array
// in: Input file
// returns: Returns size of array
// ***********************************************************

int readFlights(Flight flightList[], ifstream &in) {
    int i = 0; // iterator
    while(getline(in, flightList[i].from, ',')) {
        getline(in, flightList[i].to, ',');
        string price;
        getline(in, price, ',');
        flightList[i].price = stoi(price);
        string distance;
        getline(in, distance);
        flightList[i].distance = stoi(distance);
        i++;
    }
    return i;
}

//***********************************************************
// printFlights: Prints flights
//
// flightList: Flight array
// size: Size of array
// ***********************************************************

void printFlights(Flight flightList[], int size) {
    for(int i = 0; i < size; i++) {
        cout << fixed << left << setw(19) << flightList[i].from << setw(11) << flightList[i].to <<  setw(4)
        << flightList[i].price  << flightList[i].distance << endl;
    }
    cout << endl;
}

//***********************************************************
// printFlightsFrom: Prints flights from given city
//
// flightList: Flight array
// size: Size of array
// name: Name of city to print flights
// ***********************************************************

void printFlightsFrom(Flight flightList[], int size, string name) {
    for(int i = 0; i < size; i++) {
        if(flightList[i].from == name)
        cout << fixed << left << setw(19) << flightList[i].from << setw(11) << flightList[i].to <<  setw(4)
        << flightList[i].price  << flightList[i].distance << endl;
    }
}

//***********************************************************
// findHighestDistanceToPriceRatio: Finds the flight with the best distance to price ratio
//
// flightList: Flight array
// size: Size of array
// flightIndex: Index of flight with best ratio, changes in the function
// ***********************************************************

void findHighestDistanceToPriceRatio(Flight flightList[], int size, int &flightIndex) {
    double ratio = 0; // ratio
    flightIndex = 0; // index of best ratio
    for(int i = 0; i < size; i++) {
        double compare = flightList[i].distance / flightList[i].price;
        if(compare > ratio) {
            ratio = compare;
            flightIndex = i;
        }
    }
}

