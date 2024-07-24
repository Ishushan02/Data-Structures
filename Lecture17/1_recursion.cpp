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

int fibonacci(int n ){
    if(n == 0 ){
        return 0;
    }else if (n == 1){
        return 1;
    }
    
    return fibonacci(n-1) + fibonacci(n - 2);
}

int main()
{

    // cout << factorial(6) << endl;
    // print(10);
    // cout << pow2(5) << endl;

    cout << fibonacci(11) << endl;
}