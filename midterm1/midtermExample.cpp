/* Midterm proctor exam example
 * 
 * INSTRUCTIONS:  Write two functions in the space 
 * indicated below.
 * 
 * #1 => Find index of maximum value:  Write a function that will
 *  find the INDEX of the FIRST INSTANCE of the maximum value
 *  in the array. There may be more than one copy of the maximum
 *  value so just pass back the first index found.
 * 
 * #2 => Insert a given number before the first maximum:  Find the
 * first instance of the maximum and insert a passed in number
 * BEFORE this element.  Do not delete any elements in the array
 * or change the order of any elements in the array.
 * ------------------------------------------------------------------
 * NOTE: The first function can be used within the second function.
 * ------------------------------------------------------------------
 * You can change this file all you want during
 * the exam but keep in mind that I will ONLY BE
 * USING YOUR FUNCTIONS by copying it to another
 * main.cpp file (with different variable values)
 * for grading. So don't code to the given data
 * values or expect your code outside your functions
 * to copy over.
 * 
 * Do not use global variables/constants
 * or goto's in your code.  
 * 
 * Don't ask the user for information.  The main
 * function will get all information needed and pass it
 * into your functions (see main function for
 * how your functions will be called).
 * 
 * 
 * three example runs are below:
FIRST EXAMPLE
*
BEFORE

--------------------
 1 6 2
 -16 -16 2
 -5 200
--------------------
Index of maximum: 7
Number to Insert: 888
AFTER

--------------------
 1 6 2
 -16 -16 2
 -5 888 200

--------------------

SECOND EXAMPLE
*
BEFORE

--------------------
 3 -4 1
 3 -4 2

--------------------
Index of maximum: 0
Number to Insert: 999
AFTER

--------------------
 999 3 -4
 1 3 -4
 2
--------------------

THIRD EXAMPLE
* 
BEFORE

--------------------
 1 140 32
 3 140 21
 3
--------------------
Index of maximum: 1
Number to Insert: 333
AFTER

--------------------
 1 333 140
 32 3 140
 21 3
--------------------

 */
#include <iostream>

using namespace std;

// PLEASE PUT YOUR FUNCTIONS BELOW THIS LINE

int findMaxIndex(int arr[], int size)
{
	int max = arr[0];
	int indexOfMax = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			indexOfMax = i;
		}
	}

	return indexOfMax;
}

void insertNumber(int arr[], int &arrSize, int newNum)
{
	int originalSize = arrSize;
	int indexNum = findMaxIndex(arr, originalSize);
	arrSize++;
	//cout << indexNum << " " << originalSize << " " << arrSize << endl;

	for (int i = arrSize; i >= 0; i--)
	{
		if (i == indexNum)
		{
			arr[i] = newNum;
		}
		else if (i > indexNum)
		{
			arr[i] = arr[i - 1];
		}
	}
	//arrSize++;
}

//  END OF FUNCTIONS

void printArray(int array[], int count)
{
	cout << endl
			 << "--------------------" << endl;
	for (int i = 1; i <= count; i++)
	{
		if (i % 3 == 0)
			cout << " " << array[i - 1] << endl;
		else
			cout << " " << array[i - 1];
	}
	cout << endl
			 << "--------------------" << endl;
}

int main()
{
	int index, number;
	// second test array (uncomment to use)
	//	int array[200] = {3, -4, 1, 3, -4, 2};
	//	int count = 6;
	// first test array
	//int array[200] = {1, 6, 2, -16, -16, 2, -5, 200};
	//int count = 8;
	// third test array
	int array[200] = {1, 140, 32, 3, 140, 21, 3};
	int count = 7;

	cout << "BEFORE" << endl;
	printArray(array, count);

	index = findMaxIndex(array, count);
	cout << "Index of maximum: " << index << endl;
	cout << "Number to Insert: ";
	cin >> number;
	insertNumber(array, count, number);
	cout << "AFTER" << endl;
	printArray(array, count);

	return 0;
}
