/*
  - Binary search are only applied on Monotnic functions
    // So, the array or elements should be either in increasing or decreasing order

  Ex -  arr = [3, 5, 9, 13, 27] key to search = 13

  - now find the mid element (9)
  - is key=9 or key > 9 or key<9 (key=13 > 9)
  - so (key>9) then go right (if less key<9 than go left)
  - repeat from 1st step
*/

#include <iostream>

using namespace std;

int binary_search(int arr[], int size, int key)
{
  int start = 0;
  int end = size - 1;
  int mid = (start + ((end - start) / 2)); // same as (start + end) / 2;, see down for explanation

  while (start <= end)
  {
    cout << "Start is " << start << ", Mid is " << mid << ", end is " << end << endl;

    if (key > arr[mid])
    {
      // move right
      start = mid + 1;
    }
    else if (key < arr[mid])
    {
      // move left
      end = mid - 1;
    }
    else
    {
      return mid;
    }

    mid = (start + ((end - start) / 2)); // same as (start + end) / 2;, see down for explanation
  }
  return -1;
}

int main()
{

  int arr[7] = {1, 3, 7, 9, 12, 14, 16};
  int key = 16;

  int index = binary_search(arr, 7, key);

  cout << "The element " << key << " is found at " << index;
}

#include <algorithm>

/*
int inbuilt_function(){
  binary_search(arr, arr+n, key)
}
*/

/*
There is a catch in while finding mid

So, let's say mid = (start+end)/2

if start = 2^31 -1 and end = 2^31-1
hence while calculating mid = (start +end)/2, the start + end will be more than 2^31
which is greater than INT_MAX;

hence it's better to upadte as
mid = (start + (end-start)/2) --> this wont limit the case

*/

/*
Time Complexity
Size of Array goes on decreasing till 1 untill the element is found so,
let initial size be N
N --> N/2 --> N/4 --> N/8 --> N/16 --> N/32 ....... N/2^k (when element is found)

so when element is found the length of array = 1 at iteration n/2^k
1 = n/2^k
2^k = n
hence, k = logn is the time complexity of binary search
*/