#include <iostream>

using namespace std;

/*

1, 7, 9, 2, 3, 10, 0

1  7, 9, 2, 3, 10, 0 (1<7 do nothing)
*  *

1 7  9 2 3 10 0    (9> 7 do nothing)
  *  *

1 7 9 2 3 10 0   (2 < 9 swap)
    * * 

1 7 2 9 3 10 0  (3 < 9 swap)
      * *
1 7 2 3 9 10 0  (10 > 9 do nothing)
        * *

1 7 2 3 9 10 0  (0 < 10 swap)
          *  *

1 7 2 3 9 0 10 (1st round completed)

// after every round each max element will be at it's place

// similarily keep doing this now till n-1 elements and then after 2nd round till n-2 elements ...
as the last that  many numbers of elements will be sorted
*/


int main()
{

    int nums[7] = {1, 7, 9, 2, 3, 10, 0};
    int n = 7;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j+1], nums[j]);
            }
        }
    }

    // array is sorted

    for (int i = 0; i < 7; i++)
    {
        cout << nums[i] << " ";
    }
}