#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
All TikTok Questions
    - https://aonecode.com/tiktok-online-assessment-questions
*/


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


/*

2. Video Buffering
(https://aonecode.com/Interview-Question/Tiktok-OA/Video-Buffering)



void printss(vector<int>& buffer, unordered_map<int, int> availablePackets, int t){
    cout << " At time T: " << t << endl;

    cout <<" BufferData "<< " ";
    for(int i = 0; i < buffer.size(); i++){
        cout << buffer[i] << " ";
    }

    cout << endl;

    cout <<" Available Packets Data "<< " ";
    for(auto val:availablePackets){
        cout << val.first << " ";
    }

    cout << endl;


}

int videoBuffering(vector<int>& packets, int arrivalRate){
    int ans = -1;
    vector<int> buffer;
    unordered_map<int, int> availablePackets;

    int t = 1;
    int i = 0;

    while(i < packets.size()){
        int j = i;
        int limit = j + arrivalRate;
        i = j + arrivalRate;

        cout <<" Initially BufferData "<< " ";
        for(int i = 0; i < buffer.size(); i++){
            cout << buffer[i] << " ";
        }
        cout << endl;
        if(buffer.size() == 0 && t != 1){
            ans = t;
            return ans;
        }
        while(j < limit){
            if(availablePackets.find(packets[j]) == availablePackets.end()){
                buffer.push_back(packets[j]);
                availablePackets[packets[j]]++;
            }
            j++;
        }


        if(buffer.size() == 0){
            ans = t;
            return ans;
        }else{
            buffer.erase(buffer.begin());
        }

        // printss(buffer, availablePackets, t);
        
        t++;
    }

    return ans;
}
*/

/*

3. Multi Dimensional Selection - Remaining
(https://aonecode.com/Interview-Question/Tiktok-OA/Multi-Dimensional-Selection)

*/

/*

4. Paths on a Grid
(https://aonecode.com/Interview-Question/Tiktok-OA/Paths-on-a-Grid)

bool isSafe(int x, int y, vector<vector<int> >& grid){
    if(x >= grid.size() || y >= grid[0].size()){
        return false;
    }
    if(grid[x][y] == 1){
        return false;
    }
    return true;
}

void traverseGrid(int n, int m, int& res, int i, int j, vector<vector<int> >& grid){
    // cout <<" i:"<<i << " j:" << j << endl;
    if(i == n-1 && j == m-1){
        cout << " Res " << res << endl;
        res+= 1;
        return ;
    }

    if(isSafe(i+1, j, grid)){
        grid[i+1][j] = 1;
        traverseGrid(n, m, res, i+1, j, grid);
        grid[i+1][j] = 0;
    }
    if(isSafe(i, j+1, grid)){
        grid[i][j+1] = 1;
        traverseGrid(n, m, res, i, j+1, grid);
        grid[i][j+1] = 0;
    }

}
*/

/*

5. Authentication System
(https://aonecode.com/aplusplus/interviewctrl/getInterview/5000207481723372237)  

do it later
*/

/*

6. Ball Arrangement for Maximum Engagement
(https://aonecode.com/aplusplus/interviewctrl/getInterview/5000207481723371958)

- Very Important Question, Please do it.
*/

void arrange(vector<int>& arr){
    sort(arr.rbegin(), arr.rend());

    vector<int> tempArr;
    tempArr[0] = arr[0]; // setting up initial element
    int sum = 0;
    for(int i = 1; i <= arr.size()-1; i++){
        int tempelem = arr[i];
        int j = 0;

    }

}


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

   /*
   2. Video Buffering

   vector<int> packets ;
   packets.push_back(1);
   packets.push_back(3);
   packets.push_back(2);
   packets.push_back(1);
   packets.push_back(2);
   packets.push_back(3);
   packets.push_back(3);
   packets.push_back(4);
   int arrivalRate = 2;
   int ans = videoBuffering(packets, arrivalRate);
   cout<< " Ans is " << ans << endl;

   */

  /*
  4. Paths on a Grid

  int res = 0;
  int n = 5;
  int m = 2;
  vector<vector<int> > grid(n+1, vector<int>(m+1, 0));
  for(int a = 0; a<grid.size(); a++){
    for(int b = 0; b<grid[0].size(); b++){
        cout<< grid[a][b] << " ";
    }
    cout << endl;
  }
  traverseGrid(n+1, m+1, res, 0, 0, grid);
  cout << " Total ways of traversing " << n << " and " << m <<" is "<< res<< endl;

 */

    return 0;
}