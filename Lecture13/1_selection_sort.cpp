#include <iostream>

using namespace std;

/*

1, 7, 9, 2, 3, 10, 0

1 | 7, 9, 2, 3, 10, 0 (min is 0 swap 1 and 0)
*

0 7 | 9 2 3 10 1    (min is 1 swap 7 and 1)
  *

0 1 9 | 2 3 10 7   (min is 2 swap 9 and 2)
    *

0 1 2 9 | 3 10 7  (min is 3 swap 9 and 3)
      *

0 1 2 3 9 | 10 7  (min is 7 swap 7 and 9)
        *

0 1 2 3 7 9 | 10 (min is 9 swap 9 with 9)
          *

0 1 2 3 7 9 10 (sorted array)

*/

// Use selection sort when size of array is small

int main()
{

    int arr[7] = {1, 7, 9, 2, 3, 10, 0};

    int minindex = 0;

    for (int i = 0; i < 7 - 1; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }

    // array is sorted

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}