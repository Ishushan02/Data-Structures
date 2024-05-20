#include <iostream>
#include <climits>

using namespace std;

/*
int main()
{
    // int a[5];
    // fill_n(a, 5, 2); // initializa with any value
    // int c[15] = {0}; // this will fill entire array with 0 and this only works for 0
    int b[3] = {1, 2, 3};

    int array[5] = {95,
                    45,
                    78,
                    63,
                    84};

    int min = INT_MAX;
    int max = INT_MIN;
    int sumarr = 0;
    for (int i = 0; i < 5; i++)
    {
        sumarr += array[i];
        if (array[i] > max)
        {
            max = array[i];
        }
        // or max(elem1, elem2) inbuilt function
        else if (array[i] < min)
        {
            min = array[i];
        }
        // or min(elem1, elem2) inbuilt function
    }
    cout << "Max is " << max << " Min is " << min << " and Sum is " << sumarr << endl;

    //---------------------------//

    int arr[3];
    fill(arr, arr + 3, 17); // it fills all the elements with same number (start index, end index, value )
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " ";
}

*/

// IMP - lets say if an araay of size 5 and only 2 values are initialized
//  in it what will be rest 3 spaces of array contain, it's 0's and not Grbage Value

/*
Taking Input in Array
*/

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

/*

inc size cin>> size;
int arr[size];

The above code is a bad practise to initialize the array, Memory Allocation Issue

Explanation:


*/

/*
Why any array index begins with 0, why not 1

So, the formula to find element present at index i is [Base Address + size of array data type * i]

ex - Array with vaues   arr[ 10 | 60 | 20 | 63 | 74 | 55 ]
address of above array  400, 404, 408, 412, 416

if i = 1 the  apply the above formula [400 + 4 * 1 ] this gives element 60 and not element 10
hence index always starts with 0

*/

/*
Whenever we pass an array  in function it's address value is always passed so modification
will take place in original array
*/