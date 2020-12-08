/* Final 4
 *   See instructions in d2l folder on how to do
 * this exam.
 * 
 */
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// PLEASE PUT YOUR FUNCTIONS BELOW THIS LINE.
// DO NOT REMOVE THE COMMENT LINE ABOVE




//  END OF FUNCTIONS - DO NOT REMOVE THIS COMMENT LINE.

void printList(Node* head)
{
   cout << "-----------" << endl;
   Node* current = head;
   while(current) 
   {
      cout << current->data << endl;
      current = current->next;
   }
   cout << "----------------" << endl;	
}

int main()
{
    Node *head = NULL;
    int array[200] = {18, 8, 2, 1, 5, 9, 8, 10, 1};
	int count = 9;
	//int array[200] = {1, 8, 2, 1, 3, 9, 8, 10};
	//int count = 8;
	//int array[200] = {10, 8, 2, 4};
	//int count = 4;
	
    // this how the first function
    // will be called
    buildList(head, array, count);
    
    cout << "BEFORE" << endl;
    printList(head); 
	
    // this how the second function will
    // be called.
	insert100(head);
	
	cout << "AFTER" << endl;
    printList(head); 
    
    return 0;
}
