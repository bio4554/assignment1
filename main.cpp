// File Name: assign1_js108.cpp
//
// Author: (Your name here, followed by collaborators, if any)
// Date: 2/3/2020
// Assignment Number: 1
// CS 2308.255 Spring 2020
// Instructor: Jill Seaman
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

    const int numFlights = 5;


    Flight flightList[100];
    int flightIndex;
    string cityChoice;

    int size = readFlights(flightList, in);
    int selection = 0;

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
                cout << "Exiting the program.";
                break;
            default:
                break;
        }
    }




    in.close();

    return 0;
}

int readFlights(Flight flightList[], ifstream &in) {
    int i = 0;
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

void printFlights(Flight flightList[], int size) {
    for(int i = 0; i < size; i++) {
        cout << fixed << left << setw(19) << flightList[i].from << setw(11) << flightList[i].to <<  setw(4)
        << flightList[i].price  << flightList[i].distance << endl;
    }
    cout << endl;
}

void printFlightsFrom(Flight flightList[], int size, string name) {
    for(int i = 0; i < size; i++) {
        if(flightList[i].from == name)
        cout << fixed << left << setw(19) << flightList[i].from << setw(11) << flightList[i].to <<  setw(4)
        << flightList[i].price  << flightList[i].distance << endl;
    }
}

void findHighestDistanceToPriceRatio(Flight flightList[], int size, int &flightIndex) {
    double ratio = 0;
    flightIndex = 0;
    for(int i = 0; i < size; i++) {
        double compare = flightList[i].distance / flightList[i].price;
        if(compare > ratio) {
            ratio = compare;
            flightIndex = i;
        }
    }
}

