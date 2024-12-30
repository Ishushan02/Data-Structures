#include<iostream>
#include<map>

using namespace std;
/*

Maps - 
    Ordered Map - Acess(O(logn)), Insert(O(logn)), Delete(O(logn)) -  It is implemented using Balance BST
    Unordered Map - Acess(O(1)), Insert(O(1)), Delete(O(1)) - 
        For Unordered map, it works like array, so whenever we give it a key,
        there will be a hash function which converts the string value into desired integer value
        and then that value will be stored int that index of Array.

        Hash FUnction is combined of hash Code and Compression Function
        fo whenever an unordered map is declared, it will assign a fix size of array,
        next once you give any key value too it the Code part of hash function will 
        conver the key into integer value and upon which the integer value is then
        comressed to the range of that array size, after which on that index the 
        value is stored.

    map.find(key)
    

*/
