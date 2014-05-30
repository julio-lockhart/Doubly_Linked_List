#include "List.h"
#include "NodeList.h"

//*********************** 
// default constructor  *
//***********************
 
List :: List() 
   : firstPtr( 0 ), lastPtr( 0 ) 
{ 
   // empty body
} // end List constructor

//*********************** 
// destructor           *
//***********************

List :: ~List()
{
   bool empty = false;

   if ( !isEmpty() ) // List is not empty
   {    
      cout << "Destroying nodes ...\n";

      ListNode *currentPtr = firstPtr;
      ListNode *tempPtr;

      while ( currentPtr != false ) // delete remaining nodes
      {  
         tempPtr = currentPtr;
         cout << tempPtr->data << '\n';
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      } // end while
   } // end if

   cout << "All nodes destroyed\n\n";
} // end List destructor



//******************************** 
// Insert node at front of list  *
//********************************

void List :: insertAtFront( char value )
{
   ListNode *newPtr = getNewNode( value ); // new node

   if ( isEmpty() ) // List is empty
   {
	   firstPtr = lastPtr = newPtr; // new list has only one node
	   newPtr->prevPtr = NULL;
	   newPtr->nextPtr = NULL;
   }
   
   else // List is not empty
   {
      newPtr->nextPtr = firstPtr; // point new node to previous 1st node
      firstPtr->prevPtr = newPtr; 
	  firstPtr = newPtr;
   } // end else
} // end function insertAtFront



//*********************************** 
// Insert node at the back of list  *
//***********************************

void List :: insertAtBack( char value )
{
   ListNode *newPtr = getNewNode( value ); // new node

   if ( isEmpty() ) // List is empty
   {
	   firstPtr = lastPtr = newPtr; // new list has only one node
	   newPtr->nextPtr = NULL;
	   newPtr->prevPtr = NULL;
   }

   else // List is not empty
   {
      lastPtr->nextPtr = newPtr; // update previous last node
	  newPtr->prevPtr = lastPtr;
	  newPtr->nextPtr = NULL;
      lastPtr = newPtr; // new last node
   } // end else
} // end function insertAtBack


//********************************* 
// Delete node from front of list *
//*********************************

bool List :: removeFromFront( )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   
   else 
   {
      ListNode *tempPtr = firstPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0; // no nodes remain after removal
      else
	  {
         firstPtr = firstPtr->nextPtr; // point to previous 2nd node
	  }
			
      delete tempPtr; // reclaim previous front node
      return true; // delete successful
   } // end else
} // end function removeFromFront


//********************************* 
// Delete node from back of list  *
//*********************************

bool List :: removeFromBack( )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   
   else 
   {
      ListNode *tempPtr = lastPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr ) // List has one element
         firstPtr = lastPtr = NULL; // no nodes remain after removal
      
	  else 
      {
         lastPtr = lastPtr->prevPtr;
		 lastPtr->nextPtr = NULL;
      } // end else

      delete tempPtr; // reclaim former last node
      return true; // delete successful
   } // end else
} // end function removeFromBack


//********************************** 
// Checks to see if list is empty  *
//**********************************

bool List :: isEmpty() const 
{ 
   return firstPtr == NULL; 
} // end function isEmpty


//****************************************** 
// Return pointer to newly allocated node  *
//******************************************

ListNode *List :: getNewNode( char value )
{
   return new ListNode( value );
} // end function getNewNode

//***************************** 
// Displays contents of List  *
//*****************************

void List :: print() const
{
   if ( isEmpty() ) // List is empty
   {
      cout << "The list is empty\n\n";
      return;
   } // end if

   ListNode *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != NULL ) // get element data
   {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
   } // end while

   cout << "\n\n";
} // end function print

//*************************************** 
// Returns the amount of nodes in list  *
//***************************************

	
int List :: length()
{
	ListNode *currPtr = firstPtr; // Setting a temporary pointer to firstPtr

	if( isEmpty() ) // List is Empty
	{
		cout << "The list is empty." << endl;
		return 0;
	}

	else
	{
		int count = 0;
		
		while( currPtr != NULL )
		{
			currPtr = currPtr->nextPtr;
			count++;
		} // end while

		return count;
	} // end else
	cout << endl;
} // end function length


//***************************************** 
// Inserts a node after a specified node  *
//*****************************************

bool List :: insertAfter(char previous, char newValue)
{
	ListNode *currPtr = firstPtr; // Used to traverse through list  

	if ( isEmpty() ) // List is empty
	{	
		cout << "\n";
		cout << "Cannot Insert. ";
		return true;
	}
		
	else
	{
		ListNode *valuePtr = getNewNode( newValue );

		while( currPtr->data != previous ) // While currPtr's data not equal to the previous
		{
			currPtr = currPtr->nextPtr;	// continue to traverse through the list

			if( currPtr == lastPtr && currPtr->data != previous ) 
			{
				cout << "The Node, " << previous << " does not exist. ";
				return false;
			}

			if(currPtr == lastPtr)
			{
				valuePtr->nextPtr = currPtr->nextPtr;
				valuePtr->prevPtr = currPtr;
				currPtr->nextPtr = valuePtr;
				lastPtr = valuePtr;
				return true;
			}
		} // end while

		ListNode *tempPtr;

		valuePtr->nextPtr = currPtr->nextPtr;
		valuePtr->prevPtr = currPtr;
		currPtr->nextPtr = valuePtr;
		tempPtr = valuePtr->nextPtr;
	} // end else
	return true;
} // end function insertAfter 


//********************************************* 
// Change the Data Value of a specified node  *
//*********************************************

bool List :: changeElement( char prevValue, char newValue )
{
	ListNode *tempPtr = firstPtr;

	if( isEmpty() )
		return false;
	
	while( tempPtr != NULL )
	{
		if( tempPtr->data != prevValue )
		{
			tempPtr = tempPtr->nextPtr;
		}

		else
			break;
	}
	
	if( tempPtr == NULL )
	{
		cout << "\n\n";
		cout << "That node does not exist." << endl << endl;
		return false;
	}

	else
	{
		while( tempPtr->data != prevValue ) // While the tempPtr's data does not equal to the previous value
			tempPtr = tempPtr->nextPtr;	// set the tempPtr to the next pointer
	}

	tempPtr->data = newValue; // set the new value equal to the data for tempPtr
	return true;
} // end changeElement function

//****************************************** 
// Removes a specified node from the list  *
//******************************************

bool List :: removeFromList( char value )
{
	ListNode *deletePtr; // Pointer will point to node will be deleted
	ListNode *prevPtr; // Pointer that will point to previous node

	deletePtr = firstPtr;

	while( deletePtr != NULL ) // Traverse through the list
	{
		if( deletePtr->data != value ) // Matching pointer data with value
		{
			deletePtr = deletePtr->nextPtr;
		}

		else
			break;
	}

	if( deletePtr == NULL )
	{
		cout << endl << "That node is not in the list." << endl << endl;
		return false;
	}

	prevPtr = firstPtr;

	if( deletePtr == firstPtr )
	{
		// Calling removeFromFront if user wants to delete first node 
		removeFromFront();
		return true;
	}

	if( deletePtr == firstPtr ) // if one element remains
	{
		if ( firstPtr == lastPtr )
			firstPtr = lastPtr = NULL; // no nodes remain after removal

		delete deletePtr; // reclaim previous front node
		return true; // delete successful
	}
	
	while( prevPtr->nextPtr != deletePtr )
	{
		prevPtr = prevPtr->nextPtr;
	}

	prevPtr->nextPtr = deletePtr->nextPtr;
	delete deletePtr;
	return true;
} // end function removeFromList  


/*********** End List.cpp ***********/