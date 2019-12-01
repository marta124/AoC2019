#include "Utilities.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

std::vector<std::string> parseFile(std::string path)
{
	std::vector<std::string> lines;
	a
	ifstream file(path);
	if (file.is_open()) {
		string line;
		while (getline(file, line))
		{
			lines.push_back(line);
		}
	}

	file.close();

	return lines;
}
