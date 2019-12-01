#include "Day1.h"
#include "Utilities.h"

#include <iostream>

using namespace std;

void mainDay1()
{
	vector<string> lines = parseFile("Day1.txt");
	vector<int> modules;

	for (string line : lines)
	{
		modules.push_back(atoi(line.c_str()));
	}

	int allFuel = calculateAllFuel(modules);
	cout << "Needed fuel is " << allFuel << "\n";

	int allFuelWithMass = calculateAllFuelWithMass(modules);
	cout << "Needed fuel with fuel mass is " << allFuelWithMass << "\n";
}

int calculateAllFuel(std::vector<int> modules)
{
	int sum = 0;

	for (int module : modules) {
		sum += calculateFuelNeeded(module);
	}

	return sum;
}

int calculateAllFuelWithMass(std::vector<int> modules)
{
	int sum = 0;

	for (int mass : modules) {
		sum += calculateFuelWithMass(calculateFuelNeeded(mass));
	}

	return sum;
}

int calculateFuelNeeded(int mass)
{
	return (int) floor(mass / 3.0f) - 2;
}

int calculateFuelWithMass(int mass)
{
	int needed = calculateFuelNeeded(mass);
	int extra = needed <= 0 ? 0 : calculateFuelWithMass(needed);
	return mass + extra;
}

