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
	for (int j = 1; j < N; j++)															// c1 * n
	{
		// Save current element of vector into temporary variable
		keyEl = A[j];																	// c2 * (n-1)
		// Find index of previous vector element
		i = j - 1;																		// c3 * (n-1)
		// Compare current and previous vector elements
		// If current element is smaller, transfer previous element into 
		// position of the current element
		// Keep shifting already sorted sequence to find a place for a current
		// element stored in temporary variable
		while ((i >= 0) && (A[i] > keyEl))												// c4 * sum(tj)			- tj is the number of while loop iterations for specific j value
		{
			// If matching criteria, shift vector element by one forward
			A[i + 1] = A[i];															// c5 * sum(tj-1)		- summing by 1 element less
			// Decrease index of vector previous element
			i--;																		// c6 * sum(tj-1)
		}
		// Put current element (from temporary variable)
		// into last freed position. Note, that due to i-- comand
		// index must be increased by 1
		A[i + 1] = keyEl;																// c7 * (n-1)
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

// Determine computational complexity by adding up together computation time multiplied by computational costs:
//		c1*n + (c2 + c3 + c7)*(n - 1) + c4*sum(tj) + (c5 + c6)*sum(tj-1)
//
// Two extreme case scenarios:
// 1. Best case scenario (already sorted array, so tj = 1 for each j):
//		c1*n + (c2 + c3 + c7)*(n - 1) + c4*(n - 1)
//		c1*n + (c2 + c3 + c4 + c7)*(n - 1)
//      (c1 + c2 + c3 + c4 + c7)*n - (c2 + c3 + c4 + c7)													==> an + b (linear function)
// 2. Worst case scenario (sorted by descending instead of ascending, so tj = j)
//	  Thus, sum(tj)   = n*(n+1)/2 - 1			(note, that summation begins from j = 2)
//			sum(tj-1) = (n-1)*n/2 - 1
//		c1*n + (c2 + c3 + c7)*(n - 1) + c4*n*(n + 1)/2 - c4 + (c5 + c6)*(n - 1)*n/2 - (c5 + c6)
//		c1*n + (c2 + c3 + c7)*(n - 1) + (c4/2 + c5/2 + c6/2)/n^2 + (c4/2 - c5/2 - c6/2)/2*n - (c4 + c5 + c6)
//		(c4/2 + c5/2 + c6/2)*n^2 + (c1 + c2 + c3 + c4/2 - c5/2 - c6/2 + c7)*n + (c1 - c4 - c5 - c6)			==> an^2 + bn + c (quadratic function)