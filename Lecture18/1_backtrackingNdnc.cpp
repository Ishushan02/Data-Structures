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

// -----------------------------------------------------------------------------------------------------


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



// -----------------------------------------------------------------------------------------------------



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



// -----------------------------------------------------------------------------------------------------



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

/*

Backtracking -----------------

Backtracking will search for all possible solutions
but will never explore the solutions again which he
has already explored.

We discard the solutions which we have already explored.

Majority of the Backtracking are solved using Brute FOrce APproach

Famous Problems
 - Rat in a Maze Problem
 - Permutation
 - N Queens Problem
 - Sudoko SOlver

*/


/*

Rat in a Maze - Good Question
(https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

    bool safePos(vector<vector<int>>& mat, vector<vector<bool>>& visited, 
    int x,  int y, int n){
        if(x < 0 || x >= n || y < 0 || y >= n){
            return false;
        }    
        
        if(mat[x][y] == 0 || visited[x][y] == true){
            return false;
        }
        
        return true;
    }
  
    void traverse(vector<vector<int>>& mat, vector<vector<bool>>& visited, int currentRow, 
    int currentCol, string sol, vector<string>& ans, int n){
        
        if(currentRow == n -1 && currentCol == n -1){
            ans.push_back(sol);
            return;
        }
        
        // moveRight
        int x = currentRow;
        int y = currentCol + 1;
        if(safePos(mat, visited, x, y, n)){
            visited[x][y] = true;
            traverse(mat, visited, x, y, sol+"R", ans, n);
            visited[x][y] = false;
            
        }
        
        // moveLeft
        x = currentRow;
        y = currentCol - 1;
        if(safePos(mat, visited, x, y, n)){
            visited[x][y] = true;
            traverse(mat, visited, x, y, sol+"L", ans, n);
            visited[x][y] = false;
            
        }
        
        // moveUp
        x = currentRow - 1;
        y = currentCol;
        if(safePos(mat, visited, x, y, n)){
            visited[x][y] = true;
            traverse(mat, visited, x, y, sol+"U", ans, n);
            visited[x][y] = false;
            
        }
        
        // moveDown
        x = currentRow + 1;
        y = currentCol;
        if(safePos(mat, visited, x, y, n)){
            visited[x][y] = true;
            traverse(mat, visited, x, y, sol+"D", ans, n);
            visited[x][y] = false;
            
        }
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat[0].size();
        int x = 0;
        int y = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<string> ans;
        string sol;
        if(mat[0][0]==0) return ans;
        visited[x][y] = true;
        traverse(mat, visited, x, y, sol, ans, n);
        
        return ans;
    }



    / --------------------------------------------------------------------------------

    // The Above FUnction can also be written in 

    void traverse(vector<vector<int>>& mat, vector<vector<bool>>& visited, int currentRow, 
    int currentCol, string sol, vector<string>& ans, int n){
        
        if(currentRow == n -1 && currentCol == n -1){
            ans.push_back(sol);
            return;
        }
        
        int x_movement[] = {0, 0, -1, 1};
        int y_movement[] = {1, -1, 0, 0};
        string direction[] = {"R", "L", "U", "D"};
        
        for(int i = 0; i < 4;i++){
            int newx = currentRow + x_movement[i];
            int newy = currentCol + y_movement[i];
            string dir = direction[i];
            if(safePos(mat, visited, newx, newy, n)){
                visited[newx][newy] = true;
                traverse(mat, visited, newx, newy, sol+dir, ans, n);
                visited[newx][newy] = false;
                
            }
        }

    }

*/


/*

Permutation of String

    void solvePerm(string S, int start, int end, vector<string>& ans){
        if(start >= end){
            ans.push_back(S);
            return;
        }
        
        
        for(int i = start; i <= end; i++){
            swap(S[start], S[i]);
            solvePerm(S, start + 1, end,  ans);
            swap(S[start], S[i]);
        }
    }
    
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    
		    solvePerm(S, 0, S.length() - 1, ans);
		    
		    return ans;
		}

*/

/*

46. Permutations
(https://leetcode.com/problems/permutations/)

    void move(vector<int>&nums, vector<vector<int>>& ans, int start, int end){
        if(start == end){
            ans.push_back(nums);
            return;
        }

        for(int i = start; i <= end; i++){
            swap(nums[i], nums[start]);
            move(nums, ans, start+1, end);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        move(nums, ans, 0, nums.size()-1);
        return ans;
    }

*/