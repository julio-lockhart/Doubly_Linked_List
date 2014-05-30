#include "NodeList.h"

//*********************** 
// Constructor			*
//***********************

ListNode :: ListNode( char info )
   : data( info ), nextPtr( 0 ), prevPtr( 0 ) 
{ 
   // empty body
} // end ListNode constructor

//******************************** 
// Returns Copy of data in node  *
//********************************

// return copy of data in node
char ListNode :: getData() const 
{ 
   return data; 
} // end function getData