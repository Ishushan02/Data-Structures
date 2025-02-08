#include <iostream>

using namespace std;

int main()
{
    /*
    cout << "Namaste Duniya " << endl;
    cout << "End next line "
         << "\n";
    */

    // input a character
    // 'a' - 'z' then OP "Lower Case"
    // 'A' - 'Z' then OP "Upper Case"
    // '0' - '9' then OP "Numeric Case"

    char c;

    cin >> c;

    if ((c >= 97) && (c <= 122))
    {
        cout << "Lower case" << endl;
    }
    else if ((c >= 65) && (c <= 90))
    {
        cout << "Upper case" << endl;
    }
    else if ((c >= 48) && (c <= 57))
    {
        cout << "Numeric Case" << endl;
    }
    else
    {
        cout << "Not in Scope" << endl;
    }
    return 0;
}