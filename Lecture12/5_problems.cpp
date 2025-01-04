#include <iostream>

using namespace std;

// ADVANCED QUESTIONS

/*
Book Allocation Problem
(https://www.naukri.com/code360/problems/allocate-books_1090540?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM)

Question -
- given an arr where ith element represent number of pages (n size of array)
- there are m number of students, and task is to allocate books with given conditions
1.each student get atleast 1 book
2.each book should be allocated to one stdents only
3.Book allocation should be in contiguous manner

Allocate the books to m students such that maximum number of pages assigned to a student is minimum

Ex - [12, 34, 67, 90], m = 2, n = 4
12 | 34 67 90  --> max(12, 191) = 191
12 34 | 67 90  --> max(46, 157) = 157
12 34 67 | 90  --> max(113, 90) = 113

ans is min(191, 157, 113) --> 113

Solution -

if (m>n) -- return -1 ( condition 1)

solution space is (0, total sum of arr)

for any element if division is possible return true or return false
    end = mid-1
else
    start = mid+1


Code -

bool position(vector<int> arr, int n, int m, int mid){
        int pagesum = 0;
        int totalstud = 1;

        for (int i =0;i<n;i++){
            if((pagesum+arr[i]) <= mid){
                pagesum += arr[i];
            }else{
                totalstud++ ;
                pagesum = arr[i];
                if (totalstud > m  || arr[i]>mid){
                    return false;
                }
            }
        }

        return true;
    }


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    int sum = 0;
    if (m>n){
        return -1;
    }
    for (int i = 0;i<n;i++){
        sum+=arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = -1 ;
    int mid = start + (end-start)/2 ;

    while (start <= end ){
        if (position(arr, n, m, mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;

}

*/

/*
Painters Partition Problem
(https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM)

- Same Logic

bool position(vector<int> arr, int n, int m, int mid){
        int pagesum = 0;
        int totalstud = 1;

        for (int i =0;i<n;i++){
            if((pagesum+arr[i]) <= mid){
                pagesum += arr[i];
            }else{
                totalstud++ ;
                pagesum = arr[i];
                if (totalstud > m  || arr[i]>mid){
                    return false;
                }
            }
        }

        return true;
    }



int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    if (k > boards.size()){
        return -1;
    }
    int n = boards.size();
    int m = k;

    int sum = 0;
    if (m>n){
        return -1;
    }
    for (int i = 0;i<n;i++){
        sum+=boards[i];
    }

    int start = 0;
    int end = sum;
    int ans = -1 ;
    int mid = start + (end-start)/2 ;

    while (start <= end ){
        if (position(boards, n, m, mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}


*/

/*

Aggresive Cows -
(https://www.naukri.com/code360/problems/aggressive-cows_1082559?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM)

-Similar Logic (as above both)

bool ispossible(vector<int> &stalls, int k, int mid){
    int lastposition = stalls[0];
    int cowcount = 1;

    for(int i = 0;i< stalls.size();i++){
        if (stalls[i]-lastposition >= mid){
            cowcount++;
            if (cowcount==k){
                return true;
            }
            lastposition = stalls[i];
        }
    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    sort(stalls.begin(), stalls.end());

    int maxi = -1;
    for(int i= 0;i<stalls.size();i++){
        maxi = max(maxi, stalls[i]);
    }
    int ans = -1;
    int start = 0;
    int end = maxi;
    int mid = start +  (end-start)/2;

    while(start<=end){
        if (ispossible(stalls, k, mid)){
            start = mid+1;
            ans = mid;
        }else{
            end = mid-1;
        }
        mid = start +  (end-start)/2;
    }

    return ans;


}

*/