#include "Day2.h"
#include "Utilities.h"
#include <iostream>
#include <sstream>

using namespace std;

void mainDay2()
{
	vector<string> lines = parseFile("Day2.txt");
	part1(lines);
	part2(lines);
}

void part1(vector<string> lines)
{
	vector<int> numbers = readNumbers(lines[0]);

	numbers[1] = 12;
	numbers[2] = 2;

	calculate(numbers);

	cout << numbers[0] << "\n";
}

void part2(vector<string> lines)
{
	bool found = false;
	int first = 0;
	int second = 0;

	for (; first <= 99; first++)
	{
		for (second = 0; second <= 99; second++)
		{
			vector<int> numbers = readNumbers(lines[0]);

			numbers[1] = first;
			numbers[2] = second;

			calculate(numbers);

			if (numbers[0] == 19690720)
			{
				found = true;
				break;
			}
		}

		if (found)
		{
			break;
		}
	}

	cout << 100 * first + second << "\n";
}

std::vector<int> readNumbers(std::string s)
{
	vector<int> numbers;

	string token;
	istringstream stream(s);

	while (getline(stream, token, ','))
	{
		numbers.push_back(atoi(token.c_str()));
	}

	return numbers;
}

void calculate(std::vector<int>& numbers)
{
	for (int i = 0; i < numbers.size() / 4; i++)
	{
		if (numbers[i * 4] == 99) {
			break;
		}
		int index1 = numbers[i * 4 + 1];
		int a = numbers[index1];
		int index2 = numbers[i * 4 + 2];
		int b = numbers[index2];
		int result = numbers[i * 4] == 1 ? a + b : a * b;

		numbers[numbers[i * 4 + 3]] = result;
	}
}
