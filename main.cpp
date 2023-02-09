/*
 * Jaishnoor Kaur & Bhargavi Teki
 * CS 301
 * Instructor Dr. Fay Zhong
 * 2/7/2023
 */

#include <iostream>
#include "ItemType.h"
#include "ItemType.cpp"
#include "Unsorted.h"
#include "Unsorted.cpp"

using namespace std;
int main()
{
    string inFile, outFile, runTest;
    // prompt user for the name of the input file to use
    cout << "Input a file name of your choice: " ;
    cin >> inFile;
    ifstream in(inFile.c_str());

    Unsorted mylist;
    ItemType item;
    int n;
    if(in.is_open())
    {
        // prompt user for the name of the output file to use
        cout << "Enter name of otput command file: ";
        cin >> outFile;
        // prompt user for the name of the test run
        cout << "Enter name of test run: ";
        cin >> runTest;

        ofstream out(outFile.c_str());
        string line;
        int command = 1;
        out << runTest << endl;

        while(in>>line)
        {
            if(line == "GetLength")
            {
                out << "Length is " << mylist.GetLength() << endl;
                cout << "GetLength command number: " << command << " completed" << endl;
                command++;
            }
            else if(line == "PutItem")
            {
                in >> n;
                item.Initialize(n);
                mylist.PutItem(item);
                out << n << " is in list" << endl;
                cout << "PutItem command number " << command << " completed." << endl;
                command++;
            }
            else if(line == "PrintList")
            {
                out << "PrintList" << endl;
                item.Print(out);
                cout << "PrintList command number " << command << " completed." << endl;
                command++;
            }
            else if(line == "GetItem")
            {
                bool found = false;
                in >> n;
                ItemType it;
                it.Initialize(n);
                it.Print(out);
                item = mylist.GetItem(it, found);
                if (found == true)
                    out << "Is in the list." << endl;
                else
                    out << "Is not in the list." << endl;

                cout << "GetItem command number " << command << " completed." << endl;
                command++;
            }
            else if(line == "IsFull")
            {
                bool full = mylist.IsFull();
                if(full == true)
                    out << "List is full." << endl;
                else
                    out << "List is not full." << endl;

                cout << "IsFull command number " << command << " completed." << endl;
                command++;
            }
            else if(line == "DeleteItem")
            {
                in >> n;
                ItemType it;
                it.Initialize(n);
                mylist.DeleteItem(it);

                it.Print(out);
                out << "Is deleted." << endl;

                cout << "DeleteItem command number " << command << " completed." << endl;
                command++;
            }
            else if (line == "MakeEmpty")
            {
                mylist.MakeEmpty();
                out << "List is empty." << endl;
                cout << "MakeEmpty command number " << command << " completed." << endl;
                command++;
            }
            else if(line == "Error")
            {
                cout << "Error command not recognized." << endl;
                command++;
            }
            else if (line == "Quit")
            {
                cout << "Command number " << command << " completed." << endl;
                cout << "Quit \nTesting Completed." << endl;
            }

        }

    }
    else
        cout << "Input file Not Found" << endl;

    return 0;

}
