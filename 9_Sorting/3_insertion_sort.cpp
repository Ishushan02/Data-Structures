#include <iostream>

using namespace std;

/*
    Why Insertion Sort because it is more Adaptable because as time or iteration passses the loop get's on sorted.
    We can use this in small size arrays
*/
int main()
{
    int arr[9] = {9, 5, 4, 6, 1, 3, 11, 7, 8};

    int n = 9;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++){
            int j = i - 1;
            int temp = nums[i];
            for( ;j >= 0; j--){
                if(nums[j] > temp){
                    nums[j+1] = nums[j];
                }else{
                    break;
                }
            }
            nums[j+1] = temp;
        }

        return nums;
    }

*/