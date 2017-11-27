// InsertSort1.cpp : The first version of insertion sort algorithm
// The insertion sort algorithm constantly checks each element of vector
// If the element is smaller (or matching any other criteria of sort), 
// It is swapped with previous element of vector and the process is repeated
// until the analyzed element does not meet sort criteria
//
// Since all elements prior to currently analyzed one are already sorted,
// then such iterative process places the analyzed element exactly at correct
// location in vector

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> A = { 5,8,10,12,4,2,6,1,7,0,11,15,9,3,13,14 };
	int N = A.size();
	int keyEl, i;
	cout << "Initial sequence:\n";

	// Output initial sequence of numbers to be sorted
	for (int j = 0; j < N; j++)
		cout << A[j] << " ";

	// Perform sorting of the vector
	for (int j = 1; j < N; j++)
	{
		// Save current element of vector into temporary variable
		keyEl = A[j];
		// Find index of previous vector element
		i = j - 1;
		// Compare current and previous vector elements
		// If current element is smaller, transfer previous element into 
		// position of the current element
		// Keep shifting already sorted sequence to find a place for a current
		// element stored in temporary variable
		while ((i >= 0) && (A[i] > keyEl))
		{
			// If matching criteria, shift vector element by one forward
			A[i + 1] = A[i];
			// Decrease index of vector previous element
			i--;
		}
		// Put current element (from temporary variable)
		// into last freed position. Note, that due to i-- comand
		// index must be increased by 1
		A[i + 1] = keyEl;
	}

	// Output final sequence of numbers after sorting
	cout << "\n\nSorted sequence:\n";
	for (int j = 0; j < N; j++)
		cout << A[j] << " ";

	// Halt program (add pause to keep window open)
	cout << "\n\n\nPress any key to continue . . .";
	cin.get();
	return 0;
}