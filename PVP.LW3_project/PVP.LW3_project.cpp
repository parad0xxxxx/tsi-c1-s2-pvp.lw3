#include <windows.h>
#include <time.h>

#include <iostream>
#include <iomanip>
#include <random>

const std::string INT_EXPECTED_ERROR = "Integer number expected ;)";
const int g_arrayIndexSize = 4, g_arraySize = 4, g_randRangeFrom = -10, g_randRangeTo = 10;

void setConsoleColor(int);
void logInfo(std::string, std::string);
int** createArray();
void showArray(int**);
void mersennizeArray(int**);
void sumArrays(int**, int**, int**);
void killArray(int**);
void SumMatr();
void calcIntergers();
void checkNegative(int);
int sumIntergers(int, int);
int sumIntergers(int*, int*);
void recursionFibonacci();
int fibonacci(int);

int main()
{
	setConsoleColor(9);
	std::cout << "Variant ";
	setConsoleColor(15);
	std::cout << "8";
	setConsoleColor(9);
	std::cout << ".\n\n";

	SumMatr();
	calcIntergers();
	recursionFibonacci();

	return 0;
}

void setConsoleColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
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

int** createArray()
{
	int** array = new int* [g_arrayIndexSize];

	for (int i = 0; i < g_arrayIndexSize; i++)
	{
		array[i] = new int[g_arraySize];
	}

	return array;
}

void mersennizeArray(int** array) 
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<int> distribution(g_randRangeFrom, g_randRangeTo);

	for (int i = 0; i < g_arrayIndexSize; i++)
	{
		for (int j = 0; j < g_arraySize; j++)
		{
			array[i][j] = distribution(mersenne);
		}
	}
}

void showArray(int** array)
{
	setConsoleColor(9);
	std::cout << "Matrix ";
	setConsoleColor(15);
	std::cout << array;
	setConsoleColor(9);
	std::cout << ":\n\n";

	for (int i = 0; i < g_arrayIndexSize; i++)
	{
		for (int j = 0; j < g_arraySize; j++)
		{
			if (array[i][j] < 0)
			{
				setConsoleColor(4);
				std::cout << std::right << std::setw(5) << array[i][j];
			}
			else if (array[i][j] >= 0)
			{
				setConsoleColor(2);
				std::cout << std::right << std::setw(5) << array[i][j];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	setConsoleColor(15);
}

void sumArrays(int** array1, int** array2, int** array3)
{
	setConsoleColor(9);
	std::cout << "Calculations:\n\n";

	for (int i = 0; i < g_arrayIndexSize; i++)
	{
		for (int j = 0; j < g_arraySize; j++)
		{
			array3[i][j] = array1[i][j] + array2[i][j];
			std::cout << std::right << std::setw(5);
			if (array1[i][j] < 0)
			{
				setConsoleColor(4);
				std::cout << array1[i][j];
			}
			else if (array1[i][j] >= 0)
			{
				setConsoleColor(2);
				std::cout << array1[i][j];
			}
			setConsoleColor(15);
			std::cout << " + " << std::left << std::setw(3);
			if (array2[i][j] < 0)
			{
				setConsoleColor(4);
				std::cout << array2[i][j];
			}
			else if (array2[i][j] >= 0)
			{
				setConsoleColor(2);
				std::cout << array2[i][j];
			}
			setConsoleColor(15);
			std::cout << " = " << std::left << std::setw(5);
			if (array3[i][j] < 0)
			{
				setConsoleColor(4);
				std::cout << array3[i][j];
			}
			else if (array3[i][j] >= 0)
			{
				setConsoleColor(2);
				std::cout << array3[i][j];
			}
			std::cout << "     ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	setConsoleColor(9);
	std::cout << "Result ";
}

void killArray(int** array)
{
	for (int i = 0; i < g_arrayIndexSize; i++)
		delete[] array[i];
	delete[] array;
}

void SumMatr() 
{
	setConsoleColor(15);
	std::cout << "\nTask 1";
	std::cout << ".\n-----------------------------------------------\n\n";

	int** arr1 = createArray();
	int** arr2 = createArray();
	int** arr3 = createArray();

	mersennizeArray(arr1);
	showArray(arr1);

	mersennizeArray(arr2);
	showArray(arr2);

	sumArrays(arr1, arr2, arr3);

	showArray(arr3);

	killArray(arr1);
	killArray(arr2);
	killArray(arr3);
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

void calcIntergers()
{
	int a = 0, b = 0, sum = 0;

	setConsoleColor(15);
	std::cout << "\nTask 2";
	std::cout << ".\n-----------------------------------------------\n\n";

	setConsoleColor(9);
	std::cout << "Enter the first value (";
	setConsoleColor(15);
	std::cout << "a";
	setConsoleColor(9);
	std::cout << "): ";
	setConsoleColor(15);
	std::cin >> a;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	setConsoleColor(9);
	std::cout << "Enter the second value (";
	setConsoleColor(15);
	std::cout << "b";
	setConsoleColor(9);
	std::cout << "): ";
	setConsoleColor(15);
	std::cin >> b;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	std::cout << "\n";

	setConsoleColor(9);
	std::cout << "sumIntergers(a, b) ";
	setConsoleColor(15);
	std::cout << "(by value): \n";
	checkNegative(a);
	std::cout << " + ";
	checkNegative(b);
	std::cout << " = ";
	setConsoleColor(15);
	std::cout << sumIntergers(a, b) << "\n\n";

	setConsoleColor(9);
	std::cout << "sumIntergers(&a, &b) ";
	setConsoleColor(15);
	std::cout << "(by pointer): \n";
	checkNegative(a);
	std::cout << " + ";
	checkNegative(b);
	std::cout << " = ";
	setConsoleColor(15);
	std::cout << sumIntergers(&a, &b) << "\n\n";
	
}

int sumIntergers(int a, int b)
{
	int sum = 0;
	sum = a + b;
	return sum;
}

int sumIntergers(int* a, int* b)
{
	int sum = 0;
	sum = *a + *b;
	return sum;
}

void recursionFibonacci()
{
	int counter = 0;

	setConsoleColor(15);
	std::cout << "\nTask 3";
	std::cout << ".\n-----------------------------------------------\n\n";

	setConsoleColor(9);
	std::cout << "Enter the restricting value: ";
	setConsoleColor(15);
	std::cin >> counter;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	std::cout << "\n";

	setConsoleColor(8);
	for (int i = 0; fibonacci(i) < counter; i++) {
		std::cout << fibonacci(i) << " ";
	}

	setConsoleColor(7);
	std::cout << "\n\n";
}

int fibonacci(int c)
{
	if (c == 0) {
		return 0;
	} 
	else if (c == 1) {
		return 1;
	}
	else {
		return fibonacci(c - 1) + fibonacci(c - 2);
	}
}