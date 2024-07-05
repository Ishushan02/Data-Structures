#include <iostream>

using namespace std;

int main()
{

    char array[100];

    // Taking IP this way
    // for (int i = 0;i<100;i++){
    //     cin >> array[i];
    // }

    // cin >> array;

    // if you give your name and then space follwed by other name it won't take the 2nd name
    // because in char array the delimeter is set as space/enter/tab
    // cout << " Name is " << array << endl;

    // Printingall chars 1 by 1
    // cout << array[0] << endl;
    // cout << array[1] << endl;
    // cout << array[2] << endl;
    // cout << array[3] << endl;
    // cout << array[4] << endl;
    // cout << array[5] << endl;

    // After the ip is completed the Null character is entered by default

    // take input including spaces
    cin.getline(array, 100);
    cout << " Name is " << array << endl;

    // other way to take input with defined delimeter
    // cin.getline(array, 100, '\t');

    // finding length of character in char array

    // int count = 0;
    // for (int i = 0; i < 100; i++)
    // {
    //     if ((int)array[i] == 0) // searching for null character or (array[i] != '\0')
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         count += 1;
    //     }
    // }
    // cout << " The length of characters are " << count << endl;

    // Replace characters
    // loop it and replace easily

    // Upper to Lower and lower to upper
    // 'A' --> 'a'
    // We can do this by let say ch contains character
    // ch = ch - 'a' + 'A' (or)
    // remember the ascii characters 'a' -> 97, 'A' -> 65

    // for(int i = 0; i < 100;i++){
    //     char ch = array[i];
    //     if (ch >= 'a' && ch <= 'z'){
    //         ch = ch - 'a' + 'A';
    //     }
    //     array[i] = ch;
    // }
    // cout << " Capital Name is " << array << endl;

    // Reverse the characters (use 2 pointers and do)

    // Check whther a string is Palindrome or not

    // Strings
    string s;

    // s.push_back(),
    // getline(cin, s, '\n'); // expects a string in as input

    // some imp functions
    // s.at(index), s.front(), s.back(), s.length(), s.empty(), s.clear(), s.substr(start index, end index)
    // s.find("word"), s1.compare(s2), s.push_back('sa'), s.pop_back()
}