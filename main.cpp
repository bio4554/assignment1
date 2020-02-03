#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct flight {
	string from;
	string to;
	int price;
	int distance;
};

int main() {
	ifstream in("flights.csv");

	const int numFlights = 5;

	flight flightList[numFlights];

	for(int i = 0; i < numFlights; i++) {
		getline(in, flightList[i].from, ',');
		getline(in, flightList[i].to, ',');
		string price;
		flightList[i].price = stoi(getline(in, price, ','));
		//getline(in, flightlist[i].distance, ',');
	}

	for(int i = 0; i < numFlights; i++) {
		cout << "Flight:" << endl
		     << "From: " << flightList[i].from << endl
		     << "To: "  << flightList[i].to << endl
		     << "Price: " << flightList[i].price << endl
		     << "Distance: " << flightList[i].distance << endl << endl << endl;
	}


	in.close();

	return 0;
}
