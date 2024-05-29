#include <iostream>
using namespace std;

/*
Find 2 complement of a given binary number


2's complement ==> 1's complement  followed by addition of 1

11011010

1's complement -> 00100101
2's complement ->      + 1
                 _________
                  00100110

int binary 1 + 0 = 0, 1 + 1 = 10, 1+1+1 = 11;

Pseudocode to find it

arr1, contains 1 number
invert it (take 1's complement)

initially
carry=1
sum = arr1[i] + carry
ans[i] = sum % 2; we get the result
carry = sum / 2;

Example of answer and carry because that is confusing
1 + 1 = 2(in decimal) ----to binary ---->  2 % 2 = 0 (ans), 2/2 = 1 (carry)
1 + 0 = 1(in decimal) ----to binary ---->  1 % 2 = 1 (ans), 1/2 = 0 (carry)
1+1+1 = 3(in decimal) ----to binary ---->  3 % 2 = 1 (ans), 3/2 = 1 (carry)



*/

/*
int main()
{
    int arr[] = {0, 1, 0, 0};

    cout << "Array Initially " << " ";
    for (int i = 3; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    // for 1's complement
    for (int i = 0; i < 4; i++)
    {
        arr[i] = !(arr[i]);
    }

    cout << endl;
    cout << "Array after 1's complement" << " ";
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    // adding 1
    int sum = 0;
    int carry = 1;
    int ans[] = {0, 0, 0, 0};

    for (int i = 3; i >= 0; i--)
    {
        sum = ans[i] + arr[i] + carry;
        ans[i] = sum % 2;
        carry = sum / 2;
    }
    cout << "Array after 2's complement" << " ";

    for (int i = 0; i < 4; i++)
    {
        // cout << i;
        cout << ans[i] << " ";
    }
}

*/

/*
Rotate a Matrix
 Procedure
 1. Transpose
 2. Reverse each Row

//  https://leetcode.com/problems/rotate-image/submissions/1270482576/

void rotate(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        //transpose
        for (int i = 0;i<row;i++){
            for (int j = i;j<col;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse row wise
        for (int i = 0;i<row;i++){
            // vector<int> row_arr = matrix[i];
            reverse( matrix[i].begin(),  matrix[i].end());
            // reverse_array(row_arr);

        }

    }

*/

/*
KADANE's Algorithm

// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int>& nums) {
        int max_sum  = INT_MIN;
        int sum = 0;

        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
            max_sum = max(max_sum, sum);

            if (sum<0){
                sum = 0;
            }

        }

        return max_sum;
    }
*/