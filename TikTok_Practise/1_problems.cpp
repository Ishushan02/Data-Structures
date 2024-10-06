#include <iostream>
#include <vector>

using namespace std;

/*

1. Stack and Queue
(https://aonecode.com/Interview-Question/Tiktok-OA/Stack-and-Queue)



void oper1(vector<int> &stck, vector<int> &que){

    int n = stck.size();
    for(int i = n -1; i>= 0; i--){
        que.push_back(stck[i]);
    }

    stck.clear();
}

void oper2(vector<int> & stck, int index, vector<int> & arr){
    stck.push_back(arr[index]);
}

void oper3(vector<int> &stck, vector<int> &que){
    int n = que.size();
    for(int i = 0; i < n; i++){
        stck.push_back(que[i]);
    }
    que.clear();
}

*/

int main(){

    /*
    // Question 1. Stack and Queue
    // vector<int> arr = {3, 4, 2, 6, 5};
    vector<int> arr ;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    // arr.push_back(5);
    vector<int> stck;
    vector<int> que;
    for(int i = 0; i < 4; i++){
        // stck elements
        if(stck.size() != 0){
            oper1(stck, que);
        }
        oper2(stck, i, arr);
        if(que.size() != 0){
            oper3(stck, que);
        }
    }

    cout << " Answer is " << " ";
    int n = stck.size();
    for(int i = n-1; i>= 0; i--){
        cout << stck[i] << " ";
    }
    cout << endl;
    */

    // return 0;
}