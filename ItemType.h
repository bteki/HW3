/*
 * Jaishnoor Kaur & Bhargavi Teki
 * CS 301
 * Instructor Dr. Fay Zhong
 * 2/5/2023
 */

#include <iostream>
#include <fstream>
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(std::ostream&) const;
    void Initialize(int number);
private:
    int value;
};

#endif
