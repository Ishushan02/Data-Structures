#include <iostream>

using namespace std;

int main()
{

    // sum of till n even numbers

    int n;
    cin >> n;
    int sum = 0;
    int i = 1;

    while (i < n)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }

        i += 1;
    }

    cout << "Sum is " << sum << endl;
}