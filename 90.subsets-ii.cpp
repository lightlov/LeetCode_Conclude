/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.37%)
 * Total Accepted:    188.8K
 * Total Submissions: 455.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        
        

        subsetsWithDup(res,result,nums,0);
        return res;
    }


private:
    void subsetsWithDup(vector<vector<int>>& res,vector<int>& result,vector<int>& nums,int location){
        res.push_back(result);
        if(location==nums.size()) return;

        for(int i=location;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            result.push_back(nums[i]);
            int temp=nums[i];
            nums.erase(nums.begin()+i);
            subsetsWithDup(res,result,nums,i);
            result.pop_back();
            nums.insert(nums.begin()+i,temp);
        }


        
    }
};

