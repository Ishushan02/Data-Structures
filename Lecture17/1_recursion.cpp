#include <iostream>
using namespace std;
/*

    just solve for 1 Case
    rest recursion will take care
    Recursion has 3 components
      - Base Condition (MANDATORY)
      - Recursive call (Mandotory)
      - Processing (the computation/ optional)

*/

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int ans = n * factorial(n - 1);

    return ans;
}

void print(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    print(n - 1);
}

int pow2(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return 2 * pow2(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printarr(int arr[], int size, int index)
{
    if (index == size)
    {
        return;
    }
    cout << arr[index] << " ";
    printarr(arr, size, index + 1);
}

int maxInArr(int arr[], int index, int size, int max)
{
    if (index == size)
    {
        return max;
    }
    if (max < arr[index])
    {
        max = arr[index];
    }
    int maxelem = maxInArr(arr, index + 1, size, max);
    return maxelem;
}

bool BinarySearch(int arr[], int low, int high, int target)
{
    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return true;
    }
    if (low > high)
    {
        return false;
    }

    if (arr[mid] > target)
    {
        return BinarySearch(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        return BinarySearch(arr, mid + 1, high, target);
    }
}

void printdigit(int num)
{

    if (num == 0)
    {
        return;
    }

    printdigit(num / 10);
    cout << num % 10 << " ";
}

int main()
{

    // cout << factorial(6) << endl;
    // print(10);
    // cout << pow2(5) << endl;
    // cout << fibonacci(11) << endl;

    // int arr[] = {10, 30, 54, 98, 25};
    // int index = 0;
    // printarr(arr, 5, index);

    // int arr[] = {10, 30, 54, 98, 25};
    // cout << " Max Elem " << maxInArr(arr, 0, 5, -1) << endl;

    // int arr[] = {10, 30, 54, 98, 105};
    // cout << " Elem 540 is present  " << BinarySearch(arr, 0, 4, 540) << endl;

    printdigit(89756);
}