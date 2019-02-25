/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.55%)
 * Total Accepted:    303.2K
 * Total Submissions: 651.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
 //       for(int i=0;i<candidates.size();i++){
        func(res,combination,candidates,target,0);
 //       }
        
        return res;
        
    }
    
    void func(vector<vector<int>>& res,vector<int> &combination, vector<int>& candidates, int target,int cnt){
        if(target==0){res.push_back(combination);return;}
//        combination.push_back(candidates[cnt]);
//        target=target-candidates[cnt];
        if(target<0) return;
        for(int i=cnt;i<candidates.size();i++){
            combination.push_back(candidates[i]);
            target=target-candidates[i];
            func(res,combination,candidates,target,i);
            target+=candidates[i];
            combination.pop_back();
        }
    }
    
};
