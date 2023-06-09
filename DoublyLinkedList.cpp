#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
  head = NULL;
  cout << sizeof(Node) << endl;
}

DoublyLinkedList::~DoublyLinkedList() {
  // TODO: free each Node's memory in the list
  Node *currNode = head;
  Node *nextNode = NULL;

  while (currNode != NULL) {
    // save the link to the next node
    nextNode = currNode->next;
    // can safely delete currNode
    delete currNode;
    currNode = nextNode;
  }
  head = NULL; // for good practice
}

void DoublyLinkedList::insertAtFront(int newValue) {
  // make a new Node
  Node *newNode = new Node;
  newNode->value = newValue;
  newNode->next = NULL;
  newNode->prev = NULL;

  // 2 cases
  if (head == NULL) {
    head = newNode;
  } else {
    // list is not empty
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void DoublyLinkedList::displayList() {
  Node *currNode = head;

  cout << "head->";
  while (currNode != NULL) {
    cout << currNode->value << "<->";
    // progress towards BC being false
    currNode = currNode->next;
  }
  cout << "NULL" << endl;
}

void DoublyLinkedList::appendNode(int newValue) {
  // make a new Node
  Node *newNode = new Node;
  newNode->value = newValue;
  newNode->next = NULL;
  newNode->prev = NULL;

  // 2 cases
  if (head == NULL) {
    head = newNode;
  } else {
    // list is not empty
    // need to traverse list, stopping at the last node
    Node *currNode = head;
    while (currNode->next != NULL) {
      currNode = currNode->next;
    }
    // currNode points to the last node in the list
    currNode->next = newNode;
    newNode->prev = currNode;
  }
}

void DoublyLinkedList::insertInOrder(int newValue) {
  // make a new Node
  Node *newNode = new Node;
  newNode->value = newValue;
  newNode->next = NULL;
  newNode->prev = NULL;

  // 2 cases
  if (head == NULL) {
    head = newNode;
  } else {
    // list is not empty
    Node *currNode = head;

    while (currNode != NULL && currNode->value < newValue) {
      currNode = currNode->next;
    }

    // 2 cases to check
    // 1) inserting at head... so we didn't advance currNode (therefore prevNode
    // is NULL) 2) inserting somewhere other than the head, need to the splicing
    if (currNode == head) {
      head->prev = newNode;
      head = newNode;
      newNode->next = currNode;
    } else {
      currNode->prev->next = newNode;
      newNode->prev = currNode->prev;
      currNode->prev = newNode;
      newNode->next = currNode;
    }
  }
}

void DoublyLinkedList::deleteAtFront() {
  // check to make sure there is something to delete
  if (head != NULL) {
    Node *nodeToDelete = head;
    head = head->next;
    if (head != NULL) { 
      head->prev = NULL;
    }
    delete nodeToDelete;
  }
}

void DoublyLinkedList::deleteAtEnd() {
  if (head != NULL) {
    // list is not empty
    // need to traverse list, stopping at the last node
    Node *currNode = head;
    while (currNode->next != NULL) {
      currNode = currNode->next;
    }
    if (currNode == head) {
      // deleting at head... only one Node in the list
      delete head;
      head = NULL; // we now have an empty list
    } else {
      currNode->prev->next = NULL;
      delete currNode;
    }
  }
}

void DoublyLinkedList::deleteNode(int targetValue) {
  // check case 1
  if (head != NULL) {
    // list is not empty
    // need to traverse list, stopping at the last node
    Node *currNode = head;
    // check case 2... the node to delete is the first node
    if (head->value == targetValue) {
      head = head->next;
      if (head != NULL) { 
        head->prev = NULL;
      }
      delete currNode;
    } else { // case 3... the node to delete is not the first node, but might
             // not even be in the list
      Node *prevNode = NULL;
      while (currNode != NULL && currNode->value != targetValue) {
        prevNode = currNode;
        currNode = currNode->next;
      }
      // check if we found targetValue
      if (currNode != NULL) {
        // did find it
        currNode->prev->next = currNode->next;
        if (currNode->next != NULL) {
          currNode->next->prev = currNode->prev;
        }
      }
    }
  }
}
