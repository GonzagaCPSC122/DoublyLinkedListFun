#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

// a linked list of Nodes
// each Node stores a single integer value
// can be expanded to store multiple values
// or templated to store any value type
class DoublyLinkedList {
	private:
		// self referential
	   struct Node {
		  int value; // data value Node stores
		  struct Node * next; // points to next Node in list
      struct Node * prev; // NEW: points to previous Node in list
	   }; 

	   Node * head; // list head pointer

	public:
	   DoublyLinkedList(); // DVC
	   ~DoublyLinkedList(); // destructor
		  
	   // common linked list operations
	   void insertAtFront(int);
	   void displayList();
	   void appendNode(int); // insert at end
	   void insertInOrder(int);
	   void deleteAtFront();
	   void deleteAtEnd();
	   void deleteNode(int);
};

#endif
