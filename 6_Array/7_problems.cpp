#include <iostream>
#include <unordered_map>

using namespace std;

/*

// Hash Maps

int main()
{

    unordered_map<int, int> table;

    table[5] = 27;
    table[6] = 99;
    table[1] = 73;
    table[4] = 89;

    // Method 1
    // creating iterator;
    unordered_map<int, int>::iterator it;

    for (it = table.begin(); it != table.end(); it++)
    {
        int key = it->first;
        int val = it->second;

        cout << "The key is " << key << " and its value is " << val << endl;
    }

    // Method 2

    for (auto it : table)
    {
        int key = it.first;
        int val = it.second;

        cout << "The key is " << key << " and its value is " << val << endl;
    }

    // Find any Key in Map O(1)
    if (table.find(5) != table.end())
    {
        cout << "Key is available and it's key is " << table[5] << endl;
    }
    else
    {
        cout << "Key is not Present " << endl;
    }

    // Delete it

    table.erase(5);
}

*/

/*

YOU FORGET THIS YOU IDIOT, A MATRIX OF R ROWS AND C COLS, EACH POSITION OF MATRIX CAN BE WRITTEN AS

    

    [
        [[0, 0], [0, 1], [0, 2]],
        [[1, 0], [1, 1], [1, 2]],
        [[2, 0], [2, 1], [2, 2]]
    ]

    ===> C * I + J 

    [
        [[0, 1, 2]],
        [[3, 4, 5]],
        [[6, 7, 8]]
    ]

*/