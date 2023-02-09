/*
 * Jaishnoor Kaur & Bhargavi Teki
 * CS 301
 * Instructor Dr. Fay Zhong
 * 2/5/2023
 */

/****************************************************************
*    Title: C++ Plus Data Structures
*    Author: Nell Dale; Chip Weems; Tim Richards
*    Date accessed: 02/07/2023
*    Code version: 2018
*    Availability: https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
*****************************************************************/

#ifndef UNSORTED_H
#define UNSORTED_H

#include "ItemType.h"
// File ItemType.h must be provided by the user of this class.
//  ItemType.h must contain the following definitions:
//  MAX_ITEMS:     the maximum number of items on the list
//  ItemType:      the definition of the objects on the list
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns
//       LESS, if self "comes before" item
//       GREATER, if self "comes after" item
//       EQUAL, if self and item are the same

class Unsorted
{
public:
    Unsorted();
    // Constructor

    void MakeEmpty();
    // Function: Returns the list to the empty state.
    // Post:  List is empty.

    bool IsFull() const;
    // Function:  Determines whether list is full.
    // Pre:  List has been initialized.
    // Post: Function value = (list is full)

    int GetLength() const;
    // Function: Determines the number of elements in list.
    // Pre:  List has been initialized.
    // Post: Function value = number of elements in list

    ItemType GetItem(ItemType, bool&);
    // Function: Retrieves list element whose key matches item's key (if
    //           present).
    // Pre:  List has been initialized.
    //       Key member of item is initialized.
    // Post: If there is an element someItem whose key matches
    //       item's key, then found = true and someItem is returned.
    // 	 otherwise found = false and item is returned.
    //       List is unchanged.

    void PutItem(ItemType item);
    // Function: Adds item to list.
    // Pre:  List has been initialized.
    //       List is not full.
    //       item is not in list.
    // Post: item is in list.

    void DeleteItem(ItemType item);
    // Function: Deletes the element whose key matches item's key.
    // Pre:  List has been initialized.
    //       Key member of item is initialized.
    //       One and only one element in list has a key matching item's key.
    // Post: No element in list has a key matching item's key.


private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};


#endif