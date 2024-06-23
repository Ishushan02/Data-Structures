#include <iostream>

using namespace std;

/*

Given  a sorted array arr[] of size N, some elements of arr are
moved to either of the adjacent positions, i.e arr[i] may be
present at arr[i+1] or at arr[i-1] i.e arr[i] can only be swaped
with either arr[i+1] or arr[i-1]. The task is to search for an
element in this array.

// Inp Array arr[]={10,3,40,20,50,80,70}, key = 40
Output = 2 (index of 40)

// Inp Array arr[]={10,3,40,20,50,80,70}, key = 90
Output = -1

*/
