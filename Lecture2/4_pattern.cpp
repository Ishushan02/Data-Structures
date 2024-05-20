#include <iostream>

using namespace std;

/*
Output should be
* * * *
* * * *
* * * *
* * * *


int main()
{

    int i = 0;
    int j = 0;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            cout << "* "
                 << "\t";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}

*/

/*
OP
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

int main()
{

    int i = 0;
    int j = 0;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            cout << j + 1 << " "
                 << "\t";
            j++;
        }
        ++i;
        cout << endl;
    }
    return 0;
}


*/

/*
Output is
 given n
3 2 1
3 2 1
3 2 1

int main()
{
    int n = 5;

    int i = 0;
    int j = 0;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            cout << n - j << "\t";
            j++;
        }
        ++i;
        cout << endl;
    }
    return 0;
}

*/

/*
Output -

1 2 3
4 5 6
7 8 9

int main()
{

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            cout << count + 1 << "\t";
            ++count;
            ++j;
        }

        cout << endl;
        ++i;
    }
    return 0;
}

*/

/*
Output

Triangle Pattern
*
* *
* * *



int main()
{
    int i = 0;
    int j = 0;

    while (i < 3)
    {
        j = 0;
        while (j < i + 1)
        {
            cout << " * "
                 << "\t";
            ++j;
        }
        cout << endl;
        i++;
    }
}

*/

/*
Output
1
2 3
4 5 6
7 8 9 10



int main()
{
    int count = 1;

    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < i + 1)
        {
            cout << count << "\t";
            ++j;
            count++;
        }
        cout << endl;
        ++i;
    }
    return 0;
}

*/

/*
// Output

// 1
// 2 3
// 3 4 5
// 4 5 6 7



int main()
{

    int i = 0;

    while (i < 5)
    {
        int j = 0;
        while (j < i)
        {
            cout << i + j << "\t";
            ++j;
        }
        cout << endl;
        ++i;
    }

    return 0;
}
*/

/*
Output
1
2 1
3 2 1
4 3 2 1




int main()
{
    int i = 1;
    int n = 4;
    while (i <= n)
    {
        int j = 0;
        int row = i;
        while (j < i)
        {
            cout << row << "\t";
            --row;
            ++j;
        }

        ++i;
        cout << endl;
    }
    return 0;
}

*/

/*
Output

A A A
B B B
C C C


int main()
{
    int i = 0;
    char c = 'A';
    while (i < 3)
    {
        int j = 0;
        while (j < 3)
        {
            cout << c << " ";
            j++;
        }
        cout << endl;
        c++;
        i++;
    }

    return 0;
}

*/

/*

A B C
A B C
A B C


int main()
{
    int i = 0;
    while (i < 3)
    {
        char c = 'A';
        int j = 0;
        while (j < 3)
        {
            cout << c << " ";
            c++;
            j++;
        }

        cout << endl;
        i++;
    }
    return 0;
}

*/

/*
Output
A B C
B C D
C D E


int main()
{

    int i = 0;
    char c = 'A';
    while (i < 3)
    {
        int j = 0;
        char k = c + i;
        while (j < 3)
        {
            cout << k << " ";
            ++k;
            ++j;
        }
        cout << endl;
        ++i;
    }
    return 0;
}

*/

/*
OUTPUT

D
C D
B C D
A B C D



int main()
{

    int i = 0;
    char c = 'D';

    while (i < 4)
    {

        int j = 0;
        char k = c - i;
        while (j <= i)
        {
            cout << k << " ";
            k++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}

*/

/*
Output

      *
    * *
  * * *
* * * *


int main()
{
    int i = 0;
    int n = 4;

    while (i < n)
    {
        int j = 0;
        bool flag = false;
        while (j < n)
        {
            if (j == n - i - 1)
            {
                cout << "*";
                flag = true;
            }
            else if (flag == true)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            ++j;
        }
        cout << endl;
        ++i;
    }

    return 0;
}

*/

/*
Output

****
***
**
*




int main()
{

    int n = 4;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (n - i >= j)
        {
            cout << "*";
            ++j;
        }
        cout << endl;
        ++i;
    }
}

*/

/*
Output
****
 ***
  **
   *


int main()
{

    int i = 0;
    int n = 4;
    while (i < n)
    {
        int j = 0;
        bool flag = false;

        while (j < n)
        {
            if (i == j)
            {
                cout << "*";
                flag = true;
            }
            else if (flag == true)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}

*/

/*
Output
   1
  121
 12321
1234321



int main()
{

    int i = 0;
    int n = 4;

    while (i < n)
    {
        int j = 0;
        int count = 1;
        bool flag = false;

        while (j <= n - 1)
        {

            if (flag == true)
            {
                cout << count;
                ++count;
            }
            else if (j == n - i - 1)
            {
                cout << count;
                flag = true;
                count++;
            }
            else
            {
                cout << " ";
            }
            ++j;
        }

        count = i;

        while (count >= 1)
        {
            cout << count;
            count--;
        }

        cout << endl;
        ++i;
    }
}

*/

int main()
{
    int i = 0;
    int n = 4;

    while (i < n)
    {

        int j = 0;
        int num = 1;
        while (j < n)
        {
            if (i + j >= n - 1)
            {
                cout << num;
                num++;
            }
            else
            {
                cout << " ";
            }

            j++;
        }

        int k = 0;
        // num = num - 1;
        int temp = i;
        while (k < n)
        {
            if (temp != 0)
            {
                cout << temp;
                temp--;
            }
            k++;
        }

        cout << "\n";
        i++;
    }
}

/*
Output
   1
  121
 12321
1234321



int main()
{
    int i = 1;
    int n = 4;

    while (i <= n)
    {

        // print spaces (1st triangle)
        int space = n - i;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }

        // print 2nd triangle
        int j = 1;
        while (j <= i)
        {
            cout << j;
            ++j;
        }

        // printing 3rd triangle
        int left = i;
        while (left > 1)
        {
            cout << left - 1;
            left--;
        }

        cout << endl;
        ++i;
    }

    return 0;
}

*/

/*
OUTPUT
1234554321
1234**4321
123****321
12******21
1********1

*/
/*
int main()
{
    int i = 0;
    int n = 5;

    while (i < n)
    {

        // 1st triangle
        int count = 1;
        int total_row = n - i;
        while (total_row)
        {
            cout << count;
            count = count + 1;
            total_row = total_row - 1;
        }

        // 2d triangle star triangle
        int stars = 2 * i;

        while (stars)
        {
            cout << "*";
            stars = stars - 1;
        }

        // 3rd triangle opposite of 1st
        int last = n - i;

        while (last)
        {
            cout << last;
            last = last - 1;
        }

        cout << endl;
        ++i;
    }

    return 0;
}
*/