#include <iostream>

using namespace std;

/*
int main()
{
    int val = 1;

    // Nested Switch works fine.
    // The condition cannot be string or float value
    // We can only put int, char, expression in conditions.
    // exit() function helps in skipping the loops.

    switch (val)
    {
    case 1:
        cout << "First Statement" << endl;
        break;

    case 2:
        cout << "Second Statement" << endl;
        break;

    case 3:
        cout << "Third Statement" << endl;
        break;

    default:
        cout << "Default Case " << endl;
        break;
    }
}
*/

/*
    You have been given a amount n,
    Now, you have (100, 50, 20, 1 --> rupees notes)
    find the total number of each notes required to complete the amount n;
*/

int main()
{
    int n = 6678;
    int value = 0;

    while (n != 0)
    {
        int r;

        if (n > 100)
        {
            r = 100;
        }
        else if (n > 50)
        {
            r = 50;
        }
        else if (n > 20)
        {
            r = 20;
        }
        else
        {
            r = 1;
        }

        switch (r)
        {
        case 100:
        {
            value = n / 100;
            n = n % 100;
            cout << "It required " << value << " notes of 100 " << endl;
            break;
        }

        case 50:
        {
            value = n / 50;
            n = n % 50;
            cout << "It required " << value << " notes of 50 " << endl;
            break;
        }

        case 20:
        {
            value = n / 20;
            n = n % 20;
            cout << "It required " << value << " notes of 20 " << endl;
            break;
        }

        case 1:
        {
            value = n / 1;
            n = n % 1;
            cout << "It required " << value << " notes of 1 " << endl;
            break;
        }
        }
    }
}