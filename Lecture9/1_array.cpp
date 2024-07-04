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
*/

/*
// Taking Array Input
int n ;
cin>>n;
int * arr = new int[n];
*/

/*

inc size cin>> size;
int arr[size];

The above code is a bad practise to initialize the array, Memory Allocation Issue

Explanation:
Generally RAM is divided into Stack Memory and Heap Memory, Code Segment, initialized Segment, unitialized Segment
...etc and by default Stack is assigned lower Memory and Heap with Higher Memory

so all lower functionalities are done by Stack and Higher memory functionalities are covered by Heap
like variable declaration, function calls, etz --> by Stack hence when you give 10000000 size of the array it
will give Stack Over flow error because the size for it is  assigned very little


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

/*
XOR Swapping

int main()
{
    int a = 5;
    int b = 6;
    cout << "Initially Value of a is " << a << " and b is " << b << endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "After Swapping Value of a is " << a << " and b is " << b << endl;
}

*/

/*
Reverse an Array using 2 pointers

int main()
{

    int arr[6] = {0, 1, 3, 5, 7, 9};

    int start = 0;
    int end = 5;

    while (start <= end)
    {
        // SWAP
        if (start == end)
        {
                }
        else
        {
            arr[start] = arr[start] ^ arr[end];
            arr[end] = arr[start] ^ arr[end];
            arr[start] = arr[start] ^ arr[end];
        }
        start++;
        end--;
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}

*/

/*

EKO SPOJ Problem

#include <iostream>
using namespace std;

bool checkVal(long long int arr[],long long  int n,long long  int k, long long int mid)
{

    long long int diff = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        if (arr[i] < mid)
        {
            temp = arr[i];
        }
        else
        {
            temp = mid;
        }
        diff += abs(arr[i] - temp);
    }

    if (diff >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // your code goes here
    long long int n, k;
    cin >> n;
    cin >> k;
    long long int arr[n];
    long long int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }

    long long int start = 0;
    
    long long int end = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > end)
        {
            end = arr[i];
        }
    }
    long long int mid = (start + end) >> 1;
    int ans = -1;
    
    while (start <= end)
    {
        cout << "Start is " << start << " Mid is " << mid << " End is " << end << endl;

        if (checkVal(arr, n, k, mid))
        {
            ans = (int)mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = (start + end) >> 1;
    }

    cout << ans << endl;
    return ans;
}

*/