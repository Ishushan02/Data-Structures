#include <iostream>

using namespace std;

/*
sort 0's and 1's --> [0, 1, 1, 0, 0, 1, 1]

It's simple try it or else see Lect 10 1.cpp
*/

/*
OR Dutch National Flag
sort 0's, 1's, 2's --> [1, 0, 0, 2, 1, 1, 2, 2, 0, 1, 0]

// Method 1

int main()
{
    int n = 10;
    int arr[10] = {0, 0, 2, 1, 1, 2, 2, 0, 0, 0};

    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;

    for(int i = 0; i <= 10; i++)
    {
        if (arr[i] == 0)
        {
            zerocount++;
        }
        if (arr[i] == 1)
        {
            onecount++;
        }
        if (arr[i] == 2)
        {
            twocount++;
        }
    }

    cout << onecount << " " << onecount << " " << twocount << " " << endl;

    fill(arr, arr + zerocount, 0);
    fill(arr + zerocount, arr + onecount, 1);
    fill(arr + onecount, arr + twocount, 2);

    cout << "Sorted Array " << " ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


// 2nd method see in Array 6_problems.cpp last  question
{
    75. Sort Colors
    (https://leetcode.com/problems/sort-colors/description/)
    // Important Question do it practise it

    void sortColors(vector<int>& nums) {
        
        int start = 0;
        int mid = 0;
        int end = nums.size() -1 ;

        while(mid <= end){

            if(nums[mid] == 1){
                mid++;
            }else if(nums[mid] == 0){
                swap(nums[start], nums[mid]);
                mid++;
                start++;
            }else{
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
}

*/

/*
    189. Rotate Array
    (https://leetcode.com/problems/rotate-array/)

    void reverse(vector<int> & nums, int start, int end){

        while(start <= end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if(nums.size() < k){
            k = k % nums.size();
            // for smaller arr size elements
        }
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
        
    }

*/



/*
Rotate An Array by any index

Array - [1, 2, 3, 4, 5, 6, 7]
index 1 -> [7, 1, 2, 3, 4, 5, 6]
index 2 -> [6, 7, 1, 2, 3, 4, 5]
....

int main()
{

    int n = 7;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int window = 2;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        int shift = i + window;
        if (shift > n - 1)
        {
            shift = shift - n; // shift % n would also work
            ans[shift] = arr[i];
        }
        else
        {
            ans[shift] = arr[i];
        }
    }

    cout << "The ROtated Array is " << " ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

*/


