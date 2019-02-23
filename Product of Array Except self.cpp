/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

/*
method:
使用两遍遍历,第一次遍历从左到右使用left记录第i个位置左边所有值的成绩,在用output数组记录当时的left
第二次遍历从右到左,记录j位置右边所有值的成积,并用output[i]*right作为结果保存.
算法复杂度O(n)
空间复杂度O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int left=1;
        int right=1;
        int len=nums.size();
        for(int i=0;i<len;i++){
            output.push_back(left);
            left*=nums[i];
        }
        for(int j=len-1;j>=0;j--){
            output[j]*=right;
            right*=nums[j];
        }
        return output;
    }
};