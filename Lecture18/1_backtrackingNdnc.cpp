#include <iostream>
#include <vector>
using  namespace std;


/*

    DIVIDE AND CONQUER 

*/


// Merge 2 Sorted Arrays
void mergeSort(int arr1[], int n1, int arr2[], int n2, vector<int> & res ){

    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }else{
            res.push_back(arr2[j]);
            j++;
        }
    }


    while(i < n1){
        res.push_back(arr1[i]);
        i++;
    }
        
    while(j < n2){
        res.push_back(arr2[j]);
        j++;
    }
    
}


// Merge Sort

// merge the given array
void merge(vector<int>& arr, int start, int mid, int end){

    vector<int> ans;
    // we have 2 array's we need to sort that
    int leftarrStart = start;
    int leftarrEnd = mid;
    int rightarrStart = mid+1;
    int rightarrEnd = end;

    while(leftarrStart <= leftarrEnd && rightarrStart <= rightarrEnd){
        if(arr[leftarrStart] < arr[rightarrStart]){
            ans.push_back(arr[leftarrStart]);
            leftarrStart++;
        }else{
            ans.push_back(arr[rightarrStart]);
            rightarrStart++;
        }
    }

    while(leftarrStart <= leftarrEnd){
        ans.push_back(arr[leftarrStart]);
        leftarrStart++;
    }

    while(rightarrStart <= rightarrEnd){
        ans.push_back(arr[rightarrStart]);
        rightarrStart++;
    }

    for(int i = start; i <= end; i++){
        arr[i] = ans[i - start];
    }

}

// divide the given array in 2 parts
void divide(vector<int> & arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start + end) / 2;
    divide(arr, start, mid);
    divide(arr, mid+1, end);
    
    merge(arr, start, mid, end);

}




// Quick Sort {Good Method}

void quickSort(vector<int>& arr, int start, int end){
    
    if (start >= end){
        return;
    }

    int i = start - 1;
    int j = start;
    int pivot = end;

    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    i++;
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i - 1);
    quickSort(arr, i+1, end);

}


int main(){
    // int arr1[] = {1, 11, 17, 38, 45, 70};
    // int arr2[] = {2, 8, 15, 18, 24, 30, 34, 48};
    // int n1 = 6;
    // int n2 = 8;

    // vector<int> res;
    // mergeSort(arr1, n1, arr2, n2, res);

    // cout << " Merge Sort Sorted Arrays " << endl;
    // for(auto i : res){
    //     cout << i << " ";
    // }

    // -------------------------------------------------------------------------------------------

    // vector<int> arr = {98, 43, 19, 10, 90, 63, 12, 1};
    // divide(arr, 0, 7);

    // cout << " Merged Sorted Arrays " << endl;
    // for(auto i : arr){
    //     cout << i << " ";
    // }


    // -------------------------------------------------------------------------------------------

    vector<int> arr = {98, 43, 19, 10, 90, 63, 12, 1};
    quickSort(arr, 0, 7);

    cout << " QuickSort Sorted Arrays " << endl;
    for(auto i : arr){
        cout << i << " ";
    }

}

/*

1 Question
Merge SOrt Performs well in either LinkedList of Array, explain why ?

*/