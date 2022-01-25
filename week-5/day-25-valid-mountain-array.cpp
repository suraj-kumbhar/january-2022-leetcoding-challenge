// 941. Valid Mountain Array
// Easy

// 1767

// 131

// Add to List

// Share
// Given an array of integers arr, return true if and only if it is a valid mountain array.

// Recall that arr is a mountain array if and only if:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

// Example 1:

// Input: arr = [2,1]
// Output: false
// Example 2:

// Input: arr = [3,5,5]
// Output: false
// Example 3:

// Input: arr = [0,3,2,1]
// Output: true
 

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104

class Solution {
public:
    Solution() {
		ios_base::sync_with_stdio(false); cin.tie(NULL);
	}
    bool validMountainArray(vector<int>& array) {
        auto len = array.size();
        if(len<3||array[0]>array[1]){
            // cout<<"from 1st if condition";
            return false;
        }
        auto i=0;
        for(;i<len-1;i++){
            if(array[i]>=array[i+1])
            {
                break;
            }
        }
        if(array[i]==array[i+1]){
            // cout<<"from 2nd if condition";
            return false;
        }
        auto flag = false;
        for(;i<len-1;i++){
            flag=true;
            if(array[i]<=array[i+1]){
                break;
            }
        }
        // cout<<i;
        if(i+1==len&&flag){
            return true;
        }
        else{
            // cout<<"from 3rd if condition";
            return false;
        }
    }
};