/*
Author: Bchara Abou Jaffal  

-- DCList.h --------------------------------------------------

  This header file defines the data type Circular Doubly linked List for
  processing lists.
  Basic operations are:
	 Constructor
	 Copy constructor
	 Destructor
	 isEmpty:  Check if list is empty
	 search:   searches for an element inside the list
	 searchNode: search for the node containing an element inside the list
	 insertAtBegining:   Insert a node at the beginning of the list
	 insertAtEnd:   Insert a node at the end of the list
	 insertAtPosition:   Insert a node at a certain position in the list
	 removeFirst: delete the node at the beginning of the list
	 removeLast: delete the node at the end of the list
	 deleteAtPosition:   delete a node at a certain position in the list
	 deleteAValue: delete the node that contains parameter value as data
	 deleteBeforeAnElement: deletes the node before the element that contains para value
	 findAndDelete:  searches for an element and deletes all occurences
	 deleteDuplicates: keeps the first occurence of an element and deletes the rest 
	 display: displays the list
	 << :      Output operator
	 = :  assignment operator
-------------------------------------------------------------------------*/

#ifndef DCLIST_H
#define DCLIST_H
#include <iostream>
typedef int ElementType;
using namespace std;


class DCList
{

public:

	/******** Function Members ********/
   
	
	/***** Class constructor *****/
	DCList();
	/*----------------------------------------------------------------------
	 Construct a Circular Doubly Linked List object.

	 Precondition:  None
	 Postcondition: An empty Circular Doubly Linked List object has been
	 constructed; mySize is 0 and myFirst Null.
	 -----------------------------------------------------------------------*/



	 /***** Copy constructor *****/
	DCList(const DCList&);
	/*----------------------------------------------------------------------
	 Construct a copy of a Circular Doubly Linked List object.

	 Precondition:  A copy of a Circular Doubly Linked List is needed; it is a
	 const reference parameter.
	 Postcondition: A copy of Circular Doubly Linked List has been constructed.
	 -----------------------------------------------------------------------*/



	 /***** Assignment operator *****/
	 DCList &operator=(const DCList&);
	/*----------------------------------------------------------------------
	 Assign a copy of a List object to the current object.

	 Precondition: none
	 Postcondition: A copy of this list has been assigned to this
	 object. A const reference to this list is returned.
	 -----------------------------------------------------------------------*/



	 /***** Class destructor *****/
	~DCList();
	/*----------------------------------------------------------------------
	 Destroys a Circular Doubly Linked List object.

	 Precondition:  The life of a List object is over.
	 Postcondition: The memory allocated by the constructor for the nodes has
	 been returned to the heap.
	 -----------------------------------------------------------------------*/



	 /***** is empty operation *****/
	inline bool isEmpty() const;
	/*----------------------------------------------------------------------
	 Check if a list is empty.

	 Precondition:  None
	 Postcondition: true is returned if the list is empty, false if not.
	 -----------------------------------------------------------------------*/


	 /***** Search operation *****/
	bool search(ElementType);
	/*----------------------------------------------------------------------
	 checks wether an element is within the list.

	 Precondition:  None.
	 Postcondition: return true to the first existing element that holds the
	 parameter value, return Null otherwise.
	 -----------------------------------------------------------------------*/


	 /***** insert at position operation *****/
	bool insertAtPosition(ElementType, int);
	/*----------------------------------------------------------------------
	 Create a node holding a certain value and insert it at a certain position
	 in the list.

	 Precondition:  Receive the certain value to be put in the node at the position.
	 Postcondition: Insert the node at correct position  the list, increment size.
	 Return true if operation was a success, false if not(Position not within
	 the range of the list).
-----------------------------------------------------------------------*/



/***** insert at end operation *****/
	bool insertAtEnd(ElementType);
	/*----------------------------------------------------------------------
	 Create a node holding a certain value and insert it at the end of
	 the list.

	 Precondition:  Receive the certain value to be put in the node.
	 Postcondition: Insert the node at the end of the list, increment size.
	 -----------------------------------------------------------------------*/



	 /***** insert at beginning operation *****/
	bool insertAtBeginning(ElementType);
	/*----------------------------------------------------------------------
	 Create a node holding a certain value and insert it at the beginning of
	 the list.

	 Precondition:  Receive the certain value to be put in the node.
	 Postcondition: Insert the node at the beginning of the list, increment size.
	 -----------------------------------------------------------------------*/



	 /***** delete at position operation *****/
	bool deleteAtPosition(int);
	/*----------------------------------------------------------------------
	 Delete the node at a certain position of the list.

	 Precondition:  Receive the position to delete.
	 Postcondition: delete the node at the certain position, decrement size.
	 Return true if operation was a success false otherwise(list empty or
	 position out of range)
	 -----------------------------------------------------------------------*/



	 /***** delete a value operation *****/
	bool deleteAValue(ElementType);
	/*----------------------------------------------------------------------
	 Delete the first node holding a certain value.

	 Precondition:  Receive the value to delete, list not empty.
	 Postcondition: delete the node holding a certain value, decrement size.
	 Return true if operation was a success false otherwise(value not found)
	 -----------------------------------------------------------------------*/


	 /***** delete before an element operation *****/
	bool deleteBeforeAnElement(ElementType);
	/*---------------------------------------------------------------------------
	 Delete the node before the one containing the same value as parameter eleent

	 Precondition:  Receive value to delete, list not empty
	 Postcondition: delete the node preceding the one containing the parameter value
	 decrement size, return true if operation is successful false
	 otherwise(value not found)
	 ----------------------------------------------------------------------------*/



	 /***** find and delete operation *****/
	int findAndDelete(ElementType);
	/*---------------------------------------------------------------------------
	 finds an element and delete all of it's occurences

	 Precondition:  Receive value to delete, list not empty
	 Postcondition: searches for all the nodes containing the parameter value and
	  deletes all of it's occurences decrement size, return the number of times the
	  element was deleted if found, returns -1 otherwise(value not found)
	 ----------------------------------------------------------------------------*/


	 /***** remove first operation *****/
	ElementType removeFirst();
	/*----------------------------------------------------------------------
	 Delete the node at the beginning of the list.

	 Precondition:  List no empty.
	 Postcondition: delete the first node of the list, decrement size.
	 -----------------------------------------------------------------------*/



	 /***** remove last operation *****/
	ElementType removeLast();
	/*----------------------------------------------------------------------
	 Delete the node at the end of the list.

	 Precondition:  List no empty.
	 Postcondition: delete the last node of the list, decrement size.
	 -----------------------------------------------------------------------*/



	 /***** delete duplicates operation *****/
	int deleteDuplicates();
	/*----------------------------------------------------------------------------
	 keeps only the first occurence of an element in the list and deletes the rest

	 Precondition:  List no empty.
	 Postcondition: delete all the other occurences of an element in the list,
	 and keep only one, decrement size.
	 ----------------------------------------------------------------------------*/



	 /***** display *****/
	ostream& display(ostream&) const;
	/*----------------------------------------------------------------------
	 Display a list.

	 Precondition: Receive an ostream object.
	 Postcondition: display the values of te nodes of the list in order.
	 -----------------------------------------------------------------------*/



private:



	/***** Class DNode*****/
	class DNode
	{


	public:
		/***** Class no arg constructor *****/
		DNode() {
			this->data = NULL;
			this->next = NULL;
			this->prev = NULL;
		};
		/*----------------------------------------------------------------------
         Construct an empty DNode object.

         Precondition:  none
         Postcondition: A DNode object is constructed: data, value and pointer
		 are set to null
         -----------------------------------------------------------------------*/




       /***** Class constructor *****/
		DNode(ElementType data) {
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		};
		/*----------------------------------------------------------------------
         Construct a DNode object.

         Precondition:  none
         Postcondition: A DNode object is constructed: data is set to the passed
          value, both pointer point to null.
         -----------------------------------------------------------------------*/

		/******** Data Members ********/
		ElementType data;
		DNode* next;
		DNode* prev;

	};
	


	/******** Data Members ********/
	typedef DNode* NodePtr;
	int mySize; //size of the list; number of nodes in the list
	NodePtr myFirst; //pointer to the first node of the list



	/******** private search node function ********/
	NodePtr searchNode(ElementType value) {
		if (isEmpty()) {
			cout << "list is empty " << endl;
			return NULL;
		}

		NodePtr temp = myFirst;
		while (temp->next != myFirst) {
			if (temp->data == value) {
				return temp;
			}
			temp = temp->next;
		}
		if (temp->data == value) {
			return temp;
		}

		cout << "element isnt in the list " << endl;
		return NULL;
	}
	/*----------------------------------------------------------------------
	 checks wether a specific node containing the parameter value is 
	 within the list.

     Precondition:  None.
     Postcondition : returns a pointer  to the first existing node that holds 
	 the parameter value, return Null otherwise.
	 ---------------------------------------------------------------------- - */



};

//------ Prototype of output operator
ostream& operator<<(ostream&, const DCList&);


#endif 
