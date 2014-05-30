/**************************************************************** 
// Julio Lockhart											    *
// This program uses 2 classes to create a Doubly Linked List	*
// User will be able to modify list as they please				*
****************************************************************/

#include <iostream>
#include "List.h" // List class definition
#include "NodeList.h" // NodeList class definition 
using namespace std;


void instructions();

int main()
{
   // test List of char values
   List integerList;

   cout << "Testing a List of Integers" << endl << endl;
   instructions(); // display instructions

   int choice; // store user choice
   char value; // store input value
   char newValue, previous; // stores new value and previous value for insert after
   char prevValue, remove; // stores previous value and data to be removed				  

   do // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice ) 
      {
         case 1: // insert at beginning
            cout << "Enter an integer: ";
            cin >> value;
            integerList.insertAtFront( value );
            integerList.print();
            break;
		 case 2: // insert at end
            cout << "Enter an integer: ";
            cin >> value;
            integerList.insertAtBack( value );
            integerList.print();
            break;
		 case 3: // delete from beginning of list
			 if( integerList.removeFromFront() )
				 cout << "First element removed from list\n";

			 integerList.print();
			 break;
		 case 4: // delete from end of list
            if ( integerList.removeFromBack() )
               cout << "Last element removed from list\n";

            integerList.print();
            break;
         case 5: // insert After
			 cout << "Enter New Integer: ";
			 cin >> newValue;
			 cout << "After which node?: ";
			 cin >> previous;
			 integerList.insertAfter(previous, newValue);
			 integerList.print();
			 break;
		 case 6: // change an element
			 cout << "Change which Integer?: ";
			 cin >> prevValue;
			 cout << "Enter new Integer: ";
			 cin >> newValue;
			 integerList.changeElement( prevValue, newValue );
			 integerList.print();
			 break;
		 case 7: // print out number of nodes
			 cout << "The Number of Nodes is: " << integerList.length();
			 cout << endl << endl;
			 break;
		 case 8: // remove from list
			 cout << "Which Node would you like to remove?: ";
			 cin >> remove;
			 integerList.removeFromList( remove );
			 integerList.print();
			 break;
      } // end switch
   } while ( choice != 9 ); // end do...while

   cout << "End list test\n\n";

   return 0;
} // end main

// display program instructions to user
void instructions()
{
   cout << "Enter one of the following:\n"
      << "  1 to insert at beginning of list\n" 
      << "  2 to insert at end of list\n" 
      << "  3 to delete from beginning of list\n" 
	  << "  4 to delete from end of list\n"
	  << "  5 to insert after a node\n"
      << "  6 to change an element\n"
	  << "  7 to count number of nodes\n"
	  << "  8 to remove from list\n"
      << "  9 to end list processing\n" << endl;
} // end function instructions