/* Midterm 7
 * For Part II and III
 * 
 * See midterm7.txt for instructions on how to do this part
 * of the exam
 * 
 */
#include <iostream>

using namespace std;

// PLEASE PUT YOUR FUNCTIONS BELOW THIS LINE

int findLastFive(int array[], int size)
{
	int indexNum = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] % 5 == 0)
		{
			indexNum = i;
		}
	}

	return indexNum;
}

void deleteFive(int array[], int &size)
{
	int indexToDelete = findLastFive(array, size);

	for (int i = indexToDelete; i < size; i++)
	{
		array[i] = array[i + 1];
	}

	size--;
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
	int index;
	// first test array (uncomment to use)
	int array[200] = {41, 45, 300, 50, 4, 91};
	int count = 6;
	// second test array
	// int array[200] = {5437, 4233, 23333, 55788};
	// int count = 4;
	// third test array
	//int array[200] = {1, 40, 32, 3, 11, 21, 3};
	//int count = 7;

	cout << "BEFORE" << endl;
	printArray(array, count);

	index = findLastFive(array, count);
	cout << "Index found at: " << index << endl;

	deleteFive(array, count);

	cout << "AFTER" << endl;
	printArray(array, count);

	return 0;
}
