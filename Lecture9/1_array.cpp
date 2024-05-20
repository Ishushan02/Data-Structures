#include <iostream>
#include <climits>

using namespace std;

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
    cout << "Max is " << max << " Min is " << min << " and Sum is " << sumarr;
}