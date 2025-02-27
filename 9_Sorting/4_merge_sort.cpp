/*
    912. Sort an Array
    (https://leetcode.com/problems/sort-an-array/)

    void merge(vector<int> &nums, int start, int mid, int end){

        int i = start;
        int iend = mid;
        int j = mid + 1;
        int jend = end;
        vector<int >arr;

        while(i <= iend && j <= jend){
            if(nums[i] < nums[j]){
                arr.push_back(nums[i]);
                i++;
            }else{
                arr.push_back(nums[j]);
                j++;
            }
        }

        while(i <= iend){
            arr.push_back(nums[i]);
            i++;
        }

        while(j <= jend){
            arr.push_back(nums[j]);
            j++;
        }

        for(int k = start; k <= end; k++){
            nums[k] = arr[k - start];
        }

    }

    void divideArr(vector<int> &nums, int start, int end){
        // cout << start << " " << end << endl;
        if(start >= end){
            return ;
        }

        int mid = (start + end)/2;

        divideArr(nums, start, mid);
        divideArr(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        divideArr(nums, 0, n-1);
        return nums;
    }
*/