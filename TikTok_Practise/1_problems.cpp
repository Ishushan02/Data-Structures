#include <iostream>
#include <vector>
#include <map>

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

    return 0;
}