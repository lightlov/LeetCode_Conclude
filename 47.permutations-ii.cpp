/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.06%)
 * Total Accepted:    220K
 * Total Submissions: 563.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> result;
        permute(res,result,nums);
        
        return res;
    }
    
private:
    void permute(vector<vector<int>> &res, vector<int>& result,vector<int>& nums){
        //res存放最后答案,result存放当前答案,i表示从nums中取哪个数
        if(nums.size()==0){res.push_back(result);return ;}
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            result.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            permute(res,result,nums);
            result.pop_back();
            nums.insert(nums.begin()+i,num);
        }
    }
};


