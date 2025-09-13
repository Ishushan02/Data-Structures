/*
    503. Next Greater Element II
    (https://leetcode.com/problems/next-greater-element-ii/)

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i < n; i++){
            int j = i + 1;
            int loop = n;
            bool temp = false;
            while(loop){
                int idx = j % n;
                if(nums[idx] > nums[i]){
                    temp = true;
                    ans.push_back(nums[idx]);
                    break;
                }
                j += 1;
                loop -= 1;
            }
            if(temp == false){
                ans.push_back(-1);
            }
        }

        return ans;
    }
        
*/

/*

    Very VERY Good Question
    907. Sum of Subarray Minimums (TLE)
    (https://leetcode.com/problems/sum-of-subarray-minimums/)

    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int minVal = arr[i];
            for(int j = i; j < n; j++){
                minVal = min(minVal, arr[j]);
                ans += minVal;
            }
            ans = ans % 1000000007;
        }

        return ans % 1000000007;
    }

    Efficient Method (Stacks)
    Procedure is, get the counts of each numbers in array that will contribute to the min sum of all Subarrays
    Ex: 
    [3, 1, 2, 4]

    SUbArr : 
    [3], [3, 1], [3, 1, 2], [3, 1, 2, 4]
    min are:  3.    1.       1.           1

    [1], [1, 2], [1, 2, 4]
    1.     1.       1.    

    [2], [2, 4]
    2.     2.   

    [4]
    4.  

    3 counts -> 1; 
    1 counts -> 6;
    2 counts -> 2;
    4 counts -> 1;

    total Sum = 3 * 1 + 2 * 6 + 2 * 2 + 4 * 1 = 17

    hence we can get the range of each possible number by getting its min on left and right and get it's count

    make sure you include the (equal to)== num either in left small calculation or right small calculation not both
    because that will result in duplicates.. 


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> leftSmallestRange(n, -1);
        vector<int> rightSmallestRange(n, n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(!st.empty()) leftSmallestRange[i] = st.top();
            st.push(i);
        }

        stack<int> st2;
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop();
            }

            if(!st2.empty()) rightSmallestRange[i] = st2.top();
            st2.push(i);
        }

        // for(auto v: leftSmallestRange){
        //     cout << v << " ";
        // }cout<<endl;

        // for(auto v: rightSmallestRange){
        //     cout << v << " ";
        // }

        int ans = 0;
        for(int i = 0; i < n; i++){
            long long int leftRange = i - leftSmallestRange[i];
            long long int rightRange = rightSmallestRange[i] - i;
            long long int num = (arr[i] * leftRange * rightRange) % mod;
            ans += num;
            ans = ans % mod;
        }

        return ans;
    }

*/