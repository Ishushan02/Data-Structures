#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int y = 30;

    // condition ? expression_if_true:expression_if_false
    int result = (x > y) ? x : y ;

    (x > y) ? cout << "Can Vote" << endl : cout << "Cannot Vote" <<endl;

    cout << result << endl;
}