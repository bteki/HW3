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
#include "Unsorted.h"
// Implementation file for Unsorted.h

Unsorted::Unsorted()
{
    length = 0;
}
bool Unsorted::IsFull() const
{
    return (length == MAX_ITEMS);
}
int Unsorted::GetLength() const
{
    return length;
}

ItemType Unsorted::GetItem(ItemType item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been returned;
//       otherwise, item is returned.
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER : location++;
                moreToSearch = (location < length);
                break;
            case EQUAL   : found = true;
                item = info[location];
                break;
        }
    }
    return item;
}
void Unsorted::MakeEmpty()
// Post: list is empty.
{
    length = 0;
}
void Unsorted::PutItem(ItemType item)
// Post: item is in the list.
{
    info[length] = item;
    length++;
}
void Unsorted::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL)
        location++;

    info[location] = info[length - 1];
    length--;
}
void Unsorted::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}

ItemType Unsorted::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
    currentPos++;
    return info[currentPos];
}