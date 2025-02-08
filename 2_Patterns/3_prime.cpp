#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 2;
    while (i < n)
    {
        if (n % i == 0)
        {
            cout << "Not a Prime" << endl;
            return 0;
        }
        ++i;
    }

    cout << "It is a prime Number" << endl;

    return 0;
}