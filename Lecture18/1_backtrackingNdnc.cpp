#include <iostream>
#include <vector>
using  namespace std;

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

    if( i < n1 ){
        while(i < n1){
            res.push_back(arr1[i]);
            i++;
        }
    }else{    
        while(j < n2){
            res.push_back(arr1[j]);
            j++;
        }
    }
}



int main(){
    int arr1[] = {1, 11, 17, 38, 45, 70};
    int arr2[] = {2, 8, 15, 18, 24, 30, 34, 48};
    int n1 = 6;
    int n2 = 8;

    vector<int> res;
    mergeSort(arr1, n1, arr2, n2, res);

    cout << " Merge Sort Sorted Arrays " << endl;
    for(auto i : res){
        cout << i << " ";
    }

}