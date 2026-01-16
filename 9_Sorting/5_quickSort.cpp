#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int> &arr, int start, int end){
    if(start >= end) return ;
    int i = start-1;
    int j = start;
    int pivot = end;

    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i += 1;
            swap(arr[i], arr[j]);
        }
        j += 1;
    }
    i += 1;
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);

}

vector<int> sortArray(vector<int>& nums) {
    
    int n = nums.size();
    quickSort(nums, 0, n-1);

    return nums;
}