#include <iostream>

using namespace std;

/*
Containers




*/

/*
// Vector

#include <vector>
int main()
{

    vector<int> marks;
    vector<int> miles(10);
    vector<int> distances(15, 0);


    // All Methods
    // vector.begin(), vector.front(), vector.back(), vector.end(), vector.size(), vector.empty(),vector.capacity()
    // vector.reverse(size_type n),
    // vector.push_back(value), vector.pop_back(), vector.insert(iterator position, value), vector.erase(iterator position)
    // vector.clear(), vector.at(), swap()



    // 2-D Array -

    vector<vector<int>> arr(5, vector<int>(4, 0));
    int totalRows = arr.size();
    int totalCols = arr[0].size();

    // 2-D Array of different Col Size
    vector<vector<int>> brr(4);
    brr[0] = vector<int>(4);
    brr[1] = vector<int>(2);
    brr[2] = vector<int>(5);
    brr[3] = vector<int>(3);

}

*/

/*

// Linked List

#include <list>
int main()
{

    list<int> mylist;

    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_back(40);
    mylist.push_back(50);
    mylist.push_front(5);

    // All Methods
    // begin(), end(), size(), empty(),front(), back(), push_back( val), pop_back(),
    // insert(itterator pos, val), erase(iterator position), clear(),swap(list& x),
    // pop_front(), remove(Val)
}

*/

/*
// Queue

#include <queue>
int main()
{
    // FIFO
    queue<int> qu;

    // All Methods
    // empty(), size(), front(), back(), push(val), pop(), swap(queue& x)
}

*/

/*
// Stack

#include <stack>
int main()
{

    // LIFO

    // All Methods
    // empty(), size(), top(), push(val), pop(), swap(stack& x)
}

*/

/*
// Dequeue (Doubly Queue)

#include <deque>

int main()
{
    // Main difference is we can insert and pop from both front and back
}
*/

/*

// Priority Queue


#include <queue>
int main()
{
    priority_queue<int> pq;
    // max_heap

    // top element is always the highest priority and while popping the top element will be popped
    pq.push(10);
    pq.push(55);
    pq.push(23);
    pq.push(98); // highest priority
    pq.push(67);

    // All Methods
    // empty(), size(), top(), push(val), pop(), swap(priority_queue& x)

    // similarily min Heap
    priority_queue<int, vector<int>, greater<int>> mnheap;


}

*/

/*

// MAP

#include <map>
int main()
{
    // ordered, unordered

    // unordered map takes O(constant) time for all operation
    // ordered mao takes O(logn) time for all operation
}
*/

// Set (ordered and unordered_set)