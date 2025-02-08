#include <iostream>

using namespace std;

int pow(int a, int b)
{

    int sol = 1;
    for (int i = 1; i <= b; i++)
    {
        sol = sol * a;
    }
    return sol;
}

int factorial(int a)
{
    int ans = 1;
    while (a > 1)
    {
        ans = ans * a;
        a = a - 1;
    }
    return ans;
}

/*
void function(){
    // This function won't return anything as it is a void function
}
*/

int main()
{
    // int a, b;
    // cin >> a >> b;
    // int answer = pow(a, b);
    // cout << "Power of " << a << " and " << b << " is " << answer;

    int fac = factorial(5);

    cout << "Factorial of a Number " << 5 << " is " << fac << endl;
    return 0;
}