/*
Author: Bchara Abou Jaffal   

-- DCList.cpp-------------------------------------------------

   This file implements Circular Doubly Linked List member functions.

-------------------------------------------------------------------------*/






#include "DCList.h"


//--- Definition of class no arg constructor

DCList::DCList() {
    this->mySize = 0; //initialize size to 0
    this->myFirst = NULL; //set myFirst to null

}

//--- Definition of class copy constructor

DCList::DCList(const DCList& list) {
    NodePtr listHead = list.myFirst; //get pointer to the first node of the param list
    if (!list.isEmpty()) {
        for (int i = 0; i < list.mySize; i++) {
            insertAtEnd(listHead->data); //insert node into the list
            listHead = listHead->next; //move to the next node
        }
    }
}

//--- Definition of overloaded assignment operator

 DCList& DCList::operator=(const DCList& list) {
     if (this != &list) { //check if it isnt a self assignment
         NodePtr temp;
         while (myFirst != NULL) {//delete old list 
             temp = myFirst;
             myFirst = myFirst->next;
             delete temp;

         }
     }
        //assign new list
        NodePtr listHead = list.myFirst; //get pointer to the first node
        if (!list.isEmpty()) {
            for (int i = 0; i < list.mySize; i++) {
                insertAtEnd(listHead->data); //insert node into the list
                listHead = listHead->next; //move to the next node
            }
        }
     return *this;
}



//--- Definition of class destructor

DCList::~DCList() {
    NodePtr tempPtr; //pointer to delete node
    for (int i = 0; i < mySize; i++) {
        tempPtr = myFirst;
        myFirst = myFirst->next; //traverse list
        delete tempPtr; //delete Node by Node
    }
}


//--- Definition of class function isEmpty()

inline bool DCList::isEmpty() const {
    return myFirst == NULL;

}


//--- Definition of class fucntion search()


bool DCList::search(ElementType value) {
    
    if (isEmpty()) { //exit if empty
        exit(1);
    }
    
        NodePtr temp = myFirst; //set pointer to the head of the list
       
        
        while (temp->next != myFirst) { //traverse list
            if (temp->data == value) {
                return true; 
            }
            temp = temp->next;
        }
        if (temp->data == value) { //check if data is in the last node
            return true;
        }
    return false;
}


//--- Definition of class function insertAtPosition()

bool DCList::insertAtPosition(ElementType data, int index) {
    if (index > mySize || index < 0) { //check if index is valid
        cout << "invalid index" << endl;
        return false;
    }
    NodePtr newPtr = new DNode(data); //initialize node to be inserted

    if (mySize == 0) { //check if list is empty
        myFirst = newPtr; //assign myFirst the newNode
        newPtr->prev = newPtr; //next will point to the same node
        newPtr->next = newPtr; //previous will point to the same node
        mySize++;  //increment size
        return true;
    }
    
    if (index == 0) { 
            newPtr->prev = myFirst->prev;  
            newPtr->next = myFirst;
            myFirst->prev->next = newPtr;
            myFirst = newPtr; //reassign my first to the following node
            newPtr->next->prev = newPtr;
            mySize++; //increment size
            return true;
    }


        NodePtr pred = myFirst;
        int counter = 0;

        while (counter < index - 1) { //traverse list to reach index
            pred = pred->next;
            counter++; //increment counter
        }
        newPtr->next = pred->next;
        pred->next = newPtr;
        newPtr->prev = pred;
        newPtr->next->prev = newPtr;
        mySize++;  //increment size
        return true;

}


//--- Definition of class function insertAtBegining()

bool DCList::insertAtBeginning(ElementType data) {
    insertAtPosition(data, 0); //invoke insertAtPosition 
    return true;
}


//--- Definition of class function insertAtEnd()

bool DCList::insertAtEnd(ElementType data) {
    insertAtPosition(data, mySize); //invoke insertAtPosition
    return true;
}

//--- Definition of class function deleteAtPosition()

bool DCList::deleteAtPosition(int position) {
    if (isEmpty()) { //exit if list is empty
        exit(1);
    }
    if (position < 0 || position > mySize - 1) { //check if pos is valid
        cout << "invalid position" <<endl;
        return false;
    }
    
    NodePtr temp = myFirst; //set the pointer to the head
    if (position == 0) {  //check if the position is myfirst
        myFirst = temp->next; //reassign myfirst to the following node
        myFirst->prev = temp->prev;
        temp->prev->next = myFirst;
        delete temp;
        mySize--; //decrement size
        return true;
    }
    int counter = 0;
    while (counter < position) { //traverse the list to reach pos
        temp = temp->next;
        counter++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    mySize--; //decrement size
    return true;

}


//--- Definition of class function deleteAValue()

bool DCList::deleteAValue(ElementType value) {
    if (isEmpty()) { //exit if list is empty
        exit(1);
    }
    
    if (this->search(value) == false) { //check if a node holding the value exists
        cout << "element isnt in the list" << endl;
        return false;
    }
    
    NodePtr temp = myFirst; //set pointer to the head of the list
   
    
    while (temp->next != myFirst) { //traverse list
        if (temp->data == value) { //to find the value to delete 
            if (temp == myFirst) { //change myFirst 
                myFirst = temp->next;
                myFirst->prev = temp->prev;
                temp->prev->next = myFirst;
                delete temp;
                mySize--; //decrement size
                return true;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            mySize--; //decrement size
            return true;
        }
        temp = temp->next;
    }
        if (temp->data == value) { //check if last element holds the parameter value
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            mySize--;  //decrement size
            return true;
        }
    
    
    
    return true;

}

//--- Definition of class function deleteBeforeAnElement


bool DCList::deleteBeforeAnElement(ElementType value) {
    if (isEmpty()) { //exit if list is empty
        exit(1);
    }

    if (this->search(value) == false) { //check if a node holding the value exists
        cout << "element isnt in the list " << endl;
        return false;
    }

    NodePtr temp = myFirst;
    NodePtr temp2 = myFirst;
    while (temp->next != myFirst) { 
        if (temp->data == value) { //find element to delete before
            if (temp == myFirst) { //delete last element of the list
                while (temp2->next != myFirst) { //traverse the list 
                    temp2 = temp2->next;
                }
                temp2->prev->next = temp;
                temp->prev = temp2->prev;
                delete temp2;
                mySize--; //decrement size
                return true;

            }

            if (temp == myFirst->next) { //check if node is the one following myfirst
                temp2 = myFirst;
                temp->prev = temp2->prev;
                temp2->prev->next = temp;
                delete temp2; //delete head of the list
                myFirst = temp; //reassign myfirst
                mySize--; //decrement size
                return true;
            }
            
            if (temp == myFirst->prev) { //check if the node is the last element of the list
                temp2->prev->next = temp;
                temp->prev = temp2->prev;
                mySize--; //decrement size
                delete temp2;
                return true;
            }
            
            else {
                while (temp2->next != temp) { //traverse the list
                    temp2 = temp2->next;
                }
                temp2->prev->next = temp;
                temp->prev = temp2->prev;
                mySize--; //decrement size
                delete temp2;
                return true;
            }
        }
        temp = temp->next;
    }
    temp2 = temp->prev; 
    temp2->prev->next = temp;
    temp->prev = temp2->prev;
    mySize--; //decrement size
    delete temp2;
    return true;
}

//--- Definition of class function findAndDelete()


int DCList::findAndDelete(ElementType value) {
    if (isEmpty()) { //exit if list is empty
        exit(1);
    }
   
    if (this->search(value) == false) { //checks if value is in the list
        cout << "element isnt in the list " << endl;
        return -1;
    }
        int times = 0;
        NodePtr temp = myFirst; //sets pointer to the head of the list
        NodePtr temp2 = myFirst;
          while(this->search(value) == true){ //iterate through the list while value exists
            if (temp == myFirst && temp->data == value) { // change if myFirst euals param value
                myFirst = temp->next;
                this->deleteAValue(temp->data);
                times++; //increment times
                temp = myFirst;
            }
            if (temp->data == value) {  //delete current node if it the value - param value
               this->deleteAValue(temp->data);
               times++; //increment times
               temp = temp2; //set to the previous node
          }
           temp = temp->next;
           
          }
          //cout << "element deleted " << times << " times" << endl;
          return times;
}
           
  


//--- Definition of class function removeFirst()


ElementType DCList::removeFirst() {
    if (isEmpty()) { //exit if list is empty
        exit(1);
    }

    NodePtr temp = myFirst; //set pointer to the head of the list
    myFirst = temp->next; // set myfirst to the next node 
    myFirst->prev = temp->prev;
    temp->prev->next = myFirst;
    ElementType value = temp->data; //store the deleted node's value
    delete temp;
    mySize--; //decrement size
    return value; 

}


//--- Definition of class function removeLast()

ElementType DCList::removeLast() {

    if (isEmpty()) { //exit if list is empty
        exit(1);
    }

    NodePtr temp = myFirst; //sets the pointer to the head of the list
    while (temp->next != myFirst) { //traverse the list to reach the end 
        temp = temp->next;
    }
    temp->prev->next = myFirst;
    myFirst->prev = temp->prev;
    ElementType value = temp->data; //store the deleted node's value
    delete temp;
    mySize--; //decrement size
    return value; //return stored node
}



//--- Definition of class function deleteDuplicates()

int DCList::deleteDuplicates() {
    if (isEmpty()) { //exit if list empty
        exit(1);
    }
    NodePtr temp = myFirst; //sets the pointer to the head of the list
    NodePtr temp2 = myFirst;

    while (temp->next != myFirst) { //traverse the list
        ElementType value = temp->data; //takes first value and looks for it's duplicates
        while (this->searchNode(value) != temp) {
            this->findAndDelete(value);  //finds and deletes every value
            this->insertAtEnd(value); //inserts the value again once
        }
        temp = temp->next; 
    }
}
        
//--- Definition of class function display()


ostream& DCList::display(ostream& out) const{
    if (isEmpty() || mySize == 0) { //check if list is empty
        out << "list is empty";
    }
    else {
        NodePtr temp = myFirst; //pointer to the head of the list
        out << " <-> ";
        while (temp->next != myFirst) { //traversing the list
            out << temp->data << ((temp->next != myFirst) ? " <-> " : "");
            temp = temp->next; //go to the next node
        }
        out << temp->data << " <-> " << endl; //display last element
    }

      
        return out;
}
ostream& operator<<(ostream& out,  const DCList& list)  {
    list.display(out); //call list display function
    return out;
}
