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

#include <iostream>
#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    out << value;
}
