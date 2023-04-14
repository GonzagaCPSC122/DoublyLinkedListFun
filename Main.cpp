#include "DoublyLinkedList.h"

int main() {
  DoublyLinkedList list; // start out empty list
	
	list.insertInOrder(12);
	list.insertInOrder(5);
	list.insertInOrder(3);
	list.displayList();

	// list.deleteAtFront();
	// list.displayList();
	// list.deleteAtFront();
	// list.displayList();
	// list.deleteAtFront();
	// list.displayList();
	// list.deleteAtFront();
	// list.displayList();
	
	// list.deleteAtEnd();
	// list.displayList();
	// list.deleteAtEnd();
	// list.displayList();
	// list.deleteAtEnd();
	// list.displayList();
	// list.deleteAtEnd();
	// list.displayList();
	
	list.deleteNode(3); // delete first node
	list.displayList();
	list.deleteNode(5);
	list.displayList();
	list.deleteNode(12);
	list.displayList();
	list.deleteNode(4);
	list.displayList();
   
   	return 0;
}
