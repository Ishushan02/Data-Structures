#include <iostream>

using namespace std;

bool checkSorted(int arr[], int n, int index)
{
    if (index == n)
    {
        return true;
    }

    if ((index + 1 < n) && (arr[index] > arr[index + 1]))
    {
        return false;
    }

    return checkSorted(arr, n, index + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 9, 6, 7};
    cout << " arr is sorted or not " << checkSorted(arr, 8, 0) << endl;
}