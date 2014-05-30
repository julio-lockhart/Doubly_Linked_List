// ListNode.h
// ListNode class definition.
#ifndef NODELIST_H
#define NODELIST_H

// forward declaration of class List required to announce that class 		
// List exists so it can be used in the friend declaration
class List;                            

class ListNode 
{
	friend class List; // make List a friend

	public:
		ListNode( char ); // constructor
		char getData() const; // return data in node

	private:
		char data; // data
		ListNode *nextPtr; // next node in list
		ListNode *prevPtr; // prev node in list
}; // end class ListNode
#endif