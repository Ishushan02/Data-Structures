#include <iostream>

using namespace std;

/*
int main()
{

    int arr[10] = {5, 7, -2, 10, 22, 12, 0, 5, 22, 1};
    // Linear Search for 1
    int n = 1;

    for (int i = 0; i < 10; i++)
    {

        if (arr[i] == n)
        {
            cout << "Got the value " << n << " at index " << i;
        }
    }
}

*/

/*
Reverse an array
*/

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int i = 0;
    int temp = 9999;
    int n = 5;
    while (i < n / 2)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
        // n = n + 1;
        i = i + 1;
    }

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}