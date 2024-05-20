#include <iostream>

using namespace std;

// Numeric Hollow Pyramid

// 1
// 1 2
// 1   3
// 1     4
// 1 2 3 4 5

// int main()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (j == 0 || (i == j) || (i == 4))
//             {
//                 cout << j + 1 << "";
//             }
//             else
//             {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }
// }

// ********1********
// *******2*2*******
// ******3*3*3******
// *****4*4*4*4*****
// ****5*5*5*5*5****

// int main()
// {

//     int row = 0;
//     int n = 9;
//     while (row < 5)
//     {
//         int temp = n;
//         int i = row;
//         while (temp - i-1)
//         {
//             cout << "*";
//             i++;
//         }

//         bool flag = true;
//         int digits = 2*row + 1;
//         i = row;
//         while(digits){
//             if (flag){
//                 cout<<i+1;
//                 flag = false;
//             }else{
//                 cout<<"*";
//                 flag = true;
//             }
//             digits--;
//         }

//           temp = n;
//          i = row;
//         while (temp - i-1)
//         {
//             cout << "*";
//             i++;
//         }

//         cout << "" << endl;

//         row++;
//     }
// }

// 1
// 2*3
// 4*5*6
// 7*8*9*10
// 7*8*9*10
// 4*5*6
// 2*3
// 1

// int main()
// {

//     int n = 0;
//     int num = 1;

//     while (n < 4)
//     {

//         int j = (2 * n + 1);
//         bool flag = true;
//         while (j)
//         {
//             if (flag)
//             {
//                 cout << num;
//                 flag = false;
//                 num++;
//             }
//             else
//             {
//                 cout << "*";
//                 flag = true;
//             }
//             // cout << "*";
//             j--;
//         }

//         cout << "" << endl;
//         n++;
//     }

//     n = 4;
//     int fval = num;
//     while (n > 0)
//     {
//         fval--;
//         fval = fval - n +1;
//         int data = fval;
//         int j = (2 * n - 1);
//         bool flag = true;
//         while (j>0)
//         {

//             if (flag)
//             {
//                 cout << data;
//                 flag = false;
//                 data++;
//             }
//             else
//             {
//                 cout << "*";
//                 flag = true;
//             }
//             // cout << "*";
//             j--;
//         }
//         cout << "" << endl;
//         n--;
//     }
// }

/*
Pascals Triangle (VERY IMPORTANT)

          1
          1  1
          1  2  1
          1  3  3  1
          1  4  6  4  1
          1  5  10  10  5  1
          1  6  15  20  15  6  1

        c  =  c * (i - j) / j
        i = [1, n]
        j = [1, i]

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        int C = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << C << "";
            C = C * (i - j) / j;
        }
        cout << endl;
    }
}

*/

// ----------------------- Home Work -------------------------- //
// *
// *1*
// *121*
// *12321*
// *121*
// *1*
// *

// int main()
// {
//     int n = 4;

//     for (int i = 1; i <= n; i++)
//     {

//         int C = 1;
//         for (int j = 1; j <= i; j++)
//         {
//             if (j == 1)
//             {
//                 cout << "*" << "";
//             }
//             cout << C << "";
//             if ((i == j) & (i != 1))
//             {
//                 cout << "*" << "";
//             }
//             C = C * (i - j) / j;
//         }
//         cout << endl;
//     }
//     cout << "*" << "";
// }

// 1 miles = 1.60934 km
//  Kelvin - Celcius = 273.15 ; Farenhit = Celcius * 1.8 +  32

