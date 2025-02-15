#include <iostream>
using namespace std;

int main(){
    
}


/*
    48. Rotate Image
    (https://leetcode.com/problems/rotate-image/description/)

    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int i = 0;
        int j = n - 1;

        while(i < j){

            for(int row = 0; row < n; row++){
                swap(matrix[row][i], matrix[row][j]);
            }
            i++;
            j--;
        }


    }

*/


/*
    90 = transpose + reverse row
    180 = reverse row + reverse column
    270 = transpose + reverse col
*/