//2_14.cpp
#include<iostream>
using namespace std;

struct aircraft
{
	int wingspan;
	int passengers;

	union
	{
		float fuel_load;
		float bomb_load;
		int pallets;
	};
} fighter, bomber, transport;

int main()
{
	fighter.wingspan = 40;
	fighter.passengers = 1;
	fighter.fuel_load = 12000.0;

	bomber.wingspan = 90;
	bomber.passengers = 12;
	bomber.bomb_load = 14000.0;

	transport.wingspan = 106;
	transport.passengers = 4;
	transport.pallets = 42;

	transport.fuel_load = 18000.0;
	fighter.pallets = 4;

	cout << "The fighter carries " << fighter.pallets << " pallets.\n";
	cout << "The bomber bomb load is " << bomber.bomb_load << "\n";
}
