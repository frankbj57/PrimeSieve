// PrimeSieve.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

using namespace std;

typedef unsigned long long int itype;

const itype MAXNUM = 0x1ffffffffULL-1;

int main()
{
	char *numbers = new char[MAXNUM];
	for (itype i = 0; i < MAXNUM; i++)
		numbers[i] = 0;

	itype sqrtMAXNUM = sqrt((double) MAXNUM)+1;
	itype gate = 2;
	itype p = 2;
	int numprimes = 0;
	do
	{
		// cout << p << " ";
		// Cross out all multiples
		for (itype i = p * p; i <= MAXNUM-p; i += p)
		{
			numbers[i] = 1;
		}

		// Find next prime
		p++;
		while (p < sqrtMAXNUM && numbers[p] != 0)
			p++;
		if (p > gate)
		{
			cout << "Current prime " << p << " is larger than " << gate << endl;
			gate <<= 1;
		}

	} while (p < sqrtMAXNUM);

	// Count primes
	numprimes = 1; // Count 2 as prime
	// Only look at odd
	itype i;
	for (i = 3; i <= MAXNUM-2; i += 2)
		if (numbers[i] == 0)
			numprimes++;

	cout << endl << "Number of primes: " << numprimes << endl;

	// Find highest prime
	for (i = MAXNUM - 1; i > 0; i--)
	{
		if (numbers[i] == 0)
			break;
	}

	cout << endl << "Highest prime found is: " << i << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
