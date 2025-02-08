#include <iostream>
#include <algorithm>

using namespace std;

/*
    Swap alternate Numbers
    [1, 7, 2, 3, 9] -> [7, 1, 3, 2, 9]
    [6, 8, 3, 7, 5, 15] -> [8, 6, 7, 3, 15, 5]

int main()
{
    int arr[6] = {7, 89, 3, 6, 45, 63}; // [78, 95, 47, 35, 15]
    int i = 0;
    int n = sizeof(arr) / sizeof(int);
    while (i < n)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;

        // we can use swap(arr[i], arr[i+1])

        i = i + 2;
    }

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}

*/

/*
Given an integer array list of size N,
(ishan94725)
Coding Ninjas - https://www.codingninjas.com/studio/problems/find-unique_625159?interviewProblemRedirection=true




// Method1 Brute Force Approach
// int findUnique(int *arr, int size)
// {
//     if (size ==1){
//         return arr[0];
//     }
//     int i = 0;

//     while(i<size){
//         int count = 1;
//         int j = i+1;
//         while(j<size){
//             if (arr[j]==arr[i]){
//                 count = count+1;
//             }
//         }

//         if (count == 1){
//             return arr[i];
//         }
//     }
// }

// Method 2 Ex-OR Operation
int main()
{
    // If we do ex-or operation of all number
    // a^a = 0
    // so all 2 M elements will get cancel to each other
    int size = 5;
    int arr[size] = {7, 9, 8, 7, 9};
    int ans = arr[0];
    int i = 1;
    while (i < size)
    {
        ans = ans ^ arr[i];
        i++;
    }

    return ans;
}

*/

/*
LeetCode - Unique Occurence of a Number
// 1207 - https://leetcode.com/problems/unique-number-of-occurrences/description/

*/

/*
Duplicate In Array - https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?interviewProblemRedirection=true&leftPanelTabValue=SUBMISSION

// Method 1 (Best Solution Maths)
int findDuplicate(vector<int> &arr)
{
    // Write your code here
    int n = size(arr);
    int sumn1 = ((n) * (n-1)) / 2;

    int sumarr = 0;

    for (int i =0;i<n;i++){
        sumarr = sumarr + arr[i];
    }

    return sumarr - sumn1 ;

}
*/

/*
// Method2 (Ex-OR Operation)

int main()
{

    // Let's say we have given arr [1, 2, ..... X, .... , N-1, X] X is repeated
    // if we do ex-or Operation (from 1 to N-1 and given array) then we will have X 3 times which will gve the output

    // step 1 -- Ex-OR of given array -->ans
    // step 2 Ex-OR of (1,....,N-1) with the given prev ans
    // the desired result will be (0 ^ 0 .... ^ X ^ X ^ X ) --> X

    int arr[5] = {1, 3, 4, 2, 1};
    int ans = 0;
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        ans = ans ^ i;
    }
}

*/

/*
Leetcode - Find all Duplicate in an Array
442 - https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// The Procedure would be like this.
    [2, 5, 2, 1, 1, 4] --> O/P [1, 2]
    [1, 2, 2, 3, 4, 4] --> O/P [2, 4]

basic idea is switch on and switch off the switch if its aready off then we dont have to off it again

    arr = [2, 5, 2, 1, 1, 4]

    start i = 0
    arr elem is 2 then index will be 2-1 = 1
    switch off arr[1] (here do it by mutliplying -1)
    updated arr = [2, -5, 2, 1, 1, 4]

    i = 1
    arr elem is 5 then index will be 5-1 = 4
    switch off arr[4] (here do it by mutliplying -1)
    updated arr = [2, -5, 2, 1, -1, 4]

    i = 2
    arr elem is 2 then index will be 2-1 = 1
    arr[1] is already off (negative elem) so write that element to OP arr ----------> 2
    present arr = [2, -5, 2, 1, -1, 4]

    i = 3
    arr elem is 5 then index will be 1-1 = 0
    switch off arr[0] (here do it by mutliplying -1)
    updated arr = [-2, -5, 2, 1, -1, 4]

    i = 4
    arr elem is 5 then index will be 1-1 = 0 (always do abs(key) - 1)
    arr[0] is already off (negative elem) so write that element to OP arr ----------> 1
    present arr = [-2, -5, 2, 1, -1, 4]

    .
    .
    .

vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int> ans;

        while (i < n) {

            int key = abs(nums[i]) - 1 ;
            int val = nums[key];

            if (val < 0){
                ans.push_back(abs(nums[i]));
            }else{
                nums[key] = -1*val;
            }
            i++;
        }

        return ans;

    }

*/

/*
Intersection of Sorted Array - https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM


//Method 1 (using normal brute force approach)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    vector<int> ans;
    for (int i = 0;i < n;i++){
        for (int j = 0;j<m;j++){
            if (arr1[i] == arr2[j]) {
                arr2[j] =  -1;
                ans.push_back(arr1[i]);
                break;
            }
        }
    }

    return ans;
}


Method2 (Pointer Method --Efficient Method)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < n && j <m){
        if (arr1[i] < arr2[j] ){
            i=i+1;
        }
        else if (arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i=i+1;
            j=j+1;
        }
        else if (arr1[i] > arr2[j]){
            j=j+1;
        }
    }
    return ans;
}



*/

/*
PAIR SUM - https://www.codingninjas.com/studio/problems/pair-sum_697295?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM

//Easy way just by Brute force approach
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;

   for (int i =0;i < arr.size();i++){
      for (int j = i+1;j<arr.size();j++){
         if (arr[i]+arr[j] == s){
            vector<int> temp;
            temp.push_back(min(arr[i], arr[j]));
            temp.push_back(max(arr[i], arr[j]));
            ans.push_back(temp);
         }
      }
   }

   sort(ans.begin(), ans.end());
   return ans;

}
*/

/*
Sort O 1 - https://www.codingninjas.com/studio/problems/sort-0-1_624379?interviewProblemRedirection=true&leftPanelTabValue=SUBMISSION

[1, 1, 0, 0, 0, 1] -- > [0, 0, 0, 1, 1, 1]
pointers i = 0 and j = n-1

if arr[i] == 0 --> i++
if arr[j] == 0 --> j--
if arr[i]==1 and arr[j] ==0 --> Swap (0,1)



void sortZeroesAndOne(int input[], int size)
{
    //Write your code here
    int i = 0;
    int j = size - 1;

    while (i < j){
        if (input[i] == 1 && input[j] == 0){
            input[j] = 1;
            input[i] = 0;
            i++;
            j--;
        }
        else if (input[i] == 0){
            i++;
        }
        else if (input[j] == 1){
            j--;
        }
    }
}
*/

/*
Sort 0 1 2 array

so the basic idea is to keep 0 at left most 1 in between and 2 at the end

logic is
start = 0, mid = 0, end = n -1

if arr[mid]==1 --> mid++
elseif arr[mid]==0 --> swap(arr[start], arr[mid]), start++, mid++
else --> swap(arr[mid], arr[end]), end-- //as mid would be 2

#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
   //   Write your code here

   int start = 0;
   int mid = 0;
   int end = n-1;

   while(mid <= end){
      if (arr[mid] == 1){
         mid++;
      }else if(arr[mid] == 0) {
         int temp = arr[mid];
         arr[mid] = arr[start];
         arr[start] = temp;
         mid++;
         start++;
      }else{
         int temp = arr[mid];
         arr[mid] = arr[end];
         arr[end] = temp;
         end--;
      }
   }
}


*/