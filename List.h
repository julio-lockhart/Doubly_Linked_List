// List.h
// List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "NodeList.h" // ListNode class definition
using namespace std;

class List 
{
	public:

		List(); // constructor
		~List(); // destructor
		int length();
		void insertAtFront( char );
		void insertAtBack( char );
		bool insertAfter( char, char );
		bool changeElement( char, char newValue );
		bool removeFromFront( );
		bool removeFromBack( );
		bool removeFromList( char );
		bool isEmpty() const;
		void print() const;
	
	private:
		
		ListNode *firstPtr; // pointer to first node
		ListNode *lastPtr; // pointer to last node

   // utility function to allocate new node
   ListNode *getNewNode( char );
}; // end class List
#endif
