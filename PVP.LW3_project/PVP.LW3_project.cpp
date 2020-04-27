#include <windows.h>
#include <time.h>

#include <iostream>
#include <iomanip>

const std::string INT_EXPECTED_ERROR = "Integer number expected ;)";

void setConsoleColor(int);
void checkNegative(int);
void logInfo(std::string, std::string);

int main()
{
	setConsoleColor(9);
	std::cout << "Variant ";
	setConsoleColor(15);
	std::cout << "8";
	setConsoleColor(9);
	std::cout << ".\n\n";

	setConsoleColor(15);
	std::cout << "\nTask 1";
	std::cout << ".\n-----------------------------------------------\n\n";

	int arrayIndexSize = 4, arraySize = 4, randRangeFrom = -10, randRangeTo = 10;

	int** arr = new int* [arrayIndexSize];

	for (int i = 0; i < arrayIndexSize; i++)
	{
		arr[i] = new int[arraySize];
	}

	srand(time(NULL));
	for (int i = 0; i < arrayIndexSize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			arr[i][j] = rand() % (randRangeTo - randRangeFrom + 1) + randRangeFrom;
		}
	}

	setConsoleColor(9);
	std::cout << "Your array is ready and served:\n\n";

	for (int i = 0; i < arrayIndexSize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (i == j && arr[i][i] < 0)
			{
				setConsoleColor(4);
				std::cout << std::setw(5) << arr[i][j];
				setConsoleColor(15);
			}
			else if (i == j && arr[i][i] >= 0)
			{
				setConsoleColor(2);
				std::cout << std::setw(5) << arr[i][j];
				setConsoleColor(15);
			}
			else
			{
				std::cout << std::setw(5) << arr[i][j];
			}
		}
		std::cout << "\n";
	}


	for (int i = 0; i < arrayIndexSize; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}

void setConsoleColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void checkNegative(int c)
{
	if (c < 0) {
		setConsoleColor(9);
		std::cout << "(";
		setConsoleColor(15);
		std::cout << c;
		setConsoleColor(9);
		std::cout << ")";
	}
	else {
		setConsoleColor(15);
		std::cout << c;
	}
	setConsoleColor(9);
}

void logInfo(std::string loglevel, std::string log)
{
	if (loglevel == "warn") {
		setConsoleColor(4);
	}
	else {
		setConsoleColor(11);
	}

	std::cout << "\n" << log << "\n\n";
	setConsoleColor(7);
}